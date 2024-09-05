#include<iostream>
using namespace std;
#include<vector>
#include"BackTracking.hpp"
//#include"BranchAndBound.hpp"

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
        return 0;
    }

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << solution[i][j] << " "; 
        }
        cout << endl;
    }

    cout<< "Branch and Bound: " << endl;

    //vector<vector<int>> solutionn = branchAndBound(maze);
/* 
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << solutionn[i][j] << " "; 
        }
        cout << endl;
    } */

    return 0;
}