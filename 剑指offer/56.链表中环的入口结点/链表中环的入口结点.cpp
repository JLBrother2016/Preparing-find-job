#include "../util.h"

using namespace std;

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;
        ListNode* meetingNode = hasCycle(pHead);
        if(meetingNode == nullptr)
            return nullptr;

        int cycleLength = getCycleLength(meetingNode);

        ListNode* leftNode = pHead;
        ListNode* rightNode = pHead;
        rightNode = nextNode(rightNode, cycleLength);
        while(leftNode != rightNode) {
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }

        return leftNode;
    }
private:
    ListNode* nextNode(ListNode* node, int step) {
        for(int i = 0; i < step && node != nullptr; ++i) {
            node = node->next;
        }
        return node;
    }
    //获得链表中环的长度
    int getCycleLength(ListNode* node) {
        int length = 0;
        if(node == nullptr) {
            return length;
        }
        // 考虑环内, 从任何一个结点出现再回到这个结点的长度为环的长度
        ListNode* currentNode = node;
        ListNode* stepNode = node->next;

        for(int length = 1; ; ++length) {
            if(stepNode == currentNode)
                return length;
            stepNode = stepNode->next;
        }
    }
    ListNode* hasCycle(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;

        ListNode* pSlow = pHead->next;
        ListNode* pFast = pSlow->next;
        while(pSlow != nullptr && pFast != nullptr) {
            if(pSlow == pFast)
                return pSlow;
            pSlow = nextNode(pSlow, 1);
            pFast = nextNode(pFast, 2);
        }

        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}


