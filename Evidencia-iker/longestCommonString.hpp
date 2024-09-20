#include <iostream>
#include <string>
#include <vector>
using namespace std;



string longestCommonString(const string& text1, const string& text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    string result = "";
    vector<int> pos_i, pos_j;
    int max_len = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] > max_len){
                max_len = dp[i][j];
                result = text1.substr(i-max_len, max_len);
                pos_i.clear();
                pos_j.clear();
                pos_i.push_back(i-max_len);
                pos_j.push_back(j-max_len);  
            }
        }
    }
    
    for (int i = 0; i < pos_i.size(); i++){
        cout << "pos_i: " << pos_i[i] << " pos_j: " << pos_j[i] << endl;
    }

    return result;
}
