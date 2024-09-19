/* 
Complejidades:
Tiempo:
O(n*m)
Espacio:
O(n*m)
 */
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

bool branchAndBound(int y, int x, vector<vector<int>>& grid, vector<vector<int>>& outputGrid){
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
        if (branchAndBound(newY, newX, grid, outputGrid)) return true;
    }
    outputGrid[y][x] = 0;
    return false;
}