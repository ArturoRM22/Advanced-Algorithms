// TSP.hpp

/* 
Esta solución para el TSP usa programación dinamica para calcular el costo minimo y el mejor camino 
para visitar cada cuidad y regresar a la cuidad inicial. Se crea una mátriz (dp) donde cada fila representa cada
subset de cuidades visitadas posible y cada columna representa la cuidad en la que se termina o la ultima cuidad 
visitada hasta ese paso, los valores nos indican el valor minimo requerido para visitar ese subset de cuidades y 
terminar en cierta cuidad. La última fila etonces representa los valores minimos requeridos para visitar todas 
las cuidades, y estos cambian dependiendo de la última cuidad visitada. 

Esta implementación hace uso de una representación binaria de los subsets de cuidades visitadas. 
Ejemplo: 

0011 = cuidad 0 y 1 visitadas. 

¿Cómo sabemos que una cuidad esta visitada?

if (mask & (1 << next)) continue;

mask = 3 = 0011
next = 3

1 << next = 1000

0011 & 1000 = 0 

El resultado es 0. Esto indica que el bit correspondiente a la ciudad 3 no está activado en mask, por lo tanto, la ciudad 3 no ha sido visitada.


De esta manera hacemos más eficiente el algorithmo; aunque si dificulta un poco más la explicación.

 */

#include<iostream>
#include<vector>
#include<climits> 
#include<bitset>   
#include<algorithm> 
using namespace std;

// Estructura para devolver el costo y el camino óptimo
struct COST_AND_PATH   
{
    int cost;           
    vector<int> path;   
};

COST_AND_PATH TSP(const vector<vector<int>>& distances) {
    int n = distances.size();       
    int numStates = 1 << n;             
    
    // dp[mask][pos]: Representa el costo mínimo para visitar las ciudades indicadas en `mask`, terminando en `pos`.
    vector<vector<int>> dp(numStates, vector<int>(n, INT_MAX));
    
    // parent[mask][pos]: Representa la ciudad anterior en el camino óptimo al llegar a `pos` con `mask`.
    vector<vector<int>> parent(numStates, vector<int>(n, -1));
    
    // Caso base: empezar desde la ciudad 0
    dp[1][0] = 0;  // mask = 0001 (solo la ciudad 0 visitada)

    // Iteramos sobre todas las máscaras posibles (subconjuntos de ciudades visitadas)
    for (int mask = 1; mask < numStates; mask++) {
        // Iteramos sobre todas las ciudades posibles como última ciudad visitada (pos)
        for (int pos = 0; pos < n; pos++) {
            // Verificar si la ciudad pos está en el subconjunto representado por mask
            if (!(mask & (1 << pos))) continue;

            // Si no hay un costo válido para este estado, lo ignoramos
            if (dp[mask][pos] == INT_MAX) continue;
            
            // Intentamos visitar cada ciudad siguiente (next)
            for (int next = 0; next < n; next++) {
                // Saltar si la ciudad next ya ha sido visitada
                if (mask & (1 << next)) continue;
                
                // Actualizamos la máscara para incluir next
                int newMask = mask | (1 << next);
                
                // Calculamos el costo de ir de pos a next
                int newCost = dp[mask][pos] + distances[pos][next];
                
                // Si encontramos un costo menor, actualizamos dp y parent
                if (newCost < dp[newMask][next]) {
                    dp[newMask][next] = newCost;
                    parent[newMask][next] = pos;
                }
            }
        }
    }
    
/* 

Acá es donde accedemos a la mask final, la cual representa todas las cuiades visitadas.
Y como queremos volver a la cuidad inicial, pos = 0. 
 */
    int finalMask = numStates - 1;  
    int pos = 0;                   
    int minCost = INT_MAX;         
    
    // Buscamos entre las posibles ciudades finales
    for (int p = 1; p < n; p++) {
        if (dp[finalMask][p] != INT_MAX) {
            // Calculamos el costo total regresando a la ciudad inicial (0)
            int cost = dp[finalMask][p] + distances[p][0];
            if (cost < minCost) {
                minCost = cost;
                pos = p; 
            }
        }
    }
    
    /* 
    Para reconstruir el camino óptimo, hacemos uso de la matriz parent, la cual fue guardando
    el cuidad de la cual provienes para haber visitado el subset de cuidades y para haber terminado 
    en una cuidad especifica, por ejemplo:

    Mask 1111: [-1, 3, 3, 2] esta sería la última fila. 
                 0  1  2  3

    Acá podemos ver que todas las ciudades han sido visitadas, y que por ejemplo para terminar en la 
    cuidad dos, tuvimos que pasar antes por la cuidad 3. 
     
     */
    vector<int> path;
    int mask = finalMask; 
    
    while (pos != -1) {
        path.push_back(pos);         
        int newPos = parent[mask][pos]; 
        mask ^= (1 << pos);           
        pos = newPos;                
    }
    
    // Revertimos el camino para obtener el orden correcto
    reverse(path.begin(), path.end());
    path.push_back(0); // importante agregar la cuidad inicial al final del camino. 

    COST_AND_PATH output;
    output.cost = minCost;
    output.path = path;
    
    return output;
}
