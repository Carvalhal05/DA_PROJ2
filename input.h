#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;




/**
 *@brief Imprime uma mensagem de erro
 *
 */

void print_error() {
    cout << "Error: Please insert a valid option." << endl;
}



/**
 *@brief Lê qual o dataset escolhido
 *
 */
int read_dataset() {
    int dataset;
    while (true)
    {
        cout <<"Dataset:";
        cin >> dataset;
        if (cin.fail()) {
            // Se a entrada não for um número inteiro válido
            cin.clear(); // limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
            print_error();
            continue;
        }

        if (dataset > 0 && dataset <= 10) {
            return dataset;
        }

        print_error();
    }
}


/**
 *@brief Lê com o algoritmo escolhido
 *
 */

int read_approach() {
    int approach;
    while (true)
    {
        cout <<"Select the approach (exaustive:0, dynamic:1, greedy:2, ILP:3):";
        cin >> approach;
        if (cin.fail()) {
            // Se a entrada não for um número inteiro válido
            cin.clear(); // limpa o erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
            print_error();
            continue;
        }

        if (approach >= 0 && approach <= 3) {
            return approach;
        }

        print_error();
    }
}



/**
 *@brief Lê o input dos ficheiros correspondentes ao dataset escolhido
 *Completa os vetores e as variáveis com os valores lidos.
 *
 *
 * @param capacity capacidade máxima do "Truck"
 * @param n número de "Pallets"
 * @param weight vetor com o peso de cada "Pallet"
 * @param profit vetor com o valor de cada "Pallet"
 * @param approach algoritmo para resolver o problema
 */
int read_input(int& capacity, int& n, vector<unsigned int>& weight, vector<unsigned int>& profit, int& approach) {
    int dataset;
    dataset = read_dataset();

    approach = read_approach();
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

    return dataset;

}

#endif //INPUT_H
