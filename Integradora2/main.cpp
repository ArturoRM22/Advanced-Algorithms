#include<iostream>
#include<vector>
#include"TSP.hpp"
#include"Prims.hpp"
using namespace std; 

//TSP struct

int main() {
    int n; // number of cities
    cin >> n;
    vector<vector<int>> distances(n, vector<int>(n));
    
    // Read distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> distances[i][j];
        }
    }
    

    // Optionally get the path
    COST_AND_PATH result = TSP(distances);
    cout << "Cost: " << result.cost << endl;
    cout << "Path: ";
    for(int city : result.path) {
        cout << city << " ";
    }
    cout << endl;
    prim(n, distances);
    
    return 0;
}