/* 
Descripción: 
Implementación del algoritmo de ordenamiento "Merge sort" el cual hace uso de la técnica "divide and conquer"
y tiene una complejidad en el peor caso de O(n log n) en tiempo,
y de O(n) en espacio, siendo n la cantidad de números o entradas. 
Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha:

*/
#include<iostream>
using namespace std;

void merge(double* array, int mid, int left, int right){
    int lenL = mid - left +1; 
    int lenR = right - mid;
    double tempL[lenL];
    double tempR[lenR];

    for(int i = 0; i < lenL; i++){
        tempL[i] = array[left + i];
    }

    for(int j = 0; j < lenR; j++){
        tempR[j] = array[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < lenL && j < lenR){
        if(tempL[i] <= tempR[j]){
            array[k] = tempL[i];
            i++;
        }else{
            array[k] = tempR[j];
            j++;
        }
        k++;
    }

    while(i < lenL){
        array[k] = tempL[i];
        i++;
        k++;
    }

    while(j < lenR){
        array[k] = tempR[j];
        j++;
        k++;
    }
}

void mergeSort(double* array, int left, int right){
    int mid;
    if (left < right){
        mid = (left + right)/2;
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, mid, left, right);
    }
}

int main(){
    double array[] = {2.5, 1.1, 3.6, 2.1, 4.4};
    int len = sizeof(array)/sizeof(array[0]);
    mergeSort(array, 0, len - 1);
    cout <<"[";
    for(int i = 0; i < len; i++){
        cout<<array[i]<<", ";
    }
    cout <<"]";
    return 0;
}