#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>


class Team {
    public:
        Team(std::string name);
        std::string getName();
        void setName(std::string name);

    private:
        std::string name;
};

#endif // TEAM_HPP