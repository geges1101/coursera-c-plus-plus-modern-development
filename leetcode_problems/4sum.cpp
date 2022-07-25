class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> twoSum(vector<int>& nums, int target, int idx){
        vector<vector<int>> solution;

        int left = idx;
        int right = nums.size() - 1;

        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target ||(left > idx && nums[left] == nums[left - 1])) left++;
            else if(sum > target || (right < nums.size() - 1 && nums[right] == nums[right + 1])) right--;
            else solution.push_back({nums[left++], nums[right--]});
        }
        return solution;
    }

    vector<vector<int>> kSum(vector<int>& nums, int target, int idx, int k){
        vector<vector<int>> solution;
        if (idx == nums.size() || nums[idx] * k > target || target > nums.back() * k) return solution;

        if(k == 2) return twoSum(nums, target, idx);

        for(int i = idx; i != nums.size(); i++)
            if(i == idx || nums[i - 1] != nums[i])
                for(auto &set : kSum(nums, target - nums[i], i + 1, k - 1)){
                    solution.push_back({nums[i]});
                    solution.back().insert(solution.back().end(), begin(set), end(set));
                }
        return solution;
    }
};

