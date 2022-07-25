#include <iostream>
#include <vector>

using namespace std;

//
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int idx = nums.size() / 2;
//        while(nums[idx] != target){
//            if(nums[idx] >= target){
//                idx = idx / 2;
//            }
//            else {
//                idx = (nums.size() - idx) / 2;
//            }
//        }
//
//        if(nums[idx] != target){
//            return {-1,-1};
//        }
//        if(nums[idx + 1] == target){
//            int range_begin = idx;
//            while(nums[idx] != target){
//                idx++;
//            }
//            return {range_begin, idx};
//        }
//        if(nums[idx - 1] == target){
//            int range_end = idx;
//            while(nums[idx] != target){
//                idx--;
//            }
//            return {range_end, idx};
//        }
//
//        return {idx};
//    }
//
//};

int bin_search(vector <int>& nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right){
        int idx = (right - left)/ 2 + left;
        nums[idx] < target ? left = idx + 1 : right = idx - 1;
    }
    return left;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int range_begin = bin_search(nums, target);
    int range_end = bin_search(nums, target + 1) - 1;

    if(range_begin < nums.size() && nums[range_begin] == target){
        return {range_begin, range_end};
    }
    else return {-1,-1};
}

