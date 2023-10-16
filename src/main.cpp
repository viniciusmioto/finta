#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

int main() {
    try {
        boost::property_tree::ptree root;
        boost::property_tree::read_json("../data/Brasileirao2022.json", root);

        for (const auto& match : root.get_child("1")) {
            std::string homeTeam = match.second.get<std::string>("clubs.home");
            std::string awayTeam = match.second.get<std::string>("clubs.away");

            std::cout << "Home Team: " << homeTeam << std::endl;
            std::cout << "Away Team: " << awayTeam << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
