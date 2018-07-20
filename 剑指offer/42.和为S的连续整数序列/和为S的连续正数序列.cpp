#include "../util.h"

using namespace std;

// class Solution {
// public:              //这是利用一般思路求解，即每次移动一位数
//     vector<vector<int> > FindContinuousSequence(int sum) {
//         if(sum < 3)
//             return {};
//         vector<vector<int>> ans;
//         int small = 1;
//         int big = 2;
//         int mid = (1 + sum) / 2;
//         int cursum = small + big;
//         while(small < mid) {
//             if(cursum == sum) {
//                 vector<int> tmp;
//                 printAns(tmp, small, big);
//                 ans.push_back(tmp);
//             }
//             while(cursum > sum && small < mid) {
//                 cursum -= small;
//                 ++small;
//                 if(cursum == sum) {
//                     vector<int> tmp;
//                     printAns(tmp, small, big);
//                     ans.push_back(tmp);
//                 }
//             }
//             ++big;
//             cursum += big;
//         }

//         return ans;
//     }
// private:
//     void printAns(vector<int>& ans, int small, int big) {
//         for(int i = small; i <= big; ++i) {
//             ans.push_back(i);
//         }
//     }
// };
class Solution {
public:         //利用等比数组的思路求解
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum < 3)
            return {};
        vector<vector<int>> ans;
        for(int n = sqrt(2 * sum); n >= 2; --n) {
            if(((n & 1) && (sum % n == 0)) || ((sum % n) * 2 == n)) {
                vector<int> tmp;
                for(int count = 0, i = (sum / n) - (n -1) / 2;
                    count < n; ++count, ++i)
                    tmp.push_back(i);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().FindContinuousSequence(100) << endl;

    return 0;
}
