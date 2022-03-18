// 深度优先搜索 字符串
/*
    结论： 判断只有一种括号情况下，是否合法
    - 任意长度的前缀中，左括号的数量 >= 右括号的数量；
    - 左括号的总数 = 右括号的总数。

    思想：
    - 通常使用stack来辅助判断括号匹配
    - 本题中只有一种括号，简化了判断匹配的流程，即：
        只需在遇到右括号的时候，判断当前栈中是否有左括号（不为空，因为遇到左括号就加入到栈中）
    - 依据题目的已知条件和【已知结论】，第二条结论自然满足，只需要判断前缀中左右括号数量关系 
*/
class Solution {
public:

    vector<string> ans; // 存放答案

    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }
    
    // 对数，左右括号数量，第k个序列
    void dfs(int n, int lcnt, int rcnt, string seq) {
        if(lcnt == n && rcnt == n) ans.push_back(seq);
        else{
            if(lcnt < n) {
                dfs(n, lcnt + 1, rcnt, seq + '(');
            }
            if(rcnt < n && lcnt > rcnt) {
                dfs(n, lcnt, rcnt + 1, seq + ')');
            }
        }   
    }
};