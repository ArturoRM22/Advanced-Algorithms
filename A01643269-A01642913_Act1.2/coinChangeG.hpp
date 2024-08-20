#include<iostream>
#include<vector>
using namespace std;

vector<int> coinChangeG(vector<int>& den, int p, int q){ //Greedy
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