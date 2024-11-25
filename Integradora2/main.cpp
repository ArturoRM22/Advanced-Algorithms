#include<iostream>
#include<vector>
#include"TSP.hpp"
#include"Prims.hpp"
#include"EdmondsKarp.hpp"
using namespace std; 

//TSP struct

int main() {
    int n; // number of cities
    cin >> n;
    vector<vector<int>> distances(n, vector<int>(n));
    vector<vector<int>> capacities(n, vector<int>(n));
    
    // Read distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> distances[i][j];
        }
    }

    // Read capacity matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> capacities[i][j];
        }
    }
    
    //----TSP----//
    COST_AND_PATH result = TSP(distances);
    cout << "Cost: " << result.cost << endl;
    cout << "Path: ";
    for(int city : result.path) {
        cout << city << " ";
    }
    cout << endl;
    //----------//
    
    //------Prims------//
    prim(n, distances);
    //----------//


    //Nodo inicial y final
    int source = 0;
    int sink = distances[0].size()-1;
    cout << "Source: " << source << " Sink: " << sink << endl;

    // Calcular flujo máximo para el grafo
    int max_flow = maxFlow(capacities, source, sink);

    cout << "Flujo maximo: " << max_flow << endl;
    
    return 0;
}
