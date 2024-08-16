#include<iostream>
#include<vector>
using namespace std;

struct Coins{
    int num_coins = 0;
    vector<int> coins;
};

Coins coinChange(int value, int* den, int len){
    Coins out;
    int t = 1;
    while(value > 0){
        if(den[len] <= value){
            t = value/den[len];
            value = value-den[len]*t;
            for(int i = 0; i < t; i++){
                out.coins.push_back(den[len]);
            }
            out.num_coins++;
        }
        len--;
    }
    return out;
}

int main(){
    int den[] = {1, 2, 5 ,10, 20, 50, 100, 500, 1000};
    int len = sizeof(den)/sizeof(den[0]);
    Coins output = coinChange(43, den, len-1);
    cout <<"Number of coins: "<<output.num_coins << endl;
    cout <<"Denominations: "<< endl;
    for(auto i : output.coins){
        cout << i << endl;
    }
    return 0;
}