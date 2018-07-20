#include "../util.h"

using namespace std;

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        
    }
    TreeNode* Deserialize(char *str) {
    
    }
};

class Solution {
public:
    /*  序列化二叉树  */
    char* Serialize(TreeNode *root) {
        if(root == NULL) {
            char *serial = new char[3];
            strcpy(serial, "#,");
            return serial;
        }

        string str;
        Serialize(root, str);

        const char  *c_str = str.c_str( );
        char        *serial = new char[str.length( ) + 1];
        strcpy(serial, c_str);

        return serial;
    }

    TreeNode* Deserialize(char *str) {
        if(str == NULL|| *str == '\0') {
            return NULL;
        }

        int index = 0;

        return Deserialize(str, index);
    }

private :
    void Serialize(TreeNode *root, string &str) {
        if(root == NULL) {
            str += "#,";
            return;
        }
        /*  先序遍历的方式, 序列化二叉树  */
        str += (toString(root->val) + ",");
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
    /*  反序列化二叉树
     *  将一个序列化的字符串转换成二叉树  */
    TreeNode* Deserialize(char *str, int &index) {
        if(str[index] == '#') {
            index += 2;
            return NULL;
        }
        /*  获取到节点的数字权值  */
        int num = 0;
        while(str[index] != ',' && str[index] != '\0') {
            num = num * 10 + (str[index] - '0');
            index++;
        }
        index++;

        TreeNode *root = new TreeNode(num);
        root->left = Deserialize(str, index);
        root->right = Deserialize(str, index);

        return root;
    }

    string toString(int num) {
        stringstream ss;
        ss <<num;
        return ss.str( );
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}


