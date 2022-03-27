// 数组 二分查找
/*
    二分的本质：
        - 在某种条件下，一个区间可以被分为两部分，一部分满足条件（性质），另一部分不满足条件
    二分的作用：
        - 找到满足条件的区间边界
            - 左区间的右端点(mid = l + r + 1 >> 1)
            - 右区间的左端点(mid = l + r >> 1)
    二分的适用情况：
        - 单调性
        - 【二分的本质】
    
    思路：
        - 利用二分找到分界点
            -- 确定分界点（目标答案的位置）：答案在第一段的最后一个元素（左区间的右端点）
            -- 二分的条件：分界点大于等于首元素（nums[0]）
        - 根据分界点确定区间，在区间中使用二分找到目标值
            -- 确定分界点：假设目标元素（target，答案）在右区间的左端点
            -- 二分的条件：分界点大于等于目标元素（target），即
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 特判
        if(nums.empty()) return -1;
        // 找中间点，确定新的边界
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        if(target >= nums[0]) l = 0;
        else l = l + 1, r = nums.size() - 1;

        // 找目标元素（target）
        while(l < r) {
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if(nums[r] == target) return r;
        else return -1;
    }
};