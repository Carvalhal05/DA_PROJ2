#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#endif //DYNAMIC_PROG_H

#include <iostream>
#include <vector>
using namespace std;

void dynamic_approach(const vector<unsigned int>& values, const vector<unsigned int>& weights, unsigned int n, unsigned int maxWeight, vector<bool>& usedItems) {
    usedItems.assign(n,false);
    vector<vector<unsigned int>> maxValue(n, vector<unsigned int>(maxWeight + 1, 0));
    for(unsigned int k = 0; k <= maxWeight; k++) {
        maxValue[0][k] = (k >= weights[0]) ? values[0] : 0;
    }
    for(unsigned int i = 1; i < n; i++) {
        maxValue[i][0] = 0;
    }


    for(unsigned int i = 1; i < n; i++) {
        for(unsigned int k = 1; k <= maxWeight; k++) {
            if(k < weights[i]) {
                maxValue[i][k] = maxValue[i - 1][k];
            }
            else {
                unsigned int valueUsingItemI = maxValue[i - 1][k - weights[i]] + values[i];
                if(valueUsingItemI > maxValue[i - 1][k]) {
                    maxValue[i][k] = valueUsingItemI;
                }
                else {
                    maxValue[i][k] = maxValue[i - 1][k];
                }
            }
        }
    }


    for(unsigned int i = 0; i < n; i++) {
        usedItems[i] = false;
    }
    unsigned int remainingWeight = maxWeight;
    unsigned int curItem = n - 1;
    for(unsigned int i = n - 1; i > 0; i--) {

        if(remainingWeight == 0) break;


        if(maxValue[i][remainingWeight] != maxValue[i-1][remainingWeight]) {
            usedItems[i] = true;
            remainingWeight -= weights[i];
            curItem--;
        }
    }

    if(remainingWeight >= weights[0] && maxValue[0][remainingWeight] == values[0]) {
        usedItems[0] = true;
    }

    for (int i =0; i<n ; i++) {
        if (usedItems[i]==1) {
            cout << i+1 << "," << weights[i] << "," << values[i] << endl;
        }
    }

}
