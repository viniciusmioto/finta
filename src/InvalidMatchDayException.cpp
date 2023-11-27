#include "InvalidMatchDayException.hpp"

using namespace finta;

InvalidMatchDayException::InvalidMatchDayException(
    const unsigned short matchDay)
    : std::runtime_error(
          "Invalid match day. The range for Match Day ID is (1 - 38)"),
      matchDay(matchDay) {}