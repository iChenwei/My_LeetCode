// 双指针 & 排序
/*
    思路：
    - 排序
    - 固定一个元素，然后用双指针找剩下两个元素，会遇到三种情况：
        - i + l + r == target  , 此时直接返回
        - i + l + r < target  , l++
        - i + l + r >= target , r--
        出现第二种和第三种的情况下，还要及时更新ans
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(abs(nums[i] + nums[l] + nums[r] - target) < abs(ans - target))
                    ans = nums[i] + nums[l] + nums[r];
                if(nums[i] + nums[l] + nums[r] == target)
                    return target;
                else if(nums[i] + nums[l] + nums[r] < target)
                    l++;
                else 
                    r--;
            }
        }
        return ans;
    }
};
