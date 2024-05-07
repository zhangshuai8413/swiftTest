//
//  StringModule.hpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/8/7.
//

#ifndef StringModule_hpp
#define StringModule_hpp
#include "CPlusHeader.h"
#include <stdio.h>


class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    
    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
    
public:
    int sign = 1;
    long long ans = 0;
    
    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};




class MinString {
    /*
     给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。

     如果 s 中存在多个符合条件的子字符串，返回任意一个。

      

     注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。

      

     示例 1：

     输入：s = "ADOBECODEBANC", t = "ABC"
     输出："BANC"
     解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
     示例 2：

     输入：s = "a", t = "a"
     输出："a"
     示例 3：

     输入：s = "a", t = "aa"
     输出：""
     解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
      
     */
    
public:
    unordered_map<char, int> ori, cnt;
    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        for (const auto &c : t) {
            ++ori[c];
        }
        int l = 0, r = -1;
        int len = INT_MAX, anl = -1;
        while (r < int(s.size())) {
            if(ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if(r -l +1 < len) {
                    len = r - l +1;
                    anl = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return anl == -1 ? string()  : s.substr(anl, len);
    }
};

class SolutionCompareVersion {
    
public:
    int compareVersion(string version1, string version2) {
        int n = (int)version1.length(), m = (int)version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int x = 0;
            for (; i < n && version1[i] != '.'; ++i) {
                x = x * 10 + version1[i] - '0';
            }
            ++i; // 跳过点号
            int y = 0;
            for (; j < m && version2[j] != '.'; ++j) {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};


class SolutionMultiply {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = (int)num1.size(), n = (int)num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};



class LongestPalindrome {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
    
    
    string longestPalindromeII(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int maxlenth = 0;
        int left = 0;
        int right = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
                if (dp[i][j] && j - i + 1 > maxlenth) {
                    maxlenth = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, maxlenth);
    }
};

class KMP {
    /*
     
     给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

      

     示例 1：

     输入：haystack = "sadbutsad", needle = "sad"
     输出：0
     解释："sad" 在下标 0 和 6 处匹配。
     第一个匹配项的下标是 0 ，所以返回 0 。
     示例 2：

     输入：haystack = "leetcode", needle = "leeto"
     输出：-1
     解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
     
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/732236/shi-xian-strstr-by-leetcode-solution-ds6y/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
    
public:
    class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n = (int)haystack.size(), m = (int)needle.size();
            if (m == 0) {
                return 0;
            }
            vector<int> pi(m);
            for (int i = 1, j = 0; i < m; i++) {
                while (j > 0 && needle[i] != needle[j]) {
                    j = pi[j - 1];
                }
                if (needle[i] == needle[j]) {
                    j++;
                }
                pi[i] = j;
            }
            for (int i = 0, j = 0; i < n; i++) {
                while (j > 0 && haystack[i] != needle[j]) {
                    j = pi[j - 1];
                }
                if (haystack[i] == needle[j]) {
                    j++;
                }
                if (j == m) {
                    return i - m + 1;
                }
            }
            return -1;
        }
    };

};




class SolutionIntToRoman {

    
  
   
    /*
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/integer-to-roman/solutions/774611/zheng-shu-zhuan-luo-ma-shu-zi-by-leetcod-75rs/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */


public:
    string intToRoman(int num) {
       pair<int, string> valueSymbols[] = {
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"},
        };

        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};

class SolutionRomanToInt {
    
    /*
     示例 1:

     输入: s = "III"
     输出: 3
     示例 2:

     输入: s = "IV"
     输出: 4
     示例 3:

     输入: s = "IX"
     输出: 9
     示例 4:

     输入: s = "LVIII"
     输出: 58
     解释: L = 50, V= 5, III = 3.

     作者：力扣官方题解
     链接：https://leetcode.cn/problems/roman-to-integer/solutions/774992/luo-ma-shu-zi-zhuan-zheng-shu-by-leetcod-w55p/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


     */
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int n = (int)s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};

class SolutionDivide {
    /*
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/divide-two-integers/solutions/1041939/liang-shu-xiang-chu-by-leetcode-solution-5hic/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
public:
    int divide(int dividend, int divisor) {
        // 考虑被除数为最小值的情况
        if (dividend == INT_MIN) {
            if (divisor == 1) {
                return INT_MIN;
            }
            if (divisor == -1) {
                return INT_MAX;
            }
        }
        // 考虑除数为最小值的情况
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        // 考虑被除数为 0 的情况
        if (dividend == 0) {
            return 0;
        }
        
        // 一般情况，使用类二分查找
        // 将所有的正数取相反数，这样就只需要考虑一种情况
        bool rev = false;
        if (dividend > 0) {
            dividend = -dividend;
            rev = !rev;
        }
        if (divisor > 0) {
            divisor = -divisor;
            rev = !rev;
        }

        vector<int> candidates = {divisor};
        // 注意溢出
        while (candidates.back() >= dividend - candidates.back()) {
            candidates.push_back(candidates.back() + candidates.back());
        }
        int ans = 0;
        for (int i = (int)candidates.size() - 1; i >= 0; --i) {
            if (candidates[i] >= dividend) {
                ans += (1 << i);
                dividend -= candidates[i];
            }
        }

        return rev ? -ans : ans;
    }
    
    int divideI(int dividend, int divisor) {
        
        if(dividend==INT_MIN){
            if(divisor==1) return INT_MIN;
            else if(divisor==-1) return INT_MAX;
        }
        if(divisor==INT_MIN)
        {
            return dividend==INT_MIN?1:0;
        }
        if(dividend==0) return 0;
        if(divisor==1) return dividend;
        if(divisor==-1) return -dividend;
        
        
        int sign = 1;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            sign = -1;
        }
        int result = 0;
        long dividend_long = abs((long)dividend);
        long divisor_long = abs((long)divisor);
        while (dividend_long >= divisor_long) {
            long i = 1;
            long temp = divisor_long;
            while (dividend_long >= temp) {
                dividend_long -= temp;
                result += i;
                i = i << 1;
                temp = temp << 1;
            }
        }
        result *= sign;
        if (result > INT_MAX || result < INT_MIN) {
            return INT_MAX;
        }
        
        return int(result);
    }
};

/*
 
 作者：力扣官方题解
 链接：https://leetcode.cn/problems/group-anagrams/solutions/520469/zi-mu-yi-wei-ci-fen-zu-by-leetcode-solut-gyoc/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ans.emplace_back(it->second);
    }
    return ans;
}


/*
 作者：力扣官方题解
 链接：https://leetcode.cn/problems/count-and-say/solutions/1047325/wai-guan-shu-lie-by-leetcode-solution-9rt8/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
string countAndSay(int n) {
      string prev = "1";
      for (int i = 2; i <= n; ++i) {
          string curr = "";
          int start = 0;
          int pos = 0;

          while (pos < prev.size()) {
              while (pos < prev.size() && prev[pos] == prev[start]) {
                  pos++;
              }
              curr += to_string(pos - start) + prev[start];
              start = pos;
          }
          prev = curr;
      }
      
      return prev;
  }

class SolutionFindSubstring {
    /*
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/substring-with-concatenation-of-all-words/solutions/1616997/chuan-lian-suo-you-dan-ci-de-zi-chuan-by-244a/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        vector<int> res;
        int m = (int)words.size(), n = (int)words[0].size(), ls = (int)s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string &word: words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};


vector<int> findSubstringII(string s, vector<string>& words) {
        vector<int> res;
        // 设 words中所有单词的长度为 d
        int n = s.size(), m = words.size(), d = words[0].size();
        int len = 0;
        unordered_map<string, int> um;
        for (string w : words) {
            len += w.size();
            um[w]++;
        }

        // init: 初始化长度为 d 的数组
        vector<unordered_map<string, int> > vu(d);
        for (int i = 0; i < d && i + len <= n; i++) {
            for (int j = i; j < i + len; j += d) {
                string w = s.substr(j, d);
                vu[i][w]++;
            }
            if (vu[i] == um) {
                res.emplace_back(i);
            }
        }

        // sliding window: 滑动窗口，每次移动 d 个位置
        for (int i = d; i + len <= n; i++) {
            int r = i % d;
            string wa = s.substr(i - d, d), wb = s.substr(i + len - d, d);
            if(--vu[r][wa] == 0) vu[r].erase(wa);
            vu[r][wb]++;
            if (vu[r] == um) {
                res.emplace_back(i);
            }
        }

        return res;
    }



/*
 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

 在 S 上反复执行重复项删除操作，直到无法继续删除。

 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 示例：

 输入："abbaca"
 输出："ca"
 解释：例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 提示：

 1 <= S.length <= 20000
 S 仅由小写英文字母组成
 */

string removeDuplicates(string S) {
    string result;

    for(char s : S) {
        if(result.empty() || result.back() != s) {
            result.push_back(s);
        }
        else {
            result.pop_back();
        }
    }
    return result;
}


/* 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
 
 字母和数字都属于字母数字字符。

 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

  

 示例 1：

 输入: s = "A man, a plan, a canal: Panama"
 输出：true
 解释："amanaplanacanalpanama" 是回文串。
 示例 2：

 输入：s = "race a car"
 输出：false
 解释："raceacar" 不是回文串。
 示例 3：

 输入：s = " "
 输出：true
 解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
 由于空字符串正着反着读都一样，所以是回文串。
  */

bool isPalindrome(string s) {
    string sgood;
    for (char ch: s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend());
    return sgood == sgood_rev;
}


class ZSolution {
    /*
     
     将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

     比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

     P   A   H   N
     A P L S I I G
     Y   I   R
     之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

     请你实现这个将字符串进行指定行数变换的函数：

     string convert(string s, int numRows);
      

     示例 1：

     输入：s = "PAYPALISHIRING", numRows = 3
     输出："PAHNAPLSIIGYIR"
     示例 2：
     输入：s = "PAYPALISHIRING", numRows = 4
     输出："PINALSIGYAHRPI"
     解释：
     P     I    N
     A   L S  I G
     Y A   H R
     P     I
     示例 3：

     输入：s = "A", numRows = 1
     输出："A"
     
     
     作者：Krahets
     链接：https://leetcode.cn/problems/zigzag-conversion/solutions/21610/zzi-xing-bian-huan-by-jyd/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

     */
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows -1)
                flag = - flag;
            i += flag;
        }
        string res;
        for (const string &row : rows)
            res += row;
        return res;
    }
};


string addBinary(string a, string b) {
    string ans = "";
    int carry = 0;
    int i = (int)a.length() - 1;
    int j = (int)b.length() - 1;
    while (i >= 0 || j >= 0 ||  carry !=0) {
        int a1 = i >=0 ? a[i--] - '0' : 0;
        int b1 = j >=0 ? b[j--] - '0' : 0;
        int sum = a1 + b1 + carry;
        ans = to_string(sum % 2) + ans;
        carry = sum / 2;
    }
    
    return ans ;
}

class SolutionFullJustify {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

    vector<string> result;
    int i = 0;
    
    while (i < words.size()) {
        int j = i + 1;
        int lineLength = (int)words[i].size();
        
        // 尽可能多地加入单词，直到达到 maxWidth 或没有更多单词为止
        while (j < words.size() && lineLength + words[j].size() + 1 <= maxWidth) {
            lineLength += words[j].size() + 1;
            j++;
        }
        
        int extraSpaces = maxWidth - lineLength  ;
        int numberOfWords = j - i;
        
        // 构建当前行的字符串
        string line = words[i];
        
        if (numberOfWords == 1 || j == words.size()) {
            // 如果是一行只有一个单词或者是最后一行，左对齐
            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }
            line += string(maxWidth - line.size(), ' '); // 填充额外的空格
        } else {
            // 计算额外的空格需要分配给单词之间的间隔
            int spacesBetweenWords = extraSpaces / (numberOfWords - 1);
            int extraSpacesLeft = extraSpaces % (numberOfWords - 1);
            
            for (int k = i + 1; k < j; k++) {
                line += string(spacesBetweenWords + 1, ' ');
                if (extraSpacesLeft > 0) {
                    line += ' ';
                    extraSpacesLeft--;
                }
                line += words[k];
            }
        }
        
        result.push_back(line);
        i = j;
    }
    
    return result;
    }
};

class SolutionFindAnagrams {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = (int)s.size(), pLen = (int)p.size();
        if (sLen < pLen) {
            return {};
        }
        
        std::vector<int> ans;
        std::vector<int> pCount(26, 0), sCount(26, 0);
        
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }
        
        if (sCount == pCount) {
            ans.push_back(0);
        }
        
        for (int i = pLen; i < sLen; ++i) {
            --sCount[s[i - pLen] - 'a'];
            ++sCount[s[i] - 'a'];
            
            if (sCount == pCount) {
                ans.push_back(i - pLen + 1);
            }
        }
        
        return ans;
        
    }
};

/*
 有效数字（按顺序）可以分成以下几个部分：

 一个 小数 或者 整数
 （可选）一个 'e' 或 'E' ，后面跟着一个 整数
 小数（按顺序）可以分成以下几个部分：

 （可选）一个符号字符（'+' 或 '-'）
 下述格式之一：
 至少一位数字，后面跟着一个点 '.'
 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
 一个点 '.' ，后面跟着至少一位数字
 整数（按顺序）可以分成以下几个部分：

 （可选）一个符号字符（'+' 或 '-'）
 至少一位数字
 部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]

 部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]

 给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
 */

class iSNumber {
    
public:
    bool isNumber(string s) {
        int n = (int)s.length();
        int left = 0, right = n - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right --;
        if (left > right) {
            return false;
        }
        bool seen_digit = false;
        bool seen_dot = false;
        bool seen_e = false;
        
        for (int i= left; i<= right; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                seen_digit = true;
            } else if (c == '.') {
                if (seen_dot || seen_e) return false;
                seen_dot = true;
            } else if (c == 'e' || c == 'E') {
                if (seen_e || !seen_digit) return false;
                seen_e = true;
                seen_digit = false;
            } else if (c == '+' || c == '-') {
                if (i > left && s[i -1] != 'e' && s[i-1] != 'E') return false;
            } else {
                return false;
            }
        }
        return seen_digit;
    }
};

class SimplifyPathCPlus {
public:
    vector<string> splitString(const string& s, char delimiter) {
        vector<string>tokens;
        istringstream iss(s);
        string token;
        while (getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    string simplifyPath(string path) {
        
        vector<string> components = splitString(path, '/');
        
        stack<string> stack;
        
        for (int i=0; i< (int)components.size() - 1; ++i) {
            string s =  components[i];
            if (s == " " && s == ".") {
                continue;
            } else if (s == "..") {
                stack.pop();
            } else {
                stack.push(s);
            }
        }

        // 1 2 3 4 5
        
//      3 4 5
        string result  = "/";
        while (!stack.empty()) {
            result = "/" + stack.top() + result;
        }
        return "";
    }
};
#endif /* StringModule_hpp */
