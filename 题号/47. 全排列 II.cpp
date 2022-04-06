// 回溯
/*
    思路：
        - 搜索顺序
            - 1. 考虑每一个位置能够填哪些数
            - 2. 枚举每一个数能够填到哪一个位置（适合，按字典序输出 - 能保证字典序）
        - 去重（对于搜索顺序1）：
            - 首先对数组进行排序
            - 对于当前位置，如果和前一个数相同，且前一个数没有被用过，那么当前数则取不到（剪枝）

        - 去重（对于搜索顺序2）：
            -- 值相同的数字，得到的排列结果，相对顺序不发生改变
                --- 对于相同的数字，按照相对顺序的方式逐个使用（相同的数字 k，每次用 最靠前的/第一个 没有用过的 k）
                    ---- nums[i - 1] == nums[i] && !st[i] 时，说明更靠前的相同值没有被用过，不用当前的
*/  
// 参考（搜索顺序1）：https://www.programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> st(n, false);
        sort(nums.begin(), nums.end());
        dfs(nums, n, st);
        return ans;
    }

    void dfs(vector<int>& nums, int n, vector<bool>& st) {
        if(path.size() == n) {
            ans.push_back(path);
            return ;
        }
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1] && !st[i - 1]) continue;
            if(!st[i]) {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, n, st);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};

// acwing - yxc - 搜索顺序2
class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int u) {
        if(u == nums.size()) {
            ans.push_back(path);
            return ;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!st[i]) {
                if(i > 0 && nums[i] == nums[i - 1] && !st[i - 1]) continue;
                st[i] = true;
                path[u] = nums[i];
                dfs(nums, u + 1);
                st[i] = false;
            }
        }
    }
};