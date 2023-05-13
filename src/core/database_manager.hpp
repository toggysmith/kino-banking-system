// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_CORE_DATABASE_MANAGER_HPP
#define KINO_CORE_DATABASE_MANAGER_HPP

#include <sqlite3.h>

namespace Core {

class DatabaseManager
{
public:
  static DatabaseManager* get_instance();
  void run_sql(const char*);

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