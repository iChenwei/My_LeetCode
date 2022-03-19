// 双指针
/*
    思路：
    - 第一个指针枚举每一个元素，第二个指针记录存放位置
    - 如果当前枚举到的元素和val不同，那么就存放到第二个指针记录的位置
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};