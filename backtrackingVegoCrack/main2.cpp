#include<iostream>
#include<vector>
#include<utility>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};

int distance(int x, int y, int goalX, int goalY) {
    return abs(goalX - x) + abs(goalY - y);
}

bool dfs(int y, int x, vector<vector<int>>& grid, vector<vector<int>>& outputGrid){
    grid[y][x] = 2;
    outputGrid[y][x] = 1;
    if (y == grid.size()-1 && x == grid[0].size()-1) return true;
    vector<tuple<int, int, int>> directions;

    for (int i=0; i<4; i++) {
        int newY = y + dirY[i];
        int newX = x + dirX[i];
        if (newY >= 0 && newY < grid.size() && newX >= 0 && newX < grid[0].size() && grid[newY][newX] == 1) {
            int dist = distance(newX, newY, grid[0].size() - 1, grid.size() - 1);
            directions.push_back({dist, newY, newX});
        }
    }

    sort(directions.begin(), directions.end());

    // Explore the paths in order of increasing distance
    for (const auto& [dist, newY, newX] : directions) {
        if (dfs(newY, newX, grid, outputGrid)) return true;
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