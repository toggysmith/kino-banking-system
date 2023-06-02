// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "database_manager.hpp"

#include <filesystem>
#include <iostream>

namespace Core {

DatabaseManager*
DatabaseManager::get_instance()
{
  if (instance == nullptr) {
    instance = new DatabaseManager();
  }

  return instance;
}

DatabaseManager::DatabaseManager()
  : database_handle(nullptr)
{
  // Check if the database exists
  bool does_database_exist{ std::filesystem::exists({ "main.db" }) };

  if (!does_database_exist) {
    // Create (and open) the database
    create_database();
  } else {
    // Open the database
    sqlite3_open("main.db", &database_handle);
  }
}

DatabaseManager::~DatabaseManager()
{
  sqlite3_close(database_handle);
}

void
DatabaseManager::create_database()
{
  // Open the database
  sqlite3_open("main.db", &database_handle);

  // Create the tables
  run_sql("CREATE TABLE manager("
          "Name TEXT NOT NULL,"
          "Password TEXT NOT NULL"
          ");");
}

std::optional<DatabaseManager::Table>
DatabaseManager::run_sql(const char* sql)
{
  char* error_message = nullptr;

  struct CallbackData
  {
    ColumnNames column_names;
    TableData table_data;
  } callback_data;

  const auto sqlite_callback = [](void* c_style_callback_data,
                                  int number_of_columns,
                                  char** c_style_column_values,
                                  char** c_style_column_names) {
    // Convert from C-style data to C++-style data
    auto* callback_data = (CallbackData*)c_style_callback_data;

    RowValues row_values;

    for (int i = 0; i < number_of_columns; i++) {
      char* c_style_column_value = c_style_column_values[i];

      if (c_style_column_value == nullptr) {
        row_values.emplace_back(std::nullopt);
      } else {
        row_values.emplace_back(c_style_column_value);
      }
    }

    callback_data->table_data.emplace_back(row_values);

    if (callback_data->column_names.empty()) {
      for (int i = 0; i < number_of_columns; i++) {
        callback_data->column_names.emplace_back(c_style_column_names[i]);
      }
    }

    // Return zero to signal this callback was successful
    return 0;
  };

  int status_code = sqlite3_exec(
    database_handle, sql, sqlite_callback, &callback_data, &error_message);

  if (status_code != SQLITE_OK) {
    std::cerr << "SQL error: " << error_message << '\n';
    sqlite3_free(error_message);
  }

  // Return data if it exists
  const auto [column_names, table_data] = callback_data;

  if (table_data.empty()) {
    return std::nullopt;
  } else {
    return std::make_pair(column_names, table_data);
  }
}

DatabaseManager* DatabaseManager::instance{ nullptr };

}