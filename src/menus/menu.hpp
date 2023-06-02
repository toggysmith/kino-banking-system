// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_MENUS_MENU_HPP
#define KINO_MENUS_MENU_HPP

#include <deque>
#include <memory>
#include <optional>
#include <string>
#include <string_view>

#include "../core/database_manager.hpp"

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

  using TableActionButtons = std::vector<TableActionButton>;

  static void show_table(const Core::DatabaseManager::ColumnNames&,
                         const Core::DatabaseManager::TableData&,
                         const TableActionButtons&);
  static void show_table(const Core::DatabaseManager::ColumnNames&,
                         const Core::DatabaseManager::TableData&);
};

}

#endif