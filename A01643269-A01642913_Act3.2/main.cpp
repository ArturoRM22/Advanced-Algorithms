#include<iostream>
#include<vector>
#include"dijkstra.hpp"
#include"floyd.hpp"
using namespace std;

int main(){
    int n;
    cin>>n;
    //Adjacency matrix 
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

    return 0;
}