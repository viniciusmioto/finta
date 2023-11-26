#include "InvalidMatchIdException.hpp"

InvalidMatchIdException::InvalidMatchIdException(
    const unsigned short matchDay)
    : std::runtime_error(
          "Invalid match day. The range for Match Day ID is (1 - 380)"),
      matchDay(matchDay) {}