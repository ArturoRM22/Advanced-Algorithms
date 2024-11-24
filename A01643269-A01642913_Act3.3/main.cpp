#include<iostream>
#include<vector>
using namespace std;

/*
Descripción: 
La función `knapsack` resuelve el problema de la mochila 0/1 utilizando programación dinámica.
Construye una matriz para almacenar las soluciones parciales y maximizar las ganancias sin
exceder la capacidad `m`. La función `knapsackSpaceOptimized` es una versión optimizada que
utiliza un solo vector de tamaño `m+1` en lugar de una matriz para reducir el espacio.

Complejidades:
knapsack: Tiempo O(n * m), Espacio O(n * m)
knapsackSpaceOptimized: Tiempo O(n * m), Espacio O(m)
Autores: 
Gael Venegas Gómez - A01642913
Arturo Ramos Martínez - A01643269 

Fecha: 27/Oct/2024
 */

int knapsack(vector<int>& profits, vector<int>& weights, int m){
    int n = profits.size();
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < m + 1; j++){
             // Si el peso del objeto actual cabe en la mochila
            if(j-weights[i-1] >= 0){
                // Elegimos el mayor valor entre no incluir o incluir el objeto actual
                matrix[i][j] = max(matrix[i-1][j], (matrix[i-1][j-weights[i-1]] + profits[i-1]));
            }else{
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }
    return matrix[n][m];
}
/*
El espacio se puede optimizar ya que en para cada objeto tomamos la solución óptima pasada,
Dado que para cada objeto la solución a la que llegamos es la óptima, podemos solo fijarnos en el renglón anterior
Por lo que solo necesitamos espacio m adicional
Adicionalmente si hacemos los calculos en reversa se puede hacer in place, ya que de esta manera los resultados nuevos no aceptan los resultados futuros
*/
int knapsackSpaceOptimized(vector<int>& profits, vector<int>& weights, int m){
    int n = profits.size();
    vector<int> dp(m+1, 0);
    for(int i = 1; i < n+1; i++){
        for(int j = m; j >= 0; j--){
            if(weights[i-1] <= j){
                dp[j] = max(dp[j], dp[j-weights[i-1]] + profits[i-1]);
            }
        }
    }
    return dp[m];
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
    //cout << knapsackSpaceOptimized(profits, weights, m) << endl;

    return 0;
}