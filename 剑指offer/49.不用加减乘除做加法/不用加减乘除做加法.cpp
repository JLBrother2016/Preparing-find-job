#include "../util.h"

using namespace std;

class Solution {
public:
    int Add(int num1, int num2) {
        int carry, sum;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;

            num1 = sum;
            num2 = carry;
        } while(num2 != 0);

        return num1;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().Add(4, 4) << endl;

    return 0;
}


