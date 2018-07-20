#include "../util.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == NULL) return {};
        deque<TreeNode *> q;
        q.push_back(NULL);  //用来做分行
        vector<int> curr;
        vector<vector<int>> ans;
        q.push_back(pRoot);
        bool leftToRight = true;
        while (q.size() != 1) {
            TreeNode* node = q.front();
            q.pop_front();
            if(node == NULL) {  //到了行末
                if(leftToRight == true) {//  从前完后遍历
                    deque<TreeNode *>::iterator iter;
                    for(iter = q.begin(); iter != q.end(); iter++) {
                        curr.push_back((*iter)->val);
                    }
                } else {
                    deque<TreeNode *>::reverse_iterator riter;
                    for(riter = q.rbegin(); riter < q.rend(); riter++) {
                        curr.push_back((*riter)->val);
                    }
                }
                leftToRight = !leftToRight;
                ans.push_back(curr);
                curr.clear();
                q.push_back(NULL);//添加层分隔符
                continue;//一定要continue
            }     
            if (node->left)  
                q.push_back(node->left);
            if (node->right) 
                q.push_back(node->right);
        }

        return ans;
    }  
};

int main(int argc, char const *argv[])
{
    

    return 0;
}


