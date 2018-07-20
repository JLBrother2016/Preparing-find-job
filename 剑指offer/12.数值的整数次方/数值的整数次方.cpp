#include "../util.h"

using namespace std;

class Solution {    //二进制做法
public:
    double Power(double base, int exponent) {
        double ans = 1.0, curr = base;
        int n;

        if(exponent == 0)           //特殊情况的处理
            return 1.0;
        else if(exponent > 0) {     //整数的次方
            n = exponent;
        } else {                    //负数的次方
            n = -exponent;
        }
        while(n != 0) {
            if((n & 1) == 1)
                ans *= curr;
            curr *= curr;
            n >>= 1;
        }

        return exponent > 0 ? ans : 1 / ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

