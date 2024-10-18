#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void floydWarshall(vector<vector<int>>& g){
    int n = g.size(); // distance matrix 
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (g[i][k] > 0 && g[k][j] > 0) { 
                    if (g[i][j] == -1) { // First, we have to check whether g[i][j] is -1, because that means we can update it inmediately without doing g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                        g[i][j] = g[i][k] + g[k][j];
                    } else {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
    }
}
