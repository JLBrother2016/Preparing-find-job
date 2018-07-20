#include "../util.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr) 
            return pHead;   //只有0个或1个结点，则直接返回
        if(pHead->val == pHead->next->val) {//当前结点是重复结点
            ListNode* node = pHead->next;
            while(node != nullptr && node->val == pHead->val)
                node = node->next;
            // 跳过值与当前结点相同的全部结点, 找到第一个不同的结点
            return deleteDuplication(node); //从第一个与当前不同的结点开始递归
        } else {    //当前结点不是重复结点
            pHead->next = deleteDuplication(pHead->next);
            //保留当前结点，从下一个结点开始递归

            return pHead;
        }

        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

