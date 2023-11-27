#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

namespace finta {
class Person {
   public:
    Person(std::string name);

    std::string getName() const;
    void setName(const std::string& name);

    bool operator==(const Person& otherPerson) const;
    bool operator==(const std::string& otherName) const;
    bool operator<(const Person& otherPerson) const;

   private:
    std::string name;
};
}
#endif  // PERSON_HPP
