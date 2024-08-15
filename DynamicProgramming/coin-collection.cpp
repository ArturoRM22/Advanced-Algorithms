#include <iostream>
using namespace std;
#include <vector>

struct Result{ //To store the max number of coins and the path to achieve this
    int max_coins;
    vector<string> path;
};

Result coinCollecion(vector<vector<int>>& grid, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i > 0 && j > 0){
                grid[i][j] = max((grid[i][j]+ grid[i-1][j]), (grid[i][j]+ grid[i][j-1]));
            }else if(i != 0){
                grid[i][j] = grid[i][j] + grid[i-1][j];
            }
            else if(i == 0 && j > 0){
                grid[i][j] = grid[i][j] + grid[i][j-1];
            }
        }
    }
    int i = m-1;
    int j = n-1;
    //Get the path backtracking until reach the upper left of the matrix
    Result output;
    int next;
    while(i != 0 || j != 0){
        if(i > 0 && j > 0){
            next = max(grid[i-1][j], grid[i][j-1]);
            if(grid[i-1][j] == next){
                i--;
                output.path.push_back("DOWN");
            }else{
                j--;
                output.path.push_back("RIGHT");
            }
        }else if(i != 0){
            next = grid[i-1][j];
            i--;
            output.path.push_back("DOWN");
        }
        else if(i == 0 && j > 0){
            next = grid[i][j-1];
            j--;
            output.path.push_back("RIGHT");
        }
    }
    output.max_coins = grid[m-1][n-1];
    return output;
}

int main(){
    vector<vector<int>> grid;
    grid = {
        {0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0}
    };
    Result out = coinCollecion(grid, 5, 6);
    cout << "Max number of coins: " << out.max_coins << endl;
    cout << "Path: "<< endl;
    for (int i = out.path.size() - 1; i >= 0; --i) {
        cout << out.path[i] <<", ";
    }
    return 0;
}
