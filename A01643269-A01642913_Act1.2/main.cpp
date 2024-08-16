#include<iostream>
#include<vector>
using namespace std; 

vector<int> coinChange(vector<int>& den, int p, int q){
    vector<int> coins;
    int len = den.size()-1;
    int change = q - p;
    int t = 1; //Numero de veces que la denominación se puede usar para completar el cambio. 
    while(change > 0){
        if(den[len] <= change){
            t = change/den[len];
            change = change - den[len]*t;
            for(int i = 0; i < t; i++){
                coins.push_back(den[len]); 
            }
        }
        len--;
    }
    return coins;
}

int main(){
    int n;
    int p, q;
    cout << "Ingrese el número de denominaciones disponibles de las monedas: " << endl;
    cin>>n;
    vector<int> den(n); //Vector de denominaciones
    cout << "A continuación ingrese las denominaciones: "<< endl;
    for(int i = 0; i < n ;i++){
        cin>>den[i];
    }
    cout << "Ahora ingrese el Precio a pagar: " << endl;
    cin>>p;
    cout << "Por último, ingrese el valor del billete o moneda con el que pagará: " << endl;
    cin>>q;
    vector<int> output = coinChange(den, p, q);
    cout << "Lista de denominaciones necesarias: " << endl;
    for(int i : output){
        cout << i << endl;
    }
    return 0;
}