#include "../util.h"

using namespace std;

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr)
            return 0;
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        if(len1 > len2) {
            for(int i = 0; i < len1 - len2; ++i) 
                pHead1 = pHead1->next;
        } else if(len2 > len1) {
            for(int i = 0; i < len2 - len1; ++i)
                pHead2 = pHead2->next;
        }

        while(pHead1 && pHead2) {
            if(pHead1->val == pHead2->val) {
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return nullptr;
    }
private:
    int getLength(ListNode* head) {
        if(head == nullptr)
            return 0;
        ListNode* node = head;
        int len = 0;
        while(node) {
            ++len;
            node = node->next;
        }

        return len;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

