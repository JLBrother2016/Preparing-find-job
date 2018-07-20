#include "../util.h"

using namespace std;

// (a) 把长度为4的数组分解成两个长度为2的子数组；
// (b) 把长度为2的数组分解成两个成都为1的子数组；
// (c) 把长度为1的子数组 合并、排序并统计逆序对 ；
// (d) 把长度为2的子数组合并、排序，并统计逆序对；
class Solution {      //逆序对的题目用归并排序的算法来求解
public:
    int InversePairs(vector<int> data) {
        int len = data.size();
        if(len <= 0)
            return 0;
        vector<int> copy(data.begin(), data.end());
        // for(int i = 0; i < len; ++i)
        //     copy.push_back(data[i]);

        long long ans = InversePairs(data, copy, 0, len - 1);
        return ans % 1000000007;
    }
private:                //归并排序利用的是分治的思想(分而治之)
    long long InversePairs(vector<int> &data, 
                           vector<int> &copy,
                           int begin, int end) {
        if(begin == end) {
            copy[begin] = data[begin];  //数组中只有一个元素了
            return 0;
        }

        int len = (end - begin) / 2;    //每次讲数组一分为二
        //数组的左边
        long long left = InversePairs(copy, data, begin, begin + len); 
        // 数组的右边
        long long right = InversePairs(copy, data, begin+len+1, end);

        int i = begin + len;
        int j = end;
        int indexcopy = end;
        long long count = 0;
        while(i >= begin && j >= begin + len + 1) {
            if(data[i] > data[j]) {
                copy[indexcopy--] = data[i--];
                count = count + j - begin - len;    //统计逆序对
            } else {
                copy[indexcopy--] = data[j--];
            }
        }

        for(; i >= begin; i--)
            copy[indexcopy--] = data[i];
        for(; j >= begin + len + 1; j--)
            copy[indexcopy--] = data[j];

        return left + right + count;    //合并统计的逆序对
    }
};


int main(int argc, char const *argv[])
{
    cout << Solution().InversePairs({1,2,3,4,5,6,7,0}) << endl;

    return 0;
}
