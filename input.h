#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void read_input(int& capacity, int& n, vector<unsigned int>& weight, vector<unsigned int>& profit, int& approach) {
    cout << "Select the dataset: ";
    int dataset;
    cin >> dataset;
    cout <<"Select the approach (exaustive:0, dynamic:1): ";
    cin >> approach;
    string csv;
    string csv_1;
    if (dataset < 10) {
        csv = "TruckandPallets_0" + to_string(dataset) + ".csv";
        csv_1 = "Pallets_0" + to_string(dataset) + ".csv";

    }
    else {
        csv = "TruckandPallets_" + to_string(dataset) + ".csv";
        csv_1 = "Pallets_" + to_string(dataset) + ".csv";
    }
    ifstream file_t(csv);
    ifstream file_p(csv_1);
    string line;
    getline(file_t,line);
    getline(file_t,line);
    stringstream ss(line);
    string value;
    getline(ss, value, ',');
    capacity = stoi(value);
    getline(ss, value, ',');
    n = stoi(value);
    getline(file_p,line);


    for (int i = 0; i < n ; i++) {
        getline(file_p,line);
        stringstream ss_1(line);
        string value_1;
        getline(ss_1, value_1, ',');
        getline(ss_1, value_1, ',');
        weight.push_back(stoi(value_1));
        getline(ss_1, value_1, ',');
        profit.push_back(stoi(value_1));

    }

}

#endif //INPUT_H
