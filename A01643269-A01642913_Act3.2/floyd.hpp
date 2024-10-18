#include<iostream>
#include<vector>
#include<unordered_set>
#include <queue>
#include <climits>
using namespace std;

void floyd(vector<vector<int>>& g){
  int v = g.size();
  for (int k=0; k<v; k++) {
    for (int i=0; i<v; i++) {
      for (int j=0; j<v; j++) {
        if (g[i][k] != -1 && g[k][j] != -1) {
            if (g[i][j] == -1 || g[i][k] + g[k][j] < g[i][j]) {
                g[i][j] = g[i][k] + g[k][j];
            }
        }
      }
    }
  }
}