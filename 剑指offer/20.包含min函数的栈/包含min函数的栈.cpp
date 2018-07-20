#include "../util.h"

class Solution {
public:
    void push(int value) {
        if(elements.empty()) {
            elements.push(value);
            elements.push(value);
        } else {
            int min = elements.top();
            elements.pop();
            elements.push(value - min);
            elements.push(value < min ? value : min);
        }
        
    }
    void pop() {
        int min = elements.top();
        elements.pop();
        int diff = elements.top();
        elements.pop();
        if(diff < 0) {
            elements.push(min - diff);
        } else {
            if(!elements.empty()) {
                elements.push(min);
            }
        }
    }
    int top() {
        int ans = 0;
        int min = elements.top();
        elements.pop();
        int diff = elements.top();
        if(diff > 0) {
            ans = min + diff;
        } else ans = min;
        elements.push(min);

        return ans;
    }
    int min() {
        if(elements.empty())
            return -1;
        return elements.top();
    }

private:
    stack<int> elements;
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}


