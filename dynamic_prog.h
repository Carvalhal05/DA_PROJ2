#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;



/**
 *@brief Resolve uma versão do problema Knapsack com programação dinâmica
 *
 *Com programação dinâmica, o algoritmo guarda numa tabela as soluções parciais ótimas de etapas anteriores, para calcular soluções ótimas de etapas posteriores.
 *Primeiro,completamos os casos base da tabela e depois, para cada “Pallet”, verificamos se é melhor colocá-la ou não no “Truck.

 * @param values vetor com o avlor de cada "Pallet"
 * @param weights vetor com o peso de cada "Pallet"
 * @param n número de "Pallets"
 * @param maxWeight capacidade máxima do "Truck"
 * @param usedItems vetor que indica quais "Pallets" estão no "Truck"
 */
void dynamic_approach(const vector<unsigned int>& values, const vector<unsigned int>& weights, unsigned int n, unsigned int maxWeight, vector<bool>& usedItems) {
    usedItems.assign(n,false);
    vector<vector<unsigned int>> maxValue(n, vector<unsigned int>(maxWeight + 1, 0));
    vector<vector<unsigned int>> minWeight(n, vector<unsigned int>(maxWeight + 1, 0));

    for(unsigned int k = 0; k <= maxWeight; k++) {
        maxValue[0][k] = (k >= weights[0]) ? values[0] : 0;
        minWeight[0][k] = (k >= weights[0]) ? weights[0] : 0;
    }


    for(unsigned int i = 1; i < n; i++) {
        maxValue[i][0] = 0;
        minWeight[i][0] = 0;
    }


    for(unsigned int i = 1; i < n; i++) {
        for(unsigned int k = 1; k <= maxWeight; k++) {
            if(k < weights[i]) {
                maxValue[i][k] = maxValue[i - 1][k];
                minWeight[i][k] = minWeight[i - 1][k];
            }
            else {
                unsigned int valueUsingItemI = maxValue[i - 1][k - weights[i]] + values[i];
                if(valueUsingItemI > maxValue[i - 1][k]) {
                    maxValue[i][k] = valueUsingItemI;
                    minWeight[i][k] = minWeight[i - 1][k - weights[i]] + weights[i];
                }
                else if (valueUsingItemI < maxValue[i - 1][k]){
                    maxValue[i][k] = maxValue[i - 1][k];
                    minWeight[i][k] = minWeight[i - 1][k];
                }else {
                    unsigned int weightWith = minWeight[i - 1][k - weights[i]] + weights[i];
                    unsigned int weightWithout = minWeight[i - 1][k];

                    if (weightWith < weightWithout) {
                        maxValue[i][k] = valueUsingItemI;
                        minWeight[i][k] = weightWith;
                    } else {
                        maxValue[i][k] = maxValue[i - 1][k];
                        minWeight[i][k] = weightWithout;
                    }
                }
            }
        }
    }


    for(unsigned int i = 0; i < n; i++) {
        usedItems[i] = false;
    }
    unsigned int k = maxWeight;
    for (int i = n - 1; i >= 1; --i) {
        if (k >= weights[i] && maxValue[i][k] == maxValue[i - 1][k - weights[i]] + values[i]) {
            usedItems[i] = true;
            k -= weights[i];
        }
    }

    if (k >= weights[0] && maxValue[0][k] == values[0]) {
        usedItems[0] = true;
    }


    for (int i =0; i<n ; i++) {
        if (usedItems[i]==1) {
            cout << i+1 << "," << weights[i] << "," << values[i] << endl;
        }
    }

    for (volatile int i = 0; i < 1e8; ++i);
}

#endif //DYNAMIC_PROG_H