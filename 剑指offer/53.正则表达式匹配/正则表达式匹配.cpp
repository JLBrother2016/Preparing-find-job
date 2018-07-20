#include "../util.h"

using namespace std;
// 分治–类似与深度优先搜索DFS
class Solution {
public:
    bool match(const char *s, const char *p) {
        if (*p == '\0') {        //  正则p到底末尾时
            return !(*s);       //  如果串s页到达末尾，则匹配成功
        }

        int slen = strlen(s), plen = strlen(p);

        if (plen == 1 || *(p + 1) != '*') {           //  如果正则串只有一个长度
                        //  如果匹配* //
            return slen && (p[0] == '.' || *s == *p)
                && match(s + 1, p + 1);
        }
        else {
            //  匹配一个字符
            while (*s != '\0' && (*p == '.' || *s == *p)) {
                if (match(s++, p + 2)) {
                    return true;
                }
            }
        }
        //  匹配0个字符
        return match(s, p + 2);
    }
};

class Solution {
public:
    bool match(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

        return f[m][n];
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}

