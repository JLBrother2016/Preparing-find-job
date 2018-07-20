#include "../til.h"
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.size() == 0) 
            return ans;
        Permutation(str, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
private:        //这种方法无法移出重复的排列；基于前缀码的全排列
    void Permutation(string prefix, string str, vector<string>& ans) {
        if(str.length() == 0) {
            ans.push_back(prefix);
        } else {
            for(int i = 0; i < str.length(); ++i) {
                Permutation(prefix + str[i], str.substr(0, i) + str.substr(i+1, str.length()), ans);         //分为第i-th个元素和剩余子串部分
            }
        }
    }           //这种方法是基于交换的全排列
    void Permutation(string str, int idx, vector<string>& ans) {
        if(str[idx] == '\0') {
            ans.push_back(str);
        } else {
            for(int i = idx; str[i] != '\0'; ++i) {
                if(i == idx || str[i] != str[idx]) {
                    swap(str[i], str[idx]);
                    Permutation(str, idx + 1, ans);
                    swap(str[i], str[idx]);
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
