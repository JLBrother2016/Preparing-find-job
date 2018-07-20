#include "../util.h"

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        RandomListNode* head = pHead;
        while(head != nullptr) {            //先复制一遍老结点
            RandomListNode* newnode = new RandomListNode(head->label);
            newnode->next = head->next;
            head->next = newnode;
            head = newnode->next;
        }
        head = pHead;
        while(head != nullptr) {            //再复制随机结点
            if(head->random != nullptr) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        RandomListNode* res = pHead->next;
        RandomListNode* tmp = nullptr;
        head = pHead;
        while(head->next != nullptr) {         //分离出复制结点
            tmp = head->next;
            head->next = tmp->next;
            head = tmp;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
