// 栈 & 字符串
/*
    思路：
    - 确定什么样子的序列是合法的
    - 技巧：与其一一对应，不如利用左右括号之间ascii大小关系
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // 存放左括号
        for(auto &c : s) { // 枚举字符串序列
            // 左括号入栈
            if(c == '(' || c == '[' || c =='{') stk.push(c);
            // 匹配验证
            else {
                if(stk.size() && abs(stk.top() - c) <= 2) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
