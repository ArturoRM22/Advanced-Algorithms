#include<iostream>
using namespace std;
#include<vector>
#include<stack>

bool isValid(int row, int col, int numRows, int numCols){
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

vector<vector<int>> backTraking(vector<vector<int>>& matrix){
    stack<vector<int>> path;
    int len_m = matrix.size();
    int len_n = matrix[0].size(); 
    int m = 0;
    int n = 0;
    bool pathFound = false;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions
    vector<vector<int>> validPos;
    do{
        for(auto d : directions){
            int new_m = m + d[0];
            int new_n = n + d[1];
            if(isValid(new_m, new_n, len_m, len_n) && matrix[new_m][new_n] == 1 && (new_m != m || new_n != n)){
                matrix[m][n] = 0;
                path.push({m, n});
                m = new_m;
                n = new_n;
                pathFound = true;
                break;
            }
        }
        if(!pathFound){
            matrix[m][n] = 0;
            m = path.top()[0];
            n = path.top()[1];
            path.pop();
        }

        pathFound = false;
        validPos = {};

        if(m == len_m-1 && n == len_n-1){
            break; 
        }
        
    }while(!path.empty());

    while(!path.empty()){
        matrix[path.top()[0]][path.top()[1]] = 1;
        path.pop();
    }
    return matrix; 
}