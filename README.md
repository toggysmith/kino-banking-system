<h1 align="center">Kino Banking System</h1>
<p align="center">A mock banking system developed in C++17.</p>

# Overview

Kino banking system is a software application developed in C++ that simulates the basic functionality of a banking system. It allows users
to perform tasks such as managing accounts, depositing and withdrawing funds, transferring between accounts, and much more.

# Run locally

Install [CMake](https://cmake.org/). You will need a version >= 3.24.

Clone the repository:

```bash
git clone https://github.com/toggysmith/kino
```

Go to the project directory:

```bash
cd kino
```

Use CMake to build the project:

```bash
cmake -S . -B build
cmake --build build
```

Run the Kino executable:

```bash
cd build
./kino
```

# Features

- Accounts, consisting of an account and branch number, a name, and a balance in a specific currency.