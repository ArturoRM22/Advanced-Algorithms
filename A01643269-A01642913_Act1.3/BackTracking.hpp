#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isValid(int row, int col, int numRows, int numCols){
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

vector<vector<int>> backTracking(vector<vector<int>> matrix){
    int len_m = matrix.size(); 
    int len_n = matrix[0].size();
    
    if (matrix[0][0] == 0 || matrix[len_m-1][len_n-1] == 0) {
        return {};
    }

    stack<pair<int, int>> path;
    vector<vector<int>> solution(len_m, vector<int>(len_n, 0));
    int m = 0;
    int n = 0;
    bool pathFound = false;
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Directions
    
    path.push({m, n});
    matrix[m][n] = 0; 
    
    while (!path.empty()) {
        m = path.top().first;
        n = path.top().second;
        
        if (m == len_m-1 && n == len_n-1) {
            pathFound = true;
            break;
        }
        
        bool moved = false;
        for (auto d : directions) {
            int new_m = m + d[0];
            int new_n = n + d[1];
            
            if (isValid(new_m, new_n, len_m, len_n) && matrix[new_m][new_n] == 1) {
                path.push({new_m, new_n});
                matrix[new_m][new_n] = 0; // Mark as visited
                moved = true;
                break;
            }
        }
    
        if (!moved) {
            path.pop();
        }
    }
    
    if (pathFound) {
        while (!path.empty()) {
            solution[path.top().first][path.top().second] = 1;
            path.pop();
        }
        return solution;
    }
    
    return {}; 
}
