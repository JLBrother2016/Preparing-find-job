#include "../util.h"

using namespace std;

// class Solution {
// public:
//     string ReverseSentence(string str) {
//         int len = str.length();
//         if(len == 0)
//             return "";
//         int start = 0, end = len - 1;
//         // 先翻转整个句子
//         reverseWord(str, start, end);
//         // cout << str << endl;
//         start = 0, end = 0;
//         bool flag = false;
//         str += " ";

//         while(str[end] != '\0') {
//             if(str[start] == ' ') {
//                 ++start;
//                 ++end;
//             } else if(str[end] == ' ' || str[end] == '\0') {
//                 reverseWord(str, start, --end);
//                 start = ++end;
//                 flag = true;
//             } else ++end;
//         }
            
//         return str.substr(0, len);
//     }
// private:
//     void reverseWord(string& word, int start, int end) {
//         int len = word.length();
//         if(len == 0)
//             return;
//         while(end > start) {
//             swap(word[start], word[end]);
//             ++start;
//             --end;
//         } 
//     }
// };
class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        if(len == 0)
            return "";
        else if(str[0] == ' ')
            return str;
        vector<string> tmp;
        string ans;
        const char * split = " "; 
        char * p; 
        p = strtok (const_cast<char*>(str.c_str()), split); 
        while(p != NULL) { 
            tmp.push_back(p);
            // printf ("%s\n", p); 
            p = strtok(NULL, split); 
        }
        for(int i = tmp.size() - 1; i >= 0; --i) {
            ans += tmp[i];
            ans += " ";
        }    
        return ans.substr(0, str.length());
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().ReverseSentence("hello world!") << endl;
    // char str[] ="a,b,c,d*e"; 
    // const char * split = ","; 
    // char * p; 
    // p = strtok (str,split); 
    // while(p!=NULL) { 
    //     printf ("%s\n",p); 
    //     p = strtok(NULL,split); 
    // } 
    // getchar();


    return 0;
}

