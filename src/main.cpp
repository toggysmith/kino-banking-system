// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include <GLFW/glfw3.h>
#include <gtest/gtest.h>
#include <imgui.h>
#include <sqlite3.h>

#include "core/window_manager.hpp"

static int
callback(void* NotUsed, int argc, char** argv, char** azColName)
{
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int
main()
{
  sqlite3* db;
  sqlite3_open("test.db", &db);

  /* Create SQL statement */
  char* sql = "CREATE TABLE COMPANY("
              "ID INT PRIMARY KEY     NOT NULL,"
              "NAME           TEXT    NOT NULL,"
              "AGE            INT     NOT NULL,"
              "ADDRESS        CHAR(50),"
              "SALARY         REAL );";

  /* Execute SQL statement */
  char* zErrMsg = 0;
  int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Table created successfully\n");
  }
  sqlite3_close(db);

  Core::WindowManager window_manager{};

  std::optional<GLFWwindow*> window_optional{ window_manager.get_window() };

  if (!window_optional) {
    return EXIT_FAILURE;
  }

  GLFWwindow* window = *window_optional;

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    window_manager.render([]() {
      bool is_open{ true };
      ImGui::Begin("Another Window", &is_open);
      ImGui::Text("Hello from another window!");
      ImGui::End();
    });
  }

  return EXIT_SUCCESS;
}