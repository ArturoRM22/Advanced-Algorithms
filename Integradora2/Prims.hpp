#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <numeric>

using namespace std;
/*
Function to implement Prims algorithm for finding a minimum spanning tree
Time complexity: O(ElogV) where E are edges and V are vertices
Space complexity: O(V) since you need a linear priority queue to store the nearest vertices
*/
void prim(int n, vector<vector<int>> &matrix) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> key(n, INT_MAX);

    //Aditional vector to be able to print which edges the MST goes through
    vector<int> parent(n, -1);

    //Additional vector to keep track of which vertices are already in the MST
    vector<bool> inMST(n, false);

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        // Extract the vertex with the smallest key value
        int u = pq.top().second;
        pq.pop();

        // Include vertex u in the MST
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (int v = 0; v < n; ++v) {
            // Check if there is an edge (matrix[u][v] > 0), and v is not yet in MST
            if (matrix[u][v] > 0 && !inMST[v] && matrix[u][v] < key[v]) {
                // Update key and parent
                key[v] = matrix[u][v];
                parent[v] = u;
                pq.push({key[v], v}); // Push the updated key and vertex
            }
        }
    }
    //Print the edges the MST goes through
    cout << "Edges in the MST:" << endl;
    for (int i = 1; i < n; ++i) {
        cout << "(" << char('A' + parent[i]) << ", " << char('A' + i) << ") with weight " << matrix[parent[i]][i] << endl;
    }
    cout << "Total weight of MST: " << accumulate(key.begin(), key.end(), 0) << endl;
}