/* 
Descripción: 
Implementación del algoritmo de ordenamiento "Merge sort" el cual hace uso de la técnica "divide and conquer"
y tiene una complejidad en el peor caso de O(n log n) en tiempo,
y de O(n) en espacio, siendo n la cantidad de números o entradas. 
Ambos algoritmos presentados, tanto el de ramificación y poda como el de retroceso (backtracking),tienen una complejidad de tiempo y espacio de O(n*m), donde n y m son las dimensiones de la matriz de entrada. Esto se debe a que, en el peor de los casos, ambos algoritmos podrían necesitar explorar cada celda de la matriz una vez. Aunque utilizan diferentes técnicas de optimización (ordenación de caminos en el primero, y una pila para el backtracking en el segundo), estas no afectan la complejidad del peor caso. El espacio adicional utilizado por ambos algoritmos también es proporcional al tamaño de la matriz de entrada, ya sea por la recursión o por la pila utilizada para almacenar el camino.
Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 14/Ago/2024

*/
#include<iostream>
using namespace std;

// Función que combina dos mitades ordenadas en un solo arreglo ordenado.
// Complejidad en tiempo: O(n), donde n es el número total de elementos a combinar.
// Complejidad en espacio: O(n) debido a los arreglos temporales usados para almacenar las mitades.
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

// Función que implementa el algoritmo Merge Sort usando recursión para dividir el arreglo y luego ordenarlo.
//divide el arreglo en mitades hasta llegar al caso base indivisible y comienza a ordenar
// Complejidad en tiempo: O(n log n) en todos los casos (mejor, promedio y peor caso).
// Complejidad en espacio: O(n) debido al uso de memoria adicional para dividir y combinar las partes.
void mergeSort(double* array, int left, int right){
    int mid;
    if (left < right){
        mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, mid, left, right);
    }
}

int main(){
    int n;
    cin>>n; //Asignar el número de elementos
    double array[n];

    for (int i = 0; i < n; ++i) {
        cin >> array[i]; //Asignar cada elemento del .txt al array
    }

    mergeSort(array, 0, n - 1);
    cout <<"[";
    for(int i = 0; i < n; i++){
        cout<<array[i]<<" ";
    }
    cout <<"]";
    return 0;
}