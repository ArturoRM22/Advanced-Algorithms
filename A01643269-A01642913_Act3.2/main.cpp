/* 
Descripción:
Implementación de los algoritmos Dijkstra y Floyd-Warshall.
Dijkstra:
Este algoritmo nos permite encontrar el camino más corto desde un nodo o vértice fuente a todos los nodos alcanzables del grafo;
dijkstra utiliza la técnica greedy, ya que en cada iteración elige el camino tentativo más corto hacia alguno de sus vecinos.
De esta manera, una vez que un vértice es procesado/visitado, se asume que no existe un camino más corto para ese nodo, a menos que
se tenga un grafo con pesos negativos, pero en este caso dijkstra fallaría.
Para esta implementación usamos una priority queue para hacer más eficiente el seguimiento del camino más corto en cada iteración.
Estructuras de datos clave:
    -Priority queue
    -Visited array
    -Distance vector
Complejidad:
    Tiempo: O(v^2*log(v)) v = vértices. Esto porque para cada vértice, existe la posibilidad de aplicar la fórmula de relajación en todos los vértices restantes
    Además, si se encuentra un mejor camino, se necesita actualizar la cola de prioridad, lo cual tiene una complejidad de O(log(v)).
    Espacio: O(v^2 + 3v) = O(v^2) debido a la matriz de adyacencia y las estructuras de datos mencionadas anteriormente.

Floyd-Warshall:

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
    floyd(g);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}