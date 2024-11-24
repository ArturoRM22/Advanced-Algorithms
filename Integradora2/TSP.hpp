// TSP.hpp
#include<iostream>
#include<vector>
#include<climits>
#include<bitset>
#include<algorithm>
using namespace std;

struct COST_AND_PATH   
{
    int cost;
    vector<int> path;
};


// Optional: Function to reconstruct the path
COST_AND_PATH TSP(const vector<vector<int>>& distances) {
    int n = distances.size();
    int numStates = 1 << n;
    
    vector<vector<int>> dp(numStates, vector<int>(n, INT_MAX));
    vector<vector<int>> parent(numStates, vector<int>(n, -1));
    
    dp[1][0] = 0;
    
    // Similar DP computation as above, but now tracking parent nodes
    for(int mask = 1; mask < numStates; mask++) {
        for(int pos = 0; pos < n; pos++) {
            if(!(mask & (1 << pos))) continue;
            if(dp[mask][pos] == INT_MAX) continue;
            
            for(int next = 0; next < n; next++) {
                if(mask & (1 << next)) continue;
                
                int newMask = mask | (1 << next);
                int newCost = dp[mask][pos] + distances[pos][next];
                
                if(newCost < dp[newMask][next]) {
                    dp[newMask][next] = newCost;
                    parent[newMask][next] = pos;
                }
            }
        }
    }
    
    // Find end position that gives minimum cost
    int finalMask = numStates - 1;
    int pos = 0;
    int minCost = INT_MAX;
    
    for(int p = 1; p < n; p++) {
        if(dp[finalMask][p] != INT_MAX) {
            int cost = dp[finalMask][p] + distances[p][0];
            if(cost < minCost) {
                minCost = cost;
                pos = p;
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    int mask = finalMask;
    
    while(pos != -1) {
        path.push_back(pos);
        int newPos = parent[mask][pos];
        mask ^= (1 << pos);
        pos = newPos;
    }
    
    // Reverse path and add starting city at both ends
    reverse(path.begin(), path.end());
    path.push_back(0);  // Return to starting city

    COST_AND_PATH output;
    output.cost = minCost;
    output.path = path;
    
    return output;
}