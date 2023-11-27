#ifndef INVALID_MATCH_DAY_EXCEPTION_HPP
#define INVALID_MATCH_DAY_EXCEPTION_HPP

#include <stdexcept>

namespace finta {
class InvalidMatchDayException : public std::runtime_error {
   public:
    const unsigned short matchDay;

    InvalidMatchDayException(const unsigned short matchDay);

    virtual ~InvalidMatchDayException() = default;
};
}  // namespace finta
#endif  // INVALID_MATCH_DAY_EXCEPTION_HPP