#include <iostream>
#include <vector>

#include "brute_force.h"
#include "dynamic_prog.h"
#include "greedy.h"
#include "input.h"
using namespace std;

int main() {
    int n;
    int capacity;
    int approach;
    vector<unsigned int> weigth;
    vector<unsigned int> profit;
    read_input(capacity, n, weigth, profit,approach);
    vector<bool> usedItems;
    if (approach==0) {
        exhaustive_approach(profit,weigth,n,capacity,usedItems);
    }
    else if (approach==1) {
        dynamic_approach(profit, weigth,n,capacity,usedItems);
    }
    else if (approach==2) {
        greedy_approach(profit, weigth, n,capacity,usedItems);
    }


    return 0;
}