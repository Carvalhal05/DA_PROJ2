#ifndef ILP_H
#define ILP_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int read_knapsack_solver(int dataset)
{
    string txt;
    if (dataset < 10) {
        txt = "input0" + to_string(dataset) + ".txt";

    }
    else {
        txt = "input" + to_string(dataset) + ".txt";
    }
    // Run Python script (must be .py)
    string command = "python knapsack_solver.py " + txt + " output.txt";
    int ret = system(command.c_str());
    if (ret != 0) {
        std::cerr << "Failed to run knapsack_solver.py" << std::endl;
        return 1;
    }

    // Open output.txt
    std::ifstream infile("output.txt");
    if (!infile.is_open()) {
        std::cerr << "Error opening output.txt" << std::endl;
        return 1;
    }

    int totalProfit, totalWeight, totalCapacity;
    std::string line;

    std::getline(infile, line);
    totalProfit = std::stoi(line);

    std::getline(infile, line);
    totalWeight = std::stoi(line);

    std::getline(infile, line);
    totalCapacity = std::stoi(line);

    std::getline(infile, line);
    std::istringstream iss(line);
    std::vector<int> selectedIndices;
    int index;
    while (iss >> index) {
        selectedIndices.push_back(index);
    }

    infile.close();

    // Print results
    std::cout << "=== Knapsack Results (Python ILP) ===" << std::endl;
    std::cout << "Total Profit: " << totalProfit << std::endl;
    std::cout << "Total Weight: " << totalWeight << std::endl;

    std::cout << std::endl;
}

#endif //ILP_H
