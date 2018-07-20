#include "../util.h"

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, int size) {
        if(num.size() == 0)
            return {};
        else if(size == 0) {
            int ans = INT_MIN;
            for(int &x : num) 
                ans = max(ans, x);
            return {ans};
        }
        int len = num.size();
        vector<int> ans;
        for(int i = 0; i <= len - size; ++i) {
            int temp = INT_MIN;
            for(int j = i; j < i + size; ++j) {
                temp = max(temp, num[j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//     {
//         vector<int> res;
//         deque<int> s;
//         for(unsigned int i=0;i<num.size();++i){
//             while(s.size() && num[s.back()]<=num[i])//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
//                 s.pop_back();
//             while(s.size() && i-s.front()+1>size)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
//                 s.pop_front();
//             s.push_back(i);//把每次滑动的num下标加入队列
//             if(size&&i+1>=size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
//                 res.push_back(num[s.front()]);
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if(num.size() == 0 || size == 0) {
            return res;
        }

        for(int start = 0;
            start <= (int)(num.size( ) - size);
            start++) {
            int end = start + size;
            int max = INT_MIN;
            for(int index = start; index < end; index++) {
                if(num[index] > max) {
                    max = num[index];
                }
            }

            res.push_back(max);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> tm{2,3,4,2,6,2,5,1};
    cout << Solution().maxInWindows(tm, 3) << endl;

    return 0;
}


