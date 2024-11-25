/* 
Descripción: 
Resolución de la actividad integradora número 2 a través de la implementación de algoritmos como Prims, 
Edmonds Karp, Held-Karp y Voronoi. 

Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 
Edwin Iniguez Moncada - A01637064
Iker Borja Rios - A01637972

Fecha: 25/Nov/2024

 */
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
    

    //------Prims------//
    cout<<"- Forma de cablear las colonias con fibra: "<< endl;
    prim(n, distances);
    cout<<endl;
    //----------//

    //----TSP----//
    cout<<"- Costo y ruta a seguir por el personal que reparte correspondencia: "<< endl;
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
    cout<<"- Valor de flujo máximo de información del nodo inicial al nodo final: "<< endl;
    //Nodo inicial y final
    int source = 0;
    int sink = distances[0].size()-1;
    cout << "Source: " << source << " Sink: " << sink << endl;

    // Calcular flujo máximo para el grafo
    int max_flow = maxFlow(capacities, source, sink);

    cout << "Flujo maximo: " << max_flow << endl;
    //----------//

    //----Voronoi----//
    vector<Point> points;
    string line;
    
    // Leer puntos para el diagrama de Voronoi
    //cout << "\nIngrese los puntos para el diagrama de Voronoi (formato: (x,y)):\n";
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
        
        cout << "\n -Resultados del diagrama de Voronoi:\n";
        cout<<"Lista de polígonos"<<endl;
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