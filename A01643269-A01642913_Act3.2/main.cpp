/* 
Descripción:
Implementación de los algoritmos Dijkstra y Floyd-Warshall.
Dijkstra: 
Este algoritmo nos permite encontrar el camino más corto desde un nodo o vertice fuente a todos los nodos alcanzables del grafo;
dijkstra utiliza la tecnica greedy, ya que en cada iteración elige el camino tentativo más corto hacia alguno de sus vecinos. 
De esta manera, una vez que un vertice es procesado/visitado, se asume que no existe un camino más corto para ese nodo, a menos que
se tenga un grafo con pesos negativos, pero en este caso dijkstra fallaría.
Para esta implemetación usamos una priority queue para hacer más eficiente el seguimiento del camino más corto en cada iteración. 
Estructuras de datos clave:
    -Priority queue
    -Visited array
    -Distance vector
Complejidad:
    Tiempo: 
    Espacio:
Floyd-Warshall

Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 17/Oct/2024
*/

#include<iostream>
#include<vector>
#include"dijkstra.hpp"
#include"floyd.hpp"
using namespace std;

int main(){
    int n;
    cin>>n;
    //Adjacency matrix (grafo)
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cin>>g[i][j];
        }
    }
    //Dijkstra
    cout << "Dijkstra:" << endl;
    for(int i = 0; i < n; i++){
        vector<int> distances = dijkstra(g, i);
        for (int j = 0; j < n; j++){
            if(j != i){
                cout <<"node "<<i+1<<" to node "<<j+1<<": "<< distances[j] << endl;
            }
        }
    }
    //Floyd
    cout << "Floyd:" << endl;

    return 0;
}