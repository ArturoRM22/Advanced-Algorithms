#include<iostream>
#include<vector>
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
    cout << "Ahora ingrese el Precio a pagar: " << endl;
    cin >> p;
    cout << "Por último, ingrese el valor del billete o moneda con el que pagará: " << endl;
    cin >> q;

    cout << "Dynamic programming: " << endl;
    map<int, int> output = coinChangeDP(den, p, q);
    if (output.empty()) {
        cout << "No se requiere cambio, o no es posible dar cambio debido a las denominaciones" << endl;
    } else {
        cout << "Lista de denominaciones necesarias (Denominacion: cantidad): " << endl;
        for (auto it = output.rbegin(); it != output.rend(); ++it) { //Iterar el hash map de manera inversa
            cout<< it->first << ": " << it->second <<endl;
        }
    }
    cout << "Greedy: " << endl;
    
    return 0;
}