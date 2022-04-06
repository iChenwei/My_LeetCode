// 回溯
/*
    思路：
        - 与组合类问题有所不同，结果是有序的，需要用一个数组来标记其是否使用过即可
        - 枚举每一位，确定每一位能够填的数字
*/
// acwing - yxc
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permute(vector<int>& nums) {
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }
    
    void dfs(vector<int>& nums, int curr) {
        if(curr == nums.size()) {
            ans.push_back(path);
            return ;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!st[i]) {
                st[i] = true;
                path[curr] = nums[i];
                dfs(nums, curr + 1);
                st[i] = false;
            }
        }
    }
};


// 参考：https://www.programmercarl.com/0046.%E5%85%A8%E6%8E%92%E5%88%97.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> st(n, 0);
        dfs(nums, n, st);
        return ans;
    }
    // 递归函数参数（枚举的数组，枚举数组的大小，标记数组）
    void dfs(vector<int>& nums, int n, vector<int>& st) {
        // 递归退出条件
        if(path.size() == n) {
            ans.push_back(path);
            return ;
        }
        // 单层递归逻辑
        for(int i = 0; i < n; i++) {
            if(!st[i]) {
                st[i] = 1;
                path.push_back(nums[i]);
                dfs(nums, n, st);
                path.pop_back();
                st[i] = 0;
            }
        }
    }
};

