# <img src="cover.svg" width="100%" />

Kino is a mock banking system built in C++ using [GLFW](https://github.com/glfw/glfw), [Dear ImGui](https://github.com/ocornut/imgui),
and [SQLite](https://github.com/sqlite/sqlite). It's a personal learning project and may be useful if you have an interest in developing
GUIs with Dear ImGui, building software utilising SQLite as a database engine, or simply want to look at some modern C++ code.

# Features

1. **Basic CRUD abilities:** Kino follows the CRUD paradigm to create an effective and useful UI. Admins can create, view, modify, and
   delete manager accounts. They can also create new admin accounts. Managers can create, view, modify, and delete customer accounts.
   Customers can create, view, and delete bank accounts and also update their account details.
2. **Intuitive user interface:** Kino makes use of Dear ImGui to create a simple but delightful UI that is easy to navigate and work with.
3. **User interactions:** Customers can deposit and withdraw money from their accounts. They can also transfer money between different
   accounts.

# Getting Started

## Prerequisites

- [Git](https://git-scm.com/).
- A compiler that supports C++17 such as [Clang](https://clang.llvm.org/).
- [CMake](https://cmake.org/) 3.24 or above.

## Cloning

Clone this repository to your machine:

```bash
git clone https://github.com/toggysmith/kino-banking-system --recursive
```

The `--recursive` flag is needed because this project includes Dear ImGui as
a [Git submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules). If this flag is not set then only the top-level repository will be
cloned and submodules will not.

## Debug Build

Inside the newly created `kino-banking-system` directory, run these [CMake](https://cmake.org/) commands to build the project:

```bash
cmake -B build
cmake --build build
```

At this point, the Kino executable should have been built and will be located within the `build` directory. You can run it with

```bash
./build/kino
```

## Running Tests

Additionally, tests for the project can be run with:

```bash
./build/test_runner
```

## Release Build

Follow the same steps for the debug build but with the following change:

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

<a href="https://toggysmith.com">
  <picture>
    <source srcset="https://user-images.githubusercontent.com/61121030/234412163-6027c7f8-ffbe-4ebb-b83b-c8ce1941c5b4.png" media="(prefers-color-scheme: dark)" />
    <source srcset="https://user-images.githubusercontent.com/61121030/234409401-6c9037df-566d-4649-a5cc-12782ada38b5.png" media="(prefers-color-scheme: light)" />
    <img src="https://user-images.githubusercontent.com/61121030/234409401-6c9037df-566d-4649-a5cc-12782ada38b5.png" width="200" align="right" />
  </picture>
</a>
