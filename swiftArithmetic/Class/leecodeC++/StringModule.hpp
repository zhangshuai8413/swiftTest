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
                    --cnt[s[len]];
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



#endif /* StringModule_hpp */
