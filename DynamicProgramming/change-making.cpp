#include<iostream>
using namespace std;

//Input - n = amount
//Output - minimun number of coins to reach n

int changeMaking(int n, int* den, int den_size){
    int result[n+1];
    result[0] = 0;
    int minimum = 1000;
    for(int i = 1; i < n+1 ;i++){
        for(int j = 0; j < den_size-1 ;j++){
            if(den[j] <= i){
                minimum = min(minimum, result[i-den[j]]+1);
            }
        }
        //cout << "Minimum: " << minimum << endl;
        result[i] = minimum;
        minimum = 1000;
    }
    return result[n]; 
}

int main(){
    int change;
    cout << "Enter change"<< endl;
    cin>>change;
    int den[] = {1,3,4};
    int len = sizeof(den)/sizeof(den[0]);
    cout << "Denomination coins: [";
    for(int i = 0; i < len ;i++){
        cout << den[i] << " ";
    }
    cout <<"]" << endl;
    cout << "Minimum number of coins: " << changeMaking(change, den, len)<< endl;
    return 0;
}
