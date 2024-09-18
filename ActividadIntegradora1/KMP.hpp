#include<iostream>
#include<vector>
#include <fstream>
#include <sstream> 
using namespace std;

void computeLPS(const string& pattern, vector<int>& lps, int lenPattern){
    int i = 0, j = 1;
    lps[0] = 0;

    while(j < lenPattern){
        if(pattern[i] == pattern[j]){
            lps[j] = i + 1;
            i++;
            j++;
        }else if(i == 0){
            lps[j] = 0;
            j++;
        }else{
            i = lps[i - 1];
        }
    }
}

pair<string, int> KMP(string& str, string& pattern){
    pair<string, int> searchResult;
    searchResult.first = "false";
    searchResult.second = - 1;
    int lenPattern = pattern.size();
    int lenStr = str.size();
    vector<int> lps(lenPattern);
    
    computeLPS(pattern, lps, lenPattern);

    int i = 0, j = 0;
    while(i < lenStr){ // 0 - 14
        //cout << "i: " << i << endl;
        if(str[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == lenPattern){
            //cout << "i: " << i << endl;
            searchResult.first = "true";
            searchResult.second = i - lenPattern + 1;
            return searchResult;
        }else if (i < lenStr && str[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return searchResult;
}