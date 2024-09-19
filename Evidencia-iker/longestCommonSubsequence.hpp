#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonSubsequence(const string& text1, const string& text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string result = "";
    int i = n, j = m;
    vector<int> pos_i, pos_j;
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            result = text1[i-1] + result;
            pos_i.push_back(i);
            pos_j.push_back(j);
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    cout << "Initial positions: " << endl;
    cout << "transmission1.txt: " << pos_i[pos_i.size()-1] << endl;
    cout << "transmission2.txt: " << pos_j[pos_j.size()-1] << endl;
    cout << "Final positions: " << endl;
    cout << "transmission1.txt: " << pos_i[0]  << endl;
    cout << "transmission2.txt: " << pos_j[0]  << endl;
    return result;
}
