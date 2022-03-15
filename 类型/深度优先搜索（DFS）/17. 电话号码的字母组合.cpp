// 深度优先搜索
/*
    思路：
    - dfs(搜索依据, 当前第几位, 路径)
*/
class Solution {
public:
    vector<string> ans;
    string str[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans; // 特判
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int u, string path) {  // 数字，当前第u位数字转换为字母，结果
        if(u == digits.size()) 
            return ans.push_back(path);
        else {
            for(auto& c : str[digits[u] - '0'])
                dfs(digits, u + 1, path + c);
        }
    }
};