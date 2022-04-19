// 动态规划
/*
    思路：
        - f[i] 表示以nums[i]为结尾的区间和最大值
        - f[i] 的两种可能（按照连续区间长度划分）
            -- 只有nums[i]（长度为1）
                --- nums[i]
            -- 以nums[i]结尾长度>=2
                --- [i-1] + [i]
                --- [i-2, i-1] + [i]
                --- [i-3, i-2, i-1] + [i]
                --- ...
                --- 可以总结为以nums[i-1]结尾的最大值 + nums[i]
                    ---- f[i-1] + nums[i]
        - 状态转移方程：
            -- f[i] = max(nums[i], f[i-1] + nums[i])
            -- 化简（提nums[i]）
                f[i] = nums[i] + max(0, f[i-1]);
*/
// 不使用数组，使用变量记录f[i-1]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;  // 结果
        int last = 0;  // 前一个状态
        for(int i = 0; i < nums.size(); i++) {
            last = nums[i] + max(last, 0);  // 方程化简后
            res = max(res, last);
        }
        return res;
    }
};
// 使用数组
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> f(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            if(!i) f[i] = max(res, nums[i]);
            else {
                f[i] = max(f[i - 1] + nums[i], nums[i]);
            }
            res = max(f[i], res);
        }
        return res;
    }
};