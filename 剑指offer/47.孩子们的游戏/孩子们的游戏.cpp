#include "../util.h"
using namespace std;

class Solution {
public:        //递推公式:f(n,m) = [f(n-1, m) + m] % n
    int LastRemaining_Solution(int n, int m) {
        if(n < 1 || m < 1)
            return -1;
        int last = 0;
        for(int i = 2; i <= n; ++i) {
            last = (last + m) % i;
        }

        return last;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

