// 深度优先遍历（dfs） 回溯
/*
    思路：
        - 对于给定数组的每一个元素，从第一个元素开始，枚举选择个数0、1、2... 
        - 选择完第一个元素后，确定第二个元素个数... 
        - 以此类推
    核心：
        - 确定搜索顺序，做到不重不漏
*/
class Solution {
public:

    vector<vector<int>> ans;  // 最终结果
    vector<int> path;  // 存放方案

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return ans;
    }
    // dfs参数：已知数组，当前数组下标，剩余目标值
    void dfs(vector<int>& c, int u, int target) {
        // 结束情况
        if(target == 0) {  // 找到方案
            ans.push_back(path);
            return ;
        }
        if(u == c.size()) return ;  // 没找到方案

        // 执行
        for(int i = 0; c[u] * i <= target; i++){  // 当前元素个数
            dfs(c, u + 1, target - c[u] * i);  // 当前个数情况下的，下一种方案
            path.push_back(c[u]);  // 保存结果
        } 
        // 恢复现场
        for(int i = 0; c[u] * i <= target; i++) {
            path.pop_back();
        }
    }
};
// 更好理解一些

/* 
    参考： 
        https://www.bilibili.com/video/BV1KT4y1M7HJ/?spm_id_from=333.788
        https://programmercarl.com/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.html#%E5%9B%9E%E6%BA%AF%E4%B8%89%E9%83%A8%E6%9B%B2

    思路：
        - 画出搜索树，由于是组合问题，不能够重复（即 后面元素的分支中，不能够出现前面元素）
        - 
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    // 未剪枝优化
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target, 0);
        return ans;
    }
    
    // 递归函数（数组，组合总和，目标值，下一层递归索引）
    void dfs(vector<int>& candidates, int sum, int target, int startIndex) {
        // 终止条件
        if(sum > target) return ;
        if(sum == target) {
            ans.push_back(path);
            return;
        }

        // 单层递归
        for(int i = startIndex; i < candidates.size(); i ++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, sum, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};

/*
    思路：剪纸优化版
        - 在升序条件下（在搜索之前，要对数组进行排序）
        - 当 sum + candidates[curr] >= target时，后面比当前元素更大的分支就没有必要搜索了，达到了剪枝的目的
*/
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0);
        return ans;
    }

    // 递归函数(数组，和，目标，下一层递归索引)
    void dfs(vector<int>& candidates, int sum, int target, int startIndex) {
        // 终止条件
        if(sum == target) {
            ans.push_back(path);
            return ;
        }

        // 单层递归函数 && 剪枝 sum + candidates[i] > target
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, sum, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};