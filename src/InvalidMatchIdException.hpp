#ifndef INVALID_MATCH_ID_EXCEPTION_HPP
#define INVALID_MATCH_ID_EXCEPTION_HPP

#include <stdexcept>

namespace finta {
class InvalidMatchIdException : public std::runtime_error {
   public:
    const unsigned short matchDay;

    InvalidMatchIdException(const unsigned short matchDay);

    virtual ~InvalidMatchIdException() = default;
};
}  // namespace finta
#endif  // INVALID_MATCH_ID_EXCEPTION_HPP