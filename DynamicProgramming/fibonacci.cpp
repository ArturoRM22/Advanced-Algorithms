#include<iostream>
using namespace std;

void fibonacci(int* array, int n){
    array[0] = 0;
    array[1] = 1;
    for(int i = 2; i <= n; i++){
        array[i] = array[i-1] + array[i-2];
    }
}

int main(){
    int num;
    cout << "Fibonacci sequence"<< endl;
    cout << "Enter the number of elements:"<< endl;
    cin >>num;
    int seq[num];
    fibonacci(seq, num);
    for(int i = 0; i <= num;i++){
        cout << seq[i] << ", ";
    }
    return 0;
}