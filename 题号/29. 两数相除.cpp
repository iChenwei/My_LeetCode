// 位运算 数学
/*
    思路：二进制思想
    - x/y = k 这个式子可以转换为乘法  x = y * k;
    - k的求解，可以等价为 x 减了多少个 y
    - 考虑在二进制下，k的表示，乘法公式可以转化为:
        x = y * (2^0 + 2^1 + 2^2 + ... + 2^(i) + 2^(i+1) + ...)
    - 预处理所有所有的 y * (2^i)
    - 然后通过 x - y * 2^i 实现对k的求解
        当 x >= y*(2^i) 时， k += 2^i，并且 x -= y*(2^i)
*/
class Solution {
public:
    int divide(int x, int y) {
        // 处理符号
        bool minus = false;
        if((x < 0 && y > 0) || (x > 0 && y < 0)) minus = true;

        // 预处理
        vector<long long> exp;
        long long a = abs((long long) x), b = abs((long long)y);
        for(long long i = b; i <= a; i += i) {
            // y, 2*y, 2*(2y) = 2^(2) * y ... y*(2^(i)) ...
            // 其中exp[i]表示 y*(2^i)，下标为 i 次方
            exp.push_back(i);
        }

        long long ans = 0;
        for(int i = exp.size() - 1; i >= 0; i--) {
            if(a >= exp[i]) {
                ans += 1ll << i;    
                a -= exp[i];
            }
        }
        
        if(minus) ans = -ans;
        if(ans > INT_MAX || ans < INT_MIN) return INT_MAX;
        
        return ans;
    }  
};