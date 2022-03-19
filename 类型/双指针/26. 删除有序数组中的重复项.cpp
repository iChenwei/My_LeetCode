// 双指针
/*
    思路：
    - 第一个指针枚举所有数字，第二个指针用来标记当前存放元素的位置（存放第一次在数组中出现的元素）
    - 存放元素的条件：
        枚举到的元素和它前面的元素不同（第一次出现），存放当前元素并移动两个指针；
        否则，枚举下一个数。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) k++;
            else if(nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};