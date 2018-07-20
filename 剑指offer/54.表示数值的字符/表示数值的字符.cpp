#include "../util.h"

using namespace std;

// class Solution {
// public:
//     bool isNumeric(char* string) {
//         if(string == nullptr)
//             return false;
//         if(*string == '+' || *string == '-')
//             ++string;
//         if(*string == '\0')
//             return false;
//         bool numberic = true;
//         // 处理可能遇见的数字
//         ScanDigits(&string);

//         if(*string != '\0') {
//             if(*string == '.') {
//                 ++string;
//                 ScanDigits(&string);

//                 if(*string == 'e' || *string == 'E')
//                 {
//                     numberic = IsExponential(&string);
//                 }
//             }
//             else if(*string == 'e' || *string == 'E') {
//                 numberic = IsExponential(&string);
//             }
//             else {
//                 // cout << "jjj" << endl;
//                 numberic = false;
//             }
//         }
//         // cout << numberic << endl;
//         return numberic && *string == '\0';
//     }
// private:
//     void ScanDigits(char **str) {
//         while(**str != '\0' && (**str >= '0' && **str <= '9')) {
//             ++(*str);
//         }
//     }

//     bool IsExponential(char **str) {
//         if(**str != 'e' && **str != 'E') {
//             return false;
//         }

//         ++(*str);

//         if(**str == '+' || **str == '-') {
//             ++(*str);
//         }
//         if(**str == '\0') {
//             return false;
//         }
//         ScanDigits(str);

//         return (**str == '\0') ? true : false;
//     }
// };

class Solution {
public:
    bool isNumeric(char* string) {
        if(string == nullptr)
            return false;
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        for(int i = 0; i < strlen(string); ++i){ //strlen不会主动加上'/0'
            if('e' == string[i] || 'E' == string[i]) {
                if(i == strlen(string)-1)
                    return false;   //e后面一定要接数字
                if(hasE) return false;
                hasE = true;    //不能同时出现两个E
            } else if(string[i] == '+' || string[i] == '-') {
                // 第二次出现+-号, 则必须紧接在e之后
                if(sign && string[i-1] != 'e' && string[i] != 'E')
                    return false;
                if(!sign && i > 0 && string[i-1] != 'e' && string[i-1] != 'E')
                    return false; //第一次出现+-符号,且不是在字符串开头，则也必须紧接在e之后
                sign = true;
            } else if(string[i] == '.') {
                // e后面不能解小数点，小数点不能出现两次
                if(hasE || decimal)
                    return false;
                decimal = true;
            } else if(string[i] < '0' || string[i] > '9') {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().isNumeric("100") << endl;

    return 0;
}

