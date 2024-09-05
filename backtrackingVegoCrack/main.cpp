#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};

bool dfs(int y, int x, vector<vector<int>>& grid, vector<vector<int>>& outputGrid){
    grid[y][x] = 2;
    outputGrid[y][x] = 1;
    if (y == grid.size()-1 && x == grid[0].size()-1) return true;
    for (int i=0; i<4; i++) {
        if (y+dirY[i] >= 0 && y+dirY[i] < grid.size() && x+dirX[i] >= 0 && x+dirX[i] < grid[0].size()){
            if (grid[y+dirY[i]][x+dirX[i]] == 1){   
                if (dfs(y+dirY[i],x+dirX[i], grid, outputGrid)) return true;
            }
        }
    }
    outputGrid[y][x] = 0;
    return false;
}

int main () {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i=0;i<m;i++) {
        vector<int>row;
        for (int j=0;j<n;j++) {
            int val;
            cin >> val;
            grid[i][j] = val;
        }
    }
    vector<vector<int>> outputGrid(m, vector<int>(n));
    dfs(0, 0, grid, outputGrid);
    for (int k=0; k<m; k++) {
        for (int l=0; l<n; l++) {
            cout << outputGrid[k][l] << " ";
        }
        cout << endl;
    }
    return 0;
}