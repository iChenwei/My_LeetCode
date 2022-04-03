// 字符串 模拟 
/*
    思路：
        - 模拟乘法运算
    
*/
// 特殊方法，看yxc讲解视频更好理解一些
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;  // 存放逆序的num1 和 num2
        // 将num1 和 num2 逆序
        int n = num1.size(), m = num2.size();
        for(int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0');
        for(int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');

        // 不进位乘法
        vector<int> C(m + n);  // 存放处理进位之前的数据
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                C[i + j] += A[i] * B[j];  // 注意
            }
        }

        // 将不进位乘法结果，每一项进行进位
        for(int i = 0, t = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        
        // 处理多余的0
        int k = C.size() - 1;
        while(k > 0 && C[k] == 0) k--;

        // 将C中的每一位进行逆序，得到int下的正确结果
        string res;
        for(int i = k; i >= 0; i--) {
            res += C[i] + '0';
        }

        return res;
    }
};