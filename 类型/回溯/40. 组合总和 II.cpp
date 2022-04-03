// 回溯 深度优先搜索dfs
/*
    思路 & 参考：
        - https://programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html#%E5%9B%9E%E6%BA%AF%E4%B8%89%E9%83%A8%E6%9B%B2
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        dfs(candidates, target, 0, 0, used);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        // 终止条件
        if(sum == target) {
            ans.push_back(path);
            return ;
        }

        // 单层递归函数
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 剪枝
            if(i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            dfs(candidates, target, sum, i + 1, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }
};
