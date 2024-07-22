// drug_data.cpp
#include "drug_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

hill_data load_hill(const char* filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        std::exit(1); // Exit if file cannot be opened
    }
    hill_data data{};
    std::string line, cell;
    std::getline(input_file, line);
    if (std::getline(input_file, line)) {
        std::istringstream lineStream(line);
        int index = 0;
        while (getline(lineStream, cell, ',') && index < 14) {
            try {
                data.hill[index++] = std::stod(cell);
            } catch (std::invalid_argument&) {
                data.hill[index++] = 0.0; // Treat invalid data as 0
            }
        }
    }
    input_file.close();
    return data;
}

herg_data load_herg(const char* filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        std::exit(1); // Exit if file cannot be opened
    }
    herg_data data{};
    std::string line, cell;
    std::getline(input_file, line);
    if (std::getline(input_file, line)) {
        std::istringstream lineStream(line);
        int index = 0;
        while (getline(lineStream, cell, ',') && index < 6) {
            try {
                data.herg[index++] = std::stod(cell);
            } catch (std::invalid_argument&) {
                data.herg[index++] = 0.0; // Treat invalid data as 0
            }
        }
    }
    input_file.close();
    return data;
}