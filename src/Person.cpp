#include "Person.hpp"

Person::Person(std::string name) : name{name} {}

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

bool Person::operator<(const Person& person) const {
    return this->name < person.name;
}