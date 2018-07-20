#include "../util.h"

using namespace std;

//更巧妙的方法是，定义两个指针，让第一个指针先走k步，然后两个指针一起走，第一个指针走到底就返回第二个指针
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k == 0)
            return nullptr;
        ListNode* tmp1 = pListHead;
        ListNode* tmp2 = pListHead;
        for(int i = 1; i < k; ++i) {
            if(tmp1->next != nullptr)
                tmp1 = tmp1->next;
            else
                return nullptr;            //防止链表长度不足以k个
        }
        while(tmp1->next != nullptr) {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        return tmp2;
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
