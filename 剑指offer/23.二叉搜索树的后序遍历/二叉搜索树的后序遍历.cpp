#include "../util.h"

using namespace std;

class Solution {
public:
    ///  后序是 左右根
    ///  那么我们的节点
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.size() == 0) {
            return false;
        }
        int max = 0;
        stack<int> s;            //利用一个辅助栈
        int it = sequence.size() - 1;    //找到根的位置
        do {
            s.push(sequence[it]);
            it--;
        }while(it >= 0 && sequence[it] > sequence[it + 1]);    
        //搜索二叉树就是右子树比根节点更大

        max = s.top();

        for(;it >= 0; --it) {
            // cout <<"curr = " <<sequence[it] <<", max = " <<max <<endl;

            if(max < sequence[it]) { //  前面有元素比最大值还大，肯定不满足要求
                return false;
            }

            while(s.empty() != true && s.top() > sequence[it]) {
                max = s.top();
                // cout <<"max = " <<max <<endl;
                s.pop();
            }
            s.push(sequence[it]);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
