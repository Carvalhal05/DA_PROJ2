#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void greedy_approach(const vector<unsigned int>& values, const vector<unsigned int>& weights, unsigned int n, unsigned int maxWeight, vector<bool>& usedItems) {
    usedItems.assign(n,false);
    vector<pair<double,int>> P(n);

    for (unsigned int i = 0; i < n; i++) {
        double ratio = static_cast<double>(values[i]) / weights[i];
        P.push_back({ratio,i});
    }

    for (auto p : P) {
        cout << p.first << endl;
        cout << p.second << endl;
    }

    sort(P.begin(), P.end());


    /*

    sort(P.begin(), P.end(), [&](unsigned int i, unsigned int j) {
        double ratio1 = static_cast<double>(values[i]) / weights[i];
        double ratio2 = static_cast<double>(values[j]) / weights[j];
        cout << ratio1 << ' ' << ratio2 << ' ' << bool(ratio1 < ratio2) <<endl;
        return ratio1 > ratio2;
    });


    */



    unsigned int maxValue = 0;
    unsigned int totalWeight = 0;


    for (unsigned int i = 0; i < n; ++i) {
        unsigned int idx = P[i].second;
        cout << weights[idx]<< endl;
        if (totalWeight + weights[idx] <= maxWeight) {
            totalWeight += weights[idx];
            maxValue += values[idx];
            usedItems[idx] = true;
            cout << totalWeight<< endl;
        }
    }

    for (int i =0; i<n ; i++) {
        if (usedItems[i]==1) {
            cout << i+1 << "," << weights[i] << "," << values[i] << endl;
        }
    }
}


#endif //GREEDY_H