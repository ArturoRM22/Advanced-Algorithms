#include<iostream>
#include<vector>
#include<climits> // int_max
#include<map>
using namespace std;

map<int, int> coinChange(vector<int>& den, int p, int q) {
    int change = q - p;
    map<int, int> output;
    if(change <= 0){
        return output;
    }
    int den_len = den.size();
    vector<int> result(change + 1, INT_MAX);
    vector<int> coin_used(change +1); //Denominaciones usadas en cada solución
    vector<int> coins;//Denominaciones usadas en la solución final 
    result[0] = 0; // Caso base
    for(int i = 1; i <= change; i++) {
        for(int j = 0; j < den_len; j++) {
            if(den[j] <= i) {
                if(result[i] > result[i - den[j]] + 1) {
                    result[i] = result[i - den[j]] + 1;
                    coin_used[i] = den[j]; // Guarda cada denominacion usada. 
                }
            }
        }
    }
    // Encontar las denominaciones usadas para la solución final.
    while(change > 0) {
        if(output.find(coin_used[change]) != output.end()){
            output[coin_used[change]]++;
        }else{
            output[coin_used[change]] = 1;
        }
        change -= coin_used[change];
    }
    return output;
}

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

    map<int, int> output = coinChange(den, p, q);
    if (output.empty()) {
        cout << "No se requiere cambio, o no es posible dar cambio debido a las denominaciones" << endl;
    } else {
        cout << "Lista de denominaciones necesarias (Denominacion: cantidad): " << endl;
        for (auto it = output.rbegin(); it != output.rend(); ++it) { //Iterar el hash map de manera inversa
            cout<< it->first << ": " << it->second <<endl;
        }
    }
    return 0;
}