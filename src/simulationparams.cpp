// SimulationParams.cpp
#include "simulationparams.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

simulation_params load_params(const char* filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        std::exit(1); // Exit if file cannot be opened
    }
    simulation_params params{};
    std::string key;
    double tempDouble;
    int tempInt;
    std::string tempString;
    std::string line;
    while (getline(input_file, line)) {
        std::istringstream iss(line);
        if (!(iss >> key)) {
            std::cerr << "Failed to read key on line: " << line << std::endl;
            continue;
        }
        if (key == "celltype") {
            if (!(iss >> tempDouble)) {
                std::cerr << "Invalid format for euler only" << std::endl;
                continue;
            }
            params.celltype = tempDouble;
        } else if (key == "bcl") {
            if (!(iss >> tempDouble)) {
                std::cerr << "Invalid format for bcl" << std::endl;
                continue;
            }
            params.bcl = tempDouble;
        } else if (key == "beats") {
            if (!(iss >> tempInt)) {
                std::cerr << "Invalid format for beats" << std::endl;
                continue;
            }
            params.beats = tempInt;
        } else if (key == "dtw") {
            if (!(iss >> tempDouble)) {
                std::cerr << "Invalid format for dtw" << std::endl;
                continue;
            }
            params.dtw = tempDouble;
        } else if (key == "time_point") {
            if (!(iss >> tempDouble)) {
                std::cerr << "Invalid format for time_point" << std::endl;
                continue;
            }
            params.time_point = tempDouble;
        } else if (key == "min_dt") {
            if (!(iss >> tempDouble)) {
                std::cerr << "Invalid format for min_dt" << std::endl;
                continue;
            }
            params.min_dt = tempDouble;
        } else if (key == "max_dt") {
            if (!(iss >> tempDouble)) {
                std::cerr << "Invalid format for max_dt" << std::endl;
                continue;
            }
            params.max_dt = tempDouble;
        } else if (key == "drug_name") {
            if (!(iss >> tempString)) {
                std::cerr << "Invalid format for drug_name" << std::endl;
                continue;
            }
            params.drug_name = tempString;
        } else if (key == "conc") {
            // First pass to determine the number of values
            std::string value;
            std::string values;
            int size = 0;
            if (getline(iss, values)) {
                std::istringstream valuesStream(values);
                while (std::getline(valuesStream, value, ',')) {
                    ++size;
                }
            }
            params.conc_size = size;
            // Allocate array based on the determined size
            params.conc = new double[size];
            // Second pass to actually store the values
            iss.clear();
            iss.seekg(0, std::ios::beg); // Reset stream position
            iss >> key; // Skip the "conc" part
            int index = 0;
            // std::cout << "size: " << size << std::endl;
            while (getline(iss, value, ',') && index < size) {
                params.conc[index] = stod(value);
                ++index;
                // std::cout << "value: " << value << std::endl;
            }
            // params.conc = tempDouble;
            // delete[] conc;
        } else if (key == "cai_scaling") {
            if (!(iss >> tempInt)) {
                std::cerr << "Invalid format for cai scaling" << std::endl;
                continue;
            }
            params.cai_scaling = tempInt;
        } else {
            std::cerr << "Unknown parameter: " << key << std::endl;
        }
    }

    input_file.close();
    return params;
}