// 栈
/*
    - 思路：
        -- 扫描序列
            --- 运算符：栈中元素出栈，计算，并将结果入栈
                ---- 先出栈的是「右操作数」，后出栈的是「左操作数」
            --- 操作数：入栈
        -- 返回栈顶元素

    - stoi()函数：
        -- #include<string>
        -- 把string类型变量转换成int类型
            --- stoi(x);  // 把(string)x转换成(int)x
            --- stoi(str, start, n);  // 把n进制的str，中从下标start起到末尾的字符串,转换成十进制
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if(tokens[i] == "+") a += b;
                else if(tokens[i] == "-") a -= b;
                else if(tokens[i] == "*") a *= b;
                else if(tokens[i] == "/") a /= b;
                stk.push(a);
            }
            else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};