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