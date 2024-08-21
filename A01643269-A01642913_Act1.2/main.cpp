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