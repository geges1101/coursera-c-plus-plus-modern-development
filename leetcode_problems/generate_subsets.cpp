#include <iostream>
#include <vector>

using namespace std;

void generateSubs(int idx, vector<int> nums, vector<int> curr, vector<vector<int>> subs){
    subs.push_back(curr);
    for(int i = idx; i < nums.size(); i++){
        curr.push_back(nums[i]);
        generateSubs(i + 1, nums, curr, subs);
        curr.pop_back();
    }
}

    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> subs;
        vector<int> curr;
        generateSubs(0, nums, curr, subs);

        return subs;
    }

int main(){
    vector<int> nums {1, 2, 3};
    auto result = subsets(nums);

    for(auto set : result){
        for(auto item : set){
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
