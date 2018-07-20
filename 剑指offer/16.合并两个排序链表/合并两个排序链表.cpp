#include "../util.h"

using namespace std;

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr && pHead2 == nullptr)
            return nullptr;
        if(pHead1 == nullptr && pHead2)
            return pHead2;
        if(pHead1 && pHead2 == nullptr)     //特殊情况处理
            return pHead1;

        ListNode *res = pHead1->val > pHead2->val ? pHead2 : pHead1; //找到小的链表头部
        ListNode *ans = res;
        while(pHead1 && pHead2) {
            if(pHead1->val > pHead2->val) {  //比较头结点的值
                res = pHead2;
                pHead2 = pHead2->next;
            } else {
                res = pHead1;
                pHead1 = pHead1->next;
            }
            if(pHead1 && pHead2)            //更改了原链表的顺序
                res->next = pHead1->val > pHead2->val ? pHead2 : pHead1;   
        }

        if(pHead1 == nullptr) { //到phead1的尾部直接连接上剩余的结点就可以了
            res->next = pHead2;
        } else if(pHead2 == nullptr) {
            res->next = pHead1;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
