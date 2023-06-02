// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENUS_MENU_HPP
#define KINO_MENUS_MENU_HPP

#include <deque>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

namespace Menus {

class Menu
{
public:
  explicit Menu(std::string_view name);
  virtual ~Menu() = default;

  virtual void render(std::deque<std::unique_ptr<Menu>>&) const;

  const std::string name;

protected:
  struct TableActionButton;

  typedef std::optional<std::string> table_value_t;
  typedef std::vector<table_value_t> table_row_t;
  typedef std::vector<table_row_t> table_data_t;
  typedef std::vector<std::string> table_column_names_t;
  typedef std::vector<TableActionButton> table_action_buttons_t;

  static void show_table(const table_column_names_t&,
                         const table_data_t&,
                         const table_action_buttons_t&);
  static void show_table(const table_column_names_t&, const table_data_t&);
};

}

#endif