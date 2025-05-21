#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


int count_items(vector<bool>& v) {
    int counter =0;
    for (int i=0 ; i<v.size() ; i++) {
        if (v[i]==1) counter++;
    }
    return counter;
}
/**
 *@brief Resolve uma versão do problema Knapsack com brute force
 *Com este método, o algoritmo testa todas as combinações possíveis de “Pallets”, verificando para cada uma a restrição de peso e o seu valor.
 *Depois de avaliar todas as combinações, escolhe a melhor opção
 *
 * @param values vetor com o avlor de cada "Pallet"
 * @param weights vetor com o peso de cada "Pallet"
 * @param n número de "Pallets"
 * @param maxWeight capacidade máxima do "Truck"
 * @param usedItems vetor que indica quais "Pallets" estão no "Truck"
 * @complexity O(2^n), onde n é o número de "Pallets"
 */
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

    for (volatile int i = 0; i < 1e8; ++i);

}

#endif //BRUTE_FORCE_H
