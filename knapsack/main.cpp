#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& profits, vector<int>& weights, int m){
    int n = profits.size();
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(j-weights[i-1] >= 0){
                matrix[i][j] = max(matrix[i-1][j], (matrix[i-1][j-weights[i-1]] + profits[i-1]));
            }else{
                matrix[i][j] = matrix[i-1][j];
            }
            //cout << matrix[i][j] << " ";
        }
        //cout << endl;
    }
    return matrix[n][m];
}

int main(){
    int n;
    cin>>n;
    vector<int> profits(n);
    for(int i = 0; i < n; i++){
        cin>>profits[i];
    }
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin>>weights[i];
    }
    int m;
    cin>>m;
    cout << knapsack(profits, weights, m) << endl;

    return 0;
}