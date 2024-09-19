/* 
Descripción: 
Implementación del algoritmos Backtracking y branch and bound para resolver el problema del laberinto. 
Backtracking: Va tomando cada posible camino y te devuelve el primero que encuentre. 
Branch and Bound: Gracias a la distancia heuristica (manhattan) entre las posiciones y el objectivo que se toma en cuenta para cada 
paso, se logra una optimización de la versión de backtracking, logrando econtrar la mejor solución más rápidamente.

Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 05/Sep/2024 */


#include<iostream>
using namespace std;
#include<vector>
#include"BackTracking.hpp"
#include"BranchAndBound.hpp"

int main(){
    int m, n;
    cin >> m >> n;
    if((m == 1 && n == 1) || (m == 1 && n == 2)){
        cout << "Solución no requerida para laberinto de 1x1 o 1x2." << endl;
        return 0;
    }

    vector<vector<int>> maze(m, vector<int>(n)); 
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }

    cout<< "Backtracking: " << endl;

    vector<vector<int>> solution = backTracking(maze);


    if (!solution.size()){
        cout << "No se encontró una solución" << endl;
    }else{
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << solution[i][j] << " "; 
            }
            cout << endl;
        }
    }

    cout<< "Branch and Bound: " << endl;

    vector<vector<int>> outputGrid(m, vector<int>(n));
    branchAndBound(0, 0, maze, outputGrid);
    if(outputGrid[0][0] == 0){
        cout << "No se encontró una solución" << endl;
        return 0;
    }
    for (int k=0; k<m; k++) {
        for (int l=0; l<n; l++) {
            cout << outputGrid[k][l] << " ";
        }
        cout << endl;
    }
    return 0;
}