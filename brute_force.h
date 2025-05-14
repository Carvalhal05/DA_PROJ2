#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <iostream>
#include <vector>
using namespace std;


int count_items(vector<bool>& v) {
    int counter =0;
    for (int i=0 ; i<v.size() ; i++) {
        if (v[i]==1) counter++;
    }
    return counter;
}

void exhaustive_approach(const vector<unsigned int>& values,const vector<unsigned int>& weights, unsigned int n, unsigned int maxWeight, vector<bool>& usedItems) {
    vector<bool> curCandidate(n,false);
    usedItems.assign(n,false);

    unsigned int maxValue=0;
    unsigned int prevWeight = INT_MAX;
    while (true) {

        unsigned int totalValue = 0;
        unsigned int totalWeight = 0;
        for(unsigned int k = 0; k < n; k++) {
            if (curCandidate[k]) {
                totalValue += values[k];
                totalWeight += weights[k];
            }
        }
        if(totalWeight <= maxWeight) {
                if(totalValue >= maxValue || (totalValue == maxValue && totalWeight < prevWeight)) {
                    maxValue = totalValue;
                    prevWeight = totalWeight;
                    usedItems = curCandidate;

                }
        }

        unsigned int curIndex = 0;
        while(curIndex < n && curCandidate[curIndex]) {
            curCandidate[curIndex] = false;
            curIndex++;
        }
        if(curIndex == n) break;
        curCandidate[curIndex] = true;
    }


    for (int i =0; i<n ; i++) {
        if (usedItems[i]==1) {
            cout << i+1 << "," << weights[i] << "," << values[i] << endl;
        }
    }
}

#endif //BRUTE_FORCE_H
