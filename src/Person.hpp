#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class Person {
   public:
    Person(std::string name);

    std::string getName() const;
    void setName(const std::string& name);

    bool operator<(const Person& person) const;

   private:
    std::string name;
};

#endif  // PERSON_HPP
