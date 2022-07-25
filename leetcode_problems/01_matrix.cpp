#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return matrix;
        int collumns = matrix[0].size();

        vector<vector<int>> distances(rows, vector<int>(collumns, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0; i != rows; i++){
            for(int j = 0; j != collumns; j++){
                if(matrix[i][j] == 0) {
                    distances[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto item = q.front();
            q.pop();
            for(int i = 0; i != 4; i++){
                int new_row = item.first + directions[i][0];
                int new_collumn = item.second + directions[i][1];

                if(new_row >= 0 && new_collumn >= 0 && new_row < rows && new_collumn < collumns){
                    if(distances[new_row][new_collumn] > distances[item.first][item.second] + 1){
                        distances[new_row][new_collumn] = distances[item.first][item.second] + 1;
                        q.push({new_row,new_collumn});
                    }
                }
            }
        }

        return distances;
    }
};