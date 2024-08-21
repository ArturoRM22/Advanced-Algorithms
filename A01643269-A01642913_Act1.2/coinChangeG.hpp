#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> coinChangeG(vector<int>& den, int p, int q){ //Greedy
    vector<vector<int>> coins;
    int len = den.size()-1;
    int change = q - p;
    if(change <= 0){
        return coins;
    }
    int t = 1; //Numero de veces que la denominación se puede usar para completar el cambio. 
    while(change > 0){
        if(den[len] <= change){
            t = change/den[len];
            change = change - den[len]*t;
            coins.push_back({den[len], t}); 
        }
        len--;
    }
    return coins;
}