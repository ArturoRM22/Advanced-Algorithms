#include<iostream>
#include <fstream>
#include <sstream> 
#include <vector> 
#include <algorithm>
#include"KMP.hpp"
#include"longestCommonSubsequence.hpp"
using namespace std;

string removeNewlines(const string& str) {
    string result = str;
    //cout << "before removeNewlines: " << endl << result << endl;
    result.erase(remove(result.begin(), result.end(), '\n'), result.end());
    result.erase(remove(result.begin(), result.end(), '\r'), result.end());
    //cout << "after removeNewlines: " << endl << result << endl;
    return result;
}

vector<string> readTxt(const vector<string>& fileNames) {
    vector<string> contentFiles;

    for (const auto& fileName : fileNames) {
        ifstream file(fileName);

        if (!file.is_open()) {
            cout << "Error: Could not open the file " << fileName << endl;
            continue;
        }

        string line;
        string fileContent;
        while (getline(file, line)) {
            // Append line to the result
            fileContent += line;
        }
        fileContent = removeNewlines(fileContent);
        
        contentFiles.push_back(fileContent);

        // Output the file content
        //cout << "File Content: " << endl << fileContent << endl;

        file.close();
    }
    return contentFiles;
}


int main(){
    vector<string> filesNameMalicious = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};
    vector<string> filesNameTransmissions = {"transmission1.txt", "transmission2.txt"};

    vector<string> contentMalicious = readTxt(filesNameMalicious);
    vector<string> contentTransmissions = readTxt(filesNameTransmissions);

    /* Parte 1 KMP */
    for(auto t : contentTransmissions){
        pair<string, int> searchResult;
        //cout <<"Transmission: "<< t << endl;
        for(auto m: contentMalicious){
            //cout <<"Malicious: "<< m << endl;
            searchResult = KMP(t, m);
            if(searchResult.first == "true"){ 
                cout << searchResult.first;
                cout << " "<< searchResult.second << endl;
            }else{
                cout << searchResult.first << endl;
            }
        }
    }
    /* ------------------------------------------ */


    /* Parte 2 */


    /* ------------------------------------------ */


    /* Parte 3 */
    string transmission1 = contentTransmissions[0];
    string transmission2 = contentTransmissions[1];
    cout << contentTransmissions[0].size() << endl;
    cout << contentTransmissions[1].size() << endl;
    string LongestSTR = longestCommonSubsequence(transmission1, transmission2);
    cout << "Longest string: " + LongestSTR << endl;

    /* ------------------------------------------ */
    
    return 0;
}