/* 
Complejidad:
Tiempo: O() no se
Espacio: O(2*m*n)
 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isValid(int row, int col, int numRows, int numCols){
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

vector<vector<int>> backTracking(vector<vector<int>> matrix){
    stack<pair<int, int>> path;
    int len_m = matrix.size(); 
    int len_n = matrix[0].size();
    vector<vector<int>> solution(len_m, (vector<int>(len_n, 0)));
    int m = 0;
    int n = 0;
    bool pathFound = false;
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Directions

    do{
        for(auto d : directions){
            int new_m = m + d[0];
            int new_n = n + d[1];
            if(isValid(new_m, new_n, len_m, len_n) && matrix[new_m][new_n] == 1 && (m != new_m || n != new_n)){
                matrix[m][n] = 0; // visitado
                path.push({m, n});
                m = new_m;
                n = new_n;
                pathFound = true;
                break;
            }
        }
        if(!pathFound && !path.empty()){
            matrix[m][n] = 0;
            m = path.top().first;
            n = path.top().second;
            path.pop();
        }

        pathFound = false;

        if(m == len_m-1 && n == len_n-1){
            pathFound = true;
            break; 
        }

    }while(!path.empty());

    while(!path.empty()){
        solution[path.top().first][path.top().second] = 1;
        path.pop();
    }

    if (pathFound){
        solution[len_m - 1][len_n - 1] = 1;
        return solution; 
    }
    return {};
}