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
