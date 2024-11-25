#include<iostream>
#include<vector>
#include"TSP.hpp"
#include"Prims.hpp"
#include"EdmondsKarp.hpp"
#include"VoronoiDiagram.hpp"
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

    //----Voronoi----//
    vector<Point> points;
    string line;
    
    // Leer puntos para el diagrama de Voronoi
    cout << "\nIngrese los puntos para el diagrama de Voronoi (formato: (x,y)):\n";
    while (getline(cin, line)) {
        if (line.empty()) break;
        
        stringstream ss(line);
        double x, y;
        char discard;
        
        if (ss >> discard >> x >> discard >> y >> discard) {
            points.push_back({x, y});
        }
    }

    if (!points.empty()) {
        vector<Region> voronoiRegions = constructVoronoiDiagram(points);

        cout << fixed;
        cout.precision(2);
        
        cout << "\nResultados del diagrama de Voronoi:\n";
        for (size_t i = 0; i < voronoiRegions.size(); ++i) {
            cout << "Región #" << i + 1 << ": Sitio ("
                 << voronoiRegions[i].site.x << ", "
                 << voronoiRegions[i].site.y << ")" << endl;

            cout << "Vértices: ";
            for (const Point& vertex : voronoiRegions[i].vertices) {
                cout << "(" << vertex.x << ", " << vertex.y << ") ";
            }
            cout << endl << endl;
        }
    }

    return 0;
}