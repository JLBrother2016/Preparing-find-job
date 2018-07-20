#include "../util.h"

using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int blankNumber = 0;//空格的数量
        int oldstringLen;
        //首先遍历原字符串，找出字符串的长度以及其中的空格数量
        for (oldstringLen = 0; str[oldstringLen] != '\0'; oldstringLen++){

            if (str[oldstringLen] == ' ')
                blankNumber++;
        }
        int newstringLen = oldstringLen + blankNumber * 2;//新字符串的长度
        if (newstringLen > length)
            return;
        str[newstringLen] = '\0';//此行很重要，因为原字符串最后一个字符为'\0'
        
        int point1 = oldstringLen - 1, point2 = newstringLen - 1;
        
        while(point1 >= 0 && point2 > point1){
            if(str[point1] == ' '){
                str[point2--] = '0';
                str[point2--] = '2';
                str[point2--] = '%';
            } else{
                str[point2--] = str[point1];
            }
            point1--;
        }
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
