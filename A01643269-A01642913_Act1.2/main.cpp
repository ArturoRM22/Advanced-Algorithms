/* 
Descripción: 
Implementación de algoritmos ávaros y de programación dinámica para resolver el problema del cambio de monedas
Complejidades:
Solución DP: tiempo O(n*m), espacio O(n)
Solución Greedy: tiempo O(m), espacio O(1)
Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 21/Ago/2024
*/

/*SOLUCIÓN ALTERNA PARA COIN CHANGE DP (cada uno hizo su propia versión)
int coinChange(vector<int>& coins, int p, int q, vector<int>& selectedCoins) {
    if (p == q) return 0; 

    int n = q - p;
    vector<int> dp(n + 1, INT_MAX);
    vector<int> coinUsed(n + 1, -1); 
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                if (dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                    coinUsed[i] = j; 
                }
            }
        }
    }

    if (dp[n] == INT_MAX) return -1;

    int remainingAmount = n;
    while (remainingAmount > 0) {
        int coinIndex = coinUsed[remainingAmount];
        selectedCoins.push_back(coins[coinIndex]); 
        remainingAmount -= coins[coinIndex]; 
    }

    return dp[n];
}
*/

#include<iostream>
#include<vector>
#include <algorithm>
#include"coinChangeG.hpp"
#include"coinChangeDP.hpp"
using namespace std; 

int main() {
    int n;
    int p, q;
    cout << "Ingrese el número de denominaciones disponibles de las monedas: " << endl;
    cin >> n;
    vector<int> den(n); // Vector de denominaciones
    cout << "A continuación ingrese las denominaciones: "<< endl;
    for(int i = 0; i < n; i++) {
        cin >> den[i];
    }
    //Ordenar denominaciones (requerido solo para el algoritmo avaro)
    sort(den.begin(), den.end());
    cout << "Ahora ingrese el Precio a pagar: " << endl;
    cin >> p;
    cout << "Por último, ingrese el valor del billete o moneda con el que pagará: " << endl;
    cin >> q;

    cout << "Lista de denominaciones necesarias (Denominacion: cantidad): " << endl;
    cout << "Dynamic programming: " << endl;
    map<int, int> output_dp = coinChangeDP(den, p, q);
    if (output_dp.empty()) {
        cout << "No se requiere cambio, o no es posible dar cambio debido a las denominaciones" << endl;
    } else {
        for (auto it = output_dp.rbegin(); it != output_dp.rend(); ++it){ //Iterar el hash map de manera inversa
            cout<< it->first << ": " << it->second <<endl;
        }
    }

    cout << "Greedy: " << endl;
    vector<vector<int>> output_g = coinChangeG(den, p, q);
    int len_g = output_g.size();
    if (output_g.empty()) {
        cout << "No se requiere cambio, o no es posible dar cambio debido a las denominaciones" << endl;
    } else {
        for (int i = 0; i < len_g; i++) { //Iterar el hash map de manera inversa
            cout << output_g[i][0] <<": "<<output_g[i][1] << endl;
        }
    }
    return 0;
}