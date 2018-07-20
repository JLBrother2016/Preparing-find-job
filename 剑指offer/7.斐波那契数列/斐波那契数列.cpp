#include "../util.h"

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n < 2) return n;

        int ans = 1;
        int f1 = 1, f0 = 0;  //利用DP的思路来解这道题
        for(int i = 2; i < n; ++i) {
            f0 = ans;
            ans = ans + f1;
            f1 = f0;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().Fibonacci(89) << endl;

    return 0;
}

