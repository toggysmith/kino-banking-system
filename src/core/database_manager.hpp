// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_CORE_DATABASE_MANAGER_HPP
#define KINO_CORE_DATABASE_MANAGER_HPP

#include <sqlite3.h>

#include <optional>
#include <string>
#include <vector>

namespace Core {

class DatabaseManager
{
public:
  using ColumnNames = std::vector<std::string>;
  using CellValue = std::optional<std::string>;
  using RowValues = std::vector<CellValue>;
  using TableData = std::vector<RowValues>;
  using Table = std::pair<ColumnNames, TableData>;

  static DatabaseManager* get_instance();
  std::optional<Table> run_sql(const char*);

  DatabaseManager(DatabaseManager&) = delete;
  void operator=(const DatabaseManager&) = delete;

private:
  void create_database();

  sqlite3* database_handle;

protected:
  DatabaseManager();
  ~DatabaseManager();

  static DatabaseManager* instance;
};

}

#endif