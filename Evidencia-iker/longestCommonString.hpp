#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Encuentra la cadena común más larga entre dos textos.
 * 
 * Complejidad de tiempo: O(n * m), donde 'n' es la longitud de text1 y 'm' es la longitud de text2.
 * Complejidad de espacio: O(n * m), debido a la matriz DP utilizada para almacenar las longitudes de las cadenas comunes.
 */
string longestCommonString(const string& text1, const string& text2) {
    int n = text1.size();  
    int m = text2.size();  
    
    // Matriz DP para almacenar las longitudes de cadenas comunes
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  
    
    // Llenar la matriz DP comparando caracteres de ambos textos
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {  
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    // Complejidad de tiempo de la matriz DP: O(n * m)

    string result = "";
    int posI;  
    int maxLen = 0; 

    // Encontrar la cadena común más larga
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {  
            if (dp[i][j] > maxLen) {
                maxLen = dp[i][j];
                result = text1.substr(i - maxLen, maxLen);  
                
                posI = i - maxLen;
            }
        }
    }
    // Complejidad de tiempo para encontrar la cadena más larga: O(n * m)

    cout << "transmission1: " << "Initial position: " << posI + 1 
        << " Final position: " << posI + maxLen << endl;

    return result;  
}
