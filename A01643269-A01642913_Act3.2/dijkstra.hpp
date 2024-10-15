#include<iostream>
#include<vector>
#include<unordered_set>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& g, int source){
    int n = g.size();
    //distance vector
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    //distance priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // type, container, compare
    pq.push({0, source});

    while(!pq.empty()){
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        //relax neighbors 
        for(int i = 0; i < n; i++){
            if(g[currNode][i] > 0){ // to avoid checking -1 and itself connection
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