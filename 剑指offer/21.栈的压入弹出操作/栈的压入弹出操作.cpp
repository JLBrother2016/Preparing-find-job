#include "../util.h"

using namespace std;

// 用一个辅助栈来模拟, 找到栈弹出的数就弹出，否则压栈，
// 直到和弹出栈的数字相同, 如果所有的数字都压栈完了，
// 还是没有的话证明不是弹出栈的顺序
class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if(pushV.size() == 0 || pushV.size() != popV.size()) //特殊情况处理
            return false;
        stack<int> s;
        s.push(pushV[0]);
        for(size_t push = 0, pop = 0; push < pushV.size(),
                                      pop < popV.size(); ) {
            if(s.empty() != true && s.top() == popV[pop]) {
                s.pop();        //有元素, 并且等于另一个序列的值, 则弹出栈顶的元素
                ++pop;
            } else {            //不同则压入栈中
                s.push(pushV[++push]);
            }
        }

        return s.empty() ? true : false;
    }
};


int main(int argc, char const *argv[])
{
    

    return 0;
}
