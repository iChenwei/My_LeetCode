// 位运算
/*
    思路：快速幂（二进制思想）
    - 对于 n >= 0
        -- 反复平方法，求出 x^(2^0)、x^(2^1)、x^(2^2)...
            -- 预处理 x^(2^0) 、x^(2^1)、... 、x^(2^30)
        -- 由于 n 可以用多个 2^(i) + 2^(j) + 2^(k) + ... 
        -- 因此 x^(n) = x^(2^(i) + 2^(j) + 2^(k) + ... )
                    = x^(2^i) * x^(2^j) * x^(2^k)
    - n < 0
        -- 按照n >= 0时计算，然后取倒数
*/
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        // 确定正负号
        bool is_minus;
        if(n < 0) is_minus = true;
        else is_minus = false;

        // 将预处理步骤融合到了计算中
        for(long long k = abs((long long)n); k > 0; k >>= 1) {
            if(k & 1) res *= x;
            x *= x;
        }
        if(is_minus) res = 1 / res;
        return res;
    }
};