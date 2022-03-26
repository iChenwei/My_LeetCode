// 双指针 数组
/*
    思路：
    - 从后往前看，即从后往前确定线段
    - 不会出现下一个排列的情况：
        单调递减（中间可连续相等）
    - 找到满足上述情况的结点（分界点）
        分界点及其后续元素组成的序列是无法变大的
    - 调整分界点的前后元素，构成新的序列：
        分界点前面的元素：比分界点要小
        分界点后面的元素：在序列中找到，比分界点前面的元素大，但是两者差距最小
        让分界点后面的元素去交换前面的元素。
    - 再与分界点前面的元素交换后，将分界点及其后面的元素，即整个序列，调整为升序/递增/单调不减
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 找到分界点
        int k = nums.size() - 1;
        while(k > 0 && nums[k - 1] >= nums[k]) k--; 
        // 处理
        if(k <= 0) {
            reverse(nums.begin(), nums.end()); // 特判：整体倒序
        } else {
            int t = k;
            while(t < nums.size() && nums[t] > nums[k - 1]) t++;
            swap(nums[k - 1], nums[t - 1]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};