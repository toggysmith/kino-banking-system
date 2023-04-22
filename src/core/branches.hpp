#ifndef KINO_BRANCHES_HPP
#define KINO_BRANCHES_HPP

#include <string>
#include <unordered_map>

namespace Core {

static std::unordered_map<int64_t, const std::string> branches = {
  { 1, "Leicester" }, { 2, "New York" }, { 3, "Chicago" },
  { 4, "Cape Town" }, { 5, "London" },   { 6, "Edinburgh" },
};

}

#endif