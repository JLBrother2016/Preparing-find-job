#include "../uitl.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>> ans;
    if(pRoot == nullptr)
        return ans;
        queue<TreeNode *> q;
        TreeNode *curr;
        q.push(pRoot);
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for(int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                tmp.push_back(curr->val);
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
                q.pop();
            } 
            ans.push_back(tmp); 
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{


    return 0;
}

