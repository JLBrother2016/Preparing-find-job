#include "util.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        RandomListNode* head = pHead;
        while(head != nullptr) {
            RandomListNode* newnode = new RandomListNode(head->label);
            newnode->next = head->next;
            head->next = newnode;
            head = newnode->next;
        }
        head = pHead;
        while(head != nullptr) {
            if(head->random != nullptr) {
                head->next->random = head->random->next;
            } else {
                head->next->random = nullptr;
            }
            head = head->next->next;
        }
        RandomListNode* res = pHead->next;
        RandomListNode* tmp = res;
        head = pHead;
        while(head->next != nullptr) {
            head->next = tmp->next;
            head = tmp->next;
            tmp->next = head->next;
            tmp = head->next;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    


    return 0;
}

