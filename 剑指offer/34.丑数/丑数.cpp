#include "../util.h"

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        vector<int> tmp(index, 0);
        tmp [0] = 1;
        int ugly2 = 0;
        int ugly3 = 0;
        int ugly5 = 0;
        int nextidx = 1;

        while(nextidx < index) {
            int min_val = min(tmp[ugly2] * 2, 
                          min(tmp[ugly3] * 3, tmp[ugly5] * 5));
            tmp[nextidx] = min_val;
            while(tmp[ugly2] * 2 <= min_val) 
                ++ugly2;
            while(tmp[ugly3] * 3 <= min_val) 
                ++ugly3;
            while(tmp[ugly5] * 5 <= min_val)
                ++ugly5;

            ++nextidx;
        }

        return tmp[index - 1];
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().GetUglyNumber_Solution(5) << endl;

    return 0;
}
