#include "../util.h"

using namespace std;

class Solution {
public:                 //递推公式:f(n) = f(n-1) + f(n-2)
    int rectCover(int number) {
        if(number < 3)
            return number;
        int ans = 0;
        int f1 = 1;
        int f2 = 2;
        for(int i = 3; i <= number; ++i) {
            ans = f1 + f2;
            f1 = f2;
            f2 = ans;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().rectCover(5) << endl;

    return 0;
}
