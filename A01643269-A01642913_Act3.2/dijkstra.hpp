#include<iostream>
#include<vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& g, int source){
    int n = g.size();
    // Distance vector
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Visited set to track finalized nodes
    vector<bool> visited(n, false);

    // Distance priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // type, container, compare
    pq.push({0, source}); 

     /* Ciclo principal, en el que se itera cada vértice una vez, y se intenta aplicar la fórmula de relajación en los nodos/vertices vecinos no visitados/procesados (nodo visitado/procesado = no ha pasado por la cola de prioridad). 
     Aquí se hacen la inserción en la cola de prioridad para darle seguimiento al camino más corto y se va actualizando el vector de distancia
     el cual almacena el resultado final.
     Complejidad:
        -Tiempo: O(v^2*log(v)) v = vértices. Esto porque para cada vértice, existe la posibilidad de aplicar la fórmula de relajación en todos los vértices restantes
        Además, si se encuentra un mejor camino, se necesita actualizar la cola de prioridad, lo cual tiene una complejidad de O(log(v)).
        -Espacio: O(v^2 + 3v) = O(v^2) debido a la matriz de adyacencia y las estructuras de datos mencionadas anteriormente.
     */
    while(!pq.empty()){
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        // If node has been visited, skip it
        if (visited[currNode]) continue;
        
        // Mark the node as visited
        visited[currNode] = true;

        // Relax neighbors
        for(int i = 0; i < n; i++){
            if(g[currNode][i] > 0 && !visited[i]){ // Only consider unvisited neighbors, avoid itself and inifinty 
                int newDist = currDist + g[currNode][i];
                if(newDist < dist[i]){
                    dist[i] = newDist;
                    pq.push({dist[i], i});
                } 
            }
        }
    }
    return dist;
}
