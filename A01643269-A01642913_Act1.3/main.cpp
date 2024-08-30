#include<iostream>
using namespace std;
#include<vector>
#include"BackTraking.hpp"

int main(){
    int m;
    int n;
    cin>>m;
    cin>>n;
    if(m == 1 && n == 1){
        cout << "No se require de una solución para le laberinto" << endl;
        return 0;
    }
    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>maze[i][j];
        }
    }

    int len_m = maze.size();
    int len_n = maze[0].size();
    vector<vector<int>> solution = backTraking(maze);
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << solution[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}