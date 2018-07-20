#include "../util.h"

using namespace std;

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        if(head == nullptr)
            return {};
        vector<int> ans;
        stack<int> tmp;
        ListNode* node = head;
        while(node) {
            tmp.push(node->val);
            node = node->next;
        }
        while(tmp.size()) {
            ans.push_back(tmp.top());
            tmp.pop();
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
