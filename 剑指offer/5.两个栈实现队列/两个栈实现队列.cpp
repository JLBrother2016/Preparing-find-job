#include "../util.h"

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);          //只用了一次拷贝操作
        // cout << "stack1.size: " << stack1.size() << endl;
    }

    int pop() {
        if(stack1.empty() && stack2.empty()) 
            return -1;
        int ans;
        if(!stack2.empty()) {
            // cout << "stack2.size: " << stack2.size() << endl;
            ans = stack2.top();
            stack2.pop();
        } else {
            // cout << "first" << endl;
            while((int)stack1.size() > 1) {
                // cout << "i: " << i << stack1.size() << endl;
                stack2.push(stack1.top());
                stack1.pop();
            }
            ans = stack1.top();
            stack1.pop();
        }

        return ans;
    }

private:
    stack<int> stack1;      //做存储
    stack<int> stack2;
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
