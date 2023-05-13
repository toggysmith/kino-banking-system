// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_WINDOW_MANAGER_HPP
#define KINO_WINDOW_MANAGER_HPP

#include <GLFW/glfw3.h>

#include <optional>

namespace Core {

class WindowManager
{
private:
  std::optional<GLFWwindow*> window_optional;

public:
  WindowManager();
  ~WindowManager();

  [[nodiscard]] std::optional<GLFWwindow*> get_window() const;
  void render(void(void)) const;
};

}

#endif