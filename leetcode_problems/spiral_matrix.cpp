#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        int rows = matrix[0].size();
//        int collumns = matrix.size();
//
//        vector<int> result(rows * collumns);
//
//        int cur_row = rows;
//        int cur_coll = collumns;
//
//        while(result.back() != matrix[rows / 2][collumns / 2]){
//            int j = collumns - cur_coll;
//
//            for(int i = rows - cur_coll; i != cur_row; i++) result.push_back(matrix[i][j]);
//
//            int i = rows - cur_row;
//
//            for(j = collumns - cur_coll; j != cur_coll; j++) result.push_back(matrix[i][j]);
//
//            j = cur_coll;
//
//            for(i = cur_row - 1; i >= rows - cur_coll; i--) result.push_back(matrix[i][j]);
//
//            i = cur_row;
//
//            for(j = cur_coll - 1; j >= collumns - cur_coll; j--) result.push_back(matrix[i][j]);
//
//            cur_coll--;
//            cur_row--;
//        }
//
//        return result;
//    }
//};

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int> result;

    if(matrix.empty()) return result;
    if(matrix.size() == 1) return matrix[0];

    if(matrix[0].size() == 1){
        for(int i = 0; i != matrix.size(); i++){
            result.push_back(matrix[i][0]);
        }
        return result;
    }

    int rows = matrix.size();
    int collumns = matrix[0].size();

    int cur_row = rows;
    int cur_coll = collumns;

    while(result.size() != rows * collumns){
        int i = rows - cur_row;
        for(int j = collumns - cur_coll; j != cur_coll; j++)result.push_back(matrix[i][j]);

        if(result.size() == rows * collumns) return result;

        int j = cur_coll - 1;
        for(i = rows - cur_row + 1; i != cur_row; i++) result.push_back(matrix[i][j]);

        if(result.size() == rows * collumns) return result;

        i = cur_row - 1;
        for(j = cur_coll - 2; j >= collumns - cur_coll; j--) result.push_back(matrix[i][j]);

        if(result.size() == rows * collumns) return result;

        j = collumns - cur_coll;
        for(i = cur_row - 2; i >= rows - cur_row + 1; i--) result.push_back(matrix[i][j]);

        cur_coll--;
        cur_row--;
    }

    return result;
}

//int main(){
//    vector<vector<int>> matr {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
//
//    vector <int> spiral_matr = spiralOrder(matr);
//
//    for(auto i : spiral_matr){
//        cout << i << " ";
//    }
//
//            return 0;
//}
