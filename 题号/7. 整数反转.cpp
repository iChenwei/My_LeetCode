// 数学
/*
    思想：
    - 取个位（最后一位）： n = n % 10
    - 去掉/删除个位（最后一位）： n = n / 10
    - 将取到的每一位，组成新的数（逆置）秦九韶算法：
        初始：r = 0
        对于每一位数k：r = r * 10 + k

    注意：
        C++中的取模运算中，负数取模的结果为负数。
        -1234 % 10 = -4
*/
class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        while(x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        if(r > INT_MAX) return 0;
        if(r < INT_MIN) return 0;
        return r;
    }
};
