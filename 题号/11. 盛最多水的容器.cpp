// 贪心 数组 双指针
/*
    思路： 如何遍历所有情况
    - 两个指针指向左右两端，指针每次移动计算容量并更新结果；
    - 移动指针的规则，比较左右两个指针，数值较小的那一端移动
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i = 0, j = height.size() - 1; i < j; ) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
};