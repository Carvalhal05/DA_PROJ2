#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void greedy_approach(const vector<unsigned int>& values, const vector<unsigned int>& weights, unsigned int n, unsigned int maxWeight, vector<bool>& usedItems) {
    usedItems.assign(n,false);
    vector<pair<double,int>> P;

    for (unsigned int i = 0; i < n; i++) {
        double ratio = static_cast<double>(weights[i]) / values[i];
        P.push_back({ratio,i});
    }


    sort(P.begin(), P.end());


    unsigned int maxValue = 0;
    unsigned int totalWeight = 0;


    for (unsigned int i = 0; i < n; ++i) {
        unsigned int idx = P[i].second;
        if (totalWeight + weights[idx] <= maxWeight) {
            totalWeight += weights[idx];
            maxValue += values[idx];
            usedItems[idx] = true;
        }
    }

    for (int i =0; i<n ; i++) {
        if (usedItems[i]==1) {
            cout << i+1 << "," << weights[i] << "," << values[i] << endl;
        }
    }

    for (volatile int i = 0; i < 1e8; ++i);
}

#endif //GREEDY_H