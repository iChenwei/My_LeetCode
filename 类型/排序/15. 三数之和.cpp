// 双指针 & 排序
/*
    思想：
    - 数组排序
    - 由于涉及到了三个数，所以指针st固定第一个数，然后使用双指针算法移动后两个数
    - 为了保证不重复出现，双指针中的l指针每次循环都要指向（st+1）的位置
    - 当 st + l + r == target时，将当前数值加入到结果集中，并将（l+1） 和（r-1），继续寻找下一种可能
    - 当 st + l + r != target时，根据大小关系，移动 l 和 r
    - 去重操作：st每固定一个数，都要和前一个数不同，所以必要时要多移动几个单位
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // 排序
        for(int st = 0; st < nums.size(); st++) { // 固定第一个数
            while(st != 0 && st < nums.size() && nums[st] == nums[st - 1]) st++; // 防止重复
            int l = st + 1, r = nums.size() - 1;
            while(l < r) {
                if(nums[st] + nums[l] + nums[r] == 0) {
                    res.push_back({nums[st], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l - 1]) l++; // 防止重复
                    while(l < r && nums[r] == nums[r + 1]) r--; // 防止重复
                }
                else if(nums[st] + nums[l] + nums[r] < 0) {
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) l++; // 防止重复
                }
                else {
                    r--;
                    while(l < r && nums[r] == nums[r + 1]) r--; // 防止重复
                }
            }
        }
        return res;
    }
};