#include<iostream>
using namespace std;

int* coinRow(int* array, int size){
    int* results = new int[size];  // Dynamically allocate array
    results[0] = array[0];
    if(size > 1) {
        results[1] = max(array[0], array[1]);
    }
    
    for(int i = 2; i < size; i++){
        results[i] = max(results[i-1], results[i-2] + array[i]);
    }
    return results;
}

void printSelectedCoins(int* array, int* results, int size) {
    int i = size - 1;
    while(i >= 0) {
        if(i == 0 || (results[i] != results[i-1])) {
            cout << array[i] << " ";
            i -= 2;  // Skip the adjacent coin
        } else {
            i--;  // Move to the next coin
        }
    }
}

int main(){
    cout << "Coin-Row problem" << endl;
    int array[] = {5, 1, 2, 10, 6, 2};
    int len = sizeof(array) / sizeof(array[0]);
    int* results = coinRow(array, len);
    cout << "Maximum amount of money: " << results[len-1] << endl;
    cout << "Coins: ";
    printSelectedCoins(array, results, len);
    cout << endl;

    delete[] results;  // Free the dynamically allocated memory
    return 0;
}
