#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // Specify the path to your JSON file
    std::string jsonFilePath = "data.json"; // Replace with your JSON file path

    // Attempt to open the JSON file
    std::ifstream inputFile(jsonFilePath);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the JSON file." << std::endl;
        return 1;
    }

    // Parse the JSON data
    json jsonData;
    try {
        inputFile >> jsonData;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        inputFile.close();
        return 1;
    }

    // Close the input file
    inputFile.close();

    // Check if "TeamA" and "TeamB" exist in the JSON data
    if (jsonData.contains("TeamA") && jsonData.contains("TeamB")) {
        // Print the values of "TeamA" and "TeamB"
        std::cout << "TeamA: " << jsonData["TeamA"] << std::endl;
        std::cout << "TeamB: " << jsonData["TeamB"] << std::endl;
    } else {
        std::cerr << "JSON does not contain 'TeamA' and 'TeamB' keys." << std::endl;
    }

    return 0;
}
