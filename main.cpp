#include <iostream>
#include <vector>

#include "brute_force.h"
#include "dynamic_prog.h"
#include "greedy.h"
#include "input.h"
#include "ILP.h"
using namespace std;

int main() {

    int n;
    int capacity;
    int approach;
    vector<unsigned int> weigth;
    vector<unsigned int> profit;
    int dataset = read_input(capacity, n, weigth, profit,approach);
    vector<bool> usedItems;
    if (approach==0) {
        auto start1 = chrono::high_resolution_clock::now();
        exhaustive_approach(profit,weigth,n,capacity,usedItems);
        auto stop1 = chrono::high_resolution_clock::now();
        cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(stop1 - start1).count() << " ms" << endl;
    }
    else if (approach==1) {
        auto start2 = chrono::high_resolution_clock::now();
        dynamic_approach(profit, weigth,n,capacity,usedItems);
        auto stop2 = chrono::high_resolution_clock::now();
        cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(stop2 - start2).count() << " ms" << endl;
    }
    else if (approach==2) {
        auto start3 = chrono::high_resolution_clock::now();
        greedy_approach(profit, weigth, n,capacity,usedItems);
        auto stop3 = chrono::high_resolution_clock::now();
        cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(stop3 - start3).count() << " ms" << endl;
    } else if (approach==3) {
        read_knapsack_solver(dataset);
    }



    return 0;
}