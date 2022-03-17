// 双指针 & 排序
/*
    思路：
    - 参考三数之和，只是多了一层循环
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; // 结果集
        sort(nums.begin(), nums.end()); // 排序
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {  // 固定第一个数
            while(i > 0 && i < n && nums[i] == nums[i - 1]) i++;

            for(int j = i + 1; j < n; j++) { // 固定第二个数
                while(j != i + 1 && j < n && nums[j] == nums[j - 1]) j++;

                int l = j + 1, r = n - 1;
                while(l < r) {
                    if((long)nums[i] + nums[j] + nums[l] + nums[r]== target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while(l < r && nums[l] == nums[l - 1]) l++;
                        while(l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if((long)nums[i] + nums[j] + nums[l] + nums[r] < target) {
                        l++;
                        while(l < r && nums[l] == nums[l - 1]) l++;
                    }
                    else {
                        r--;
                        while(l < r && nums[r] == nums[r + 1]) r--;
                    }
                }
            }
        }
        return res;
    }
};