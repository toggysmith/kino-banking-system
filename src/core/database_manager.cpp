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
          "name TEXT NOT NULL,"
          "password TEXT NOT NULL"
          ");");
}

void
DatabaseManager::run_sql(const char* sql)
{
  char* error_message = nullptr;

  int status_code =
    sqlite3_exec(database_handle, sql, nullptr, nullptr, &error_message);

  if (status_code != SQLITE_OK) {
    std::cerr << "SQL error: " << error_message << '\n';
    sqlite3_free(error_message);
  }
}

DatabaseManager* DatabaseManager::instance{ nullptr };

}