#include<iostream>
#include<vector>
#include<climits> // int_max
#include<map>
using namespace std;
/*La solución DP utiliza las soluciones anteriores para llegar a la solución óptima global*/
map<int, int> coinChangeDP(vector<int>& den, int p, int q) {
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
    if(result[change] == INT_MAX){
        return output;
    }
    // Encontar las denominaciones usadas para la solución final.
    int change_aux = 0;
    while(change > 0) {
        if(output.find(coin_used[change]) != output.end()){
            output[coin_used[change]]++;
        }else{
            output[coin_used[change]] = 1;
        }
        change -= coin_used[change];
        if(change == change_aux){
            cout << "no es posible dar cambio debido a las denominaciones" << endl;
            break;
        }
        change_aux = change;
    }
    return output;
}