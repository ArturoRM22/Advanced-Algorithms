#include<iostream>
#include<vector>
#include"TSP.hpp"
#include"Prims.hpp"
#include"EdmondsKarp.hpp"
using namespace std; 

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

    //------Prims------//
    cout<<"Forma de cablear las colonias con fibra: "<< endl;
    prim(n, distances);
    cout<<endl;
    //----------//

    //----TSP----//
    cout<<"Costo y ruta a seguir por el personal que reparte correspondencia: "<< endl;
    COST_AND_PATH result = TSP(distances);
    cout << "Cost: " << result.cost << endl;
    cout << "Path: ";
    for(int city : result.path) {
        cout << city << " ";
    }
    cout << endl;
    //----------//


    //------Flujo Máximo----//
    cout<<endl;
    cout<<"Valor de flujo máximo de información del nodo inicial al nodo final: "<< endl;
    //Nodo inicial y final
    int source = 0;
    int sink = distances[0].size()-1;
    cout << "Source: " << source << " Sink: " << sink << endl;

    // Calcular flujo máximo para el grafo
    int max_flow = maxFlow(capacities, source, sink);

    cout << "Flujo maximo: " << max_flow << endl;
    //----------//
    

    //------Diagramas de voronoi----//
    
    //----------//

    return 0;
}
