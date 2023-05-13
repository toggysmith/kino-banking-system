// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#ifndef KINO_CORE_WINDOW_MANAGER_HPP
#define KINO_CORE_WINDOW_MANAGER_HPP

#include <GLFW/glfw3.h>

#include <optional>

namespace Core {

class WindowManager
{
public:
  WindowManager();
  ~WindowManager();

  [[nodiscard]] std::optional<GLFWwindow*> get_window() const;
  void start_frame() const;
  void finish_frame() const;

private:
  std::optional<GLFWwindow*> window_optional;
};

}

#endif