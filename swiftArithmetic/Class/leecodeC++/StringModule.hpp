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
class SolutionIntToRoman {
public:

   
    /*
     作者：力扣官方题解
     链接：https://leetcode.cn/problems/integer-to-roman/solutions/774611/zheng-shu-zhuan-luo-ma-shu-zi-by-leetcod-75rs/
     来源：力扣（LeetCode）
     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     */


public:
    string intToRoman(int num) {
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




#endif /* StringModule_hpp */
