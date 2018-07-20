#include "../util.h"

using namespace std;

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) 
            return pHead;

        ListNode *pre = pHead;          //需要两个临时变量
        ListNode *last = pHead;

        while(pHead->next != nullptr) {         //头插法
            last = pHead->next;
            pHead->next = last->next;
            last->next = pre;
            pre = last;
        }

        return pre;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

