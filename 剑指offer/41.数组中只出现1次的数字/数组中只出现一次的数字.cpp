#include "../util.h"

using namespace std;

// class Solution {   //其他都出现了两次，可以用异或来求解
// public:
//     void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
//         unordered_map<int, int> res;
//         for(auto &x : data) {
//             if(res.count(x) == 0) {
//                 res[x] = 1;
//             }
//             else if(res.count(x) > 0)
//                 ++res[x];
//         }
//         int num = 0;
//         for(auto &x : data) {
//             if(res[x] == 1 && num == 0) {
//                 *num1 = x;
//                 ++num;
//             } else if(res[x] == 1 && num != 0) {
//                 *num2 = x;
//                 break;
//             }
//         }

//         return;
//     }
// };
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        int res = 0;
        for(auto &x : data)
            res ^= x;

        unsigned int first1 = findFirstBitIs1(res);

        *num1 = 0, *num2 = 0;
        for(auto &x : data) {
            if(isBit1(x, first1))
                *num1 ^= x;
            else *num2 ^= x;
        }

        return;
    }
private:
    unsigned int findFirstBitIs1(int num) {
        unsigned int i = 0;
        while(((num & 1) == 0) && (i < 8 * sizeof(int))) {
            num = num >> 1;
            ++i;
        }
        return i;
    }
    bool isBit1(int num, unsigned int i) {
        num = num >> i;
        return (num & 1);
    }
};

int main(int argc, char const *argv[])
{
    int num1, num2;
    Solution().FindNumsAppearOnce({2,4,3,6,3,2,5,5}, &num1, &num2);
    cout << num1 << " " << num2 << endl;

    return 0;
}

