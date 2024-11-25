/*
Codigo que usa la implementacion Ford-Fulkerson en el algoritmo de Edmonds-Karp para encontrar el flujo maximo en un grafo.
Fecha de creacion: 23/11/2024
creado por: Edwin Iniguez Moncada
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

#ifndef MAX_FLOW_HPP
#define MAX_FLOW_HPP

//Funcion que encuentra un camino de aumento en el grafo
//Complejidad: 
//Tiempo: O(V*E)
//Espacio: O(V)
int bfs(const vector<vector<int>>& capacity, vector<vector<int>>& residual, vector<int>& parent, int source, int sink) {
    // Numero de nodos
    int n = capacity.size();
    // Llena el vector de padres con -1
    fill(parent.begin(), parent.end(), -1);
    // El nodo inicial es su propio padre
    parent[source] = source;
    // Cola de nodos
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});

    // Mientras la cola no este vacia
    // Encuentra un camino de aumento
    while (!q.empty()) {
        int current = q.front().first;
        int flow = q.front().second;
        q.pop();
        
        // Revisa los nodos adyacentes
        for (int next = 0; next < n; ++next) {
            if (parent[next] == -1 && residual[current][next] > 0) {  // Not visited and residual capacity > 0
                parent[next] = current;
                int new_flow = min(flow, residual[current][next]);
                if (next == sink)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    // No se encontro camino de aumento
    return 0;
}

//Funcion que calcula el flujo maximo en un grafo
//Complejidad: 
//Tiempo: O(V* E^2)
//Espacio: O(V^2)
int maxFlow(const vector<vector<int>>& capacity, int source, int sink) {
    // Numero de nodos
    int n = capacity.size();
    
    //Vector de capacidades residuales
    vector<vector<int>> residual = capacity;
    
    //Vector de padres
    vector<int> parent(n);
    
    //Empieza el algoritmo de Ford Fulkerson
    //Flujo total
    int total_flow = 0;

    // Mientras haya un camino de aumento
    // Encuentra el flujo máximo de un camino de aumento
    while (int flow = bfs(capacity, residual, parent, source, sink)) {
        total_flow += flow;
        int current = sink;
        
        // Actualiza las capacidades residuales
        while (current != source) {
            int prev = parent[current];
            residual[prev][current] -= flow;
            residual[current][prev] += flow;
            current = prev;
        }
    }

    return total_flow;
}

#endif
