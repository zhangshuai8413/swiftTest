//
//  FFList.cpp
//  suanfaC++
//
//  Created by 张帅 on 2023/5/1.
//

#include "FFList.hpp"

ListNode * addTwo(ListNode *l1, ListNode *l2) {
    int carray = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (l1 != nullptr || l2 != nullptr || carray != 0) {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        int sum = a + b + carray;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
        carray = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    return dummy->next;
}

ListNode *reverse(ListNode *head) {
    if (head == nullptr ){
        return  head;
    }
    ListNode *pre = nullptr;
    ListNode *temp = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
        temp = current->next;
        current->next = pre;
        pre = current;
        current = temp;
    }
    return pre;
}

vector<int> twoSum(vector<int> & nums, int target) {
    unordered_map<int, int> map;
    for (int i=0; i< nums.size(); ++i) {
        auto it = map.find(target - nums[i]);
        if (it != map.end()) {
            return {it-> second, i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int lengthOfLongestSubstring(string s) {
    int len = 0;
    int left = 0;
    unordered_map<char, int> map;
    for (int i=0; i< s.size(); ++i) {
        auto it = map.find(s[i]);
        if (it != map.end()) {
            left = max(left,it-> second + 1);
        }
        len = max(len, i - left + 1);
        map[s[i]] = i;
    }
    return len;
}

int lengthOfLongestSubstring1(string s) {
    int len = 0;
    int left = 0;
    vector<int> map(128, -1);
    for (int i=0; i< s.size(); ++i) {
        if (map[s[i]]!= -1) {
            left = max(left, map[s[i]] + 1);
        }
        len = max(len, i - left + 1);
        map[s[i]] = i;
    }
    return len;
}

bool isValid(string s) {
    unordered_map<char, char> map = {{']','['},{'}','{'},{')','('}};
    stack<char> stack;
    int size = (int)s.size();
    if (size % 2 != 0 || size == 0){
        return false;
    }
    for (char ch: s) {
        if (map.count(ch)) {
            if (stack.empty() || stack.top() != map[ch]) {
                return false;
            }
            stack.pop();
        } else {
            stack.push(ch);
        }
    }
    return stack.empty();
}

int reverse(int x) {
    int res = 0;
    while (x != 0) {
        if (res >  INT_MAX / 10 || res < INT_MIN / 10) {
            return 0;
        } else {
            int dig = x % 10;
            res = res * 10  + dig;
            x = x / 10;
        }
    }
    return res;
}


string longestCommonPrefix(string str1, string str2) {
    int minLenght = (int)min(str1.length(), str2.length());
    for (int i=0; i< minLenght; ++i) {
        if (str1[i] != str2[i]) {
            return str1.substr(0, i);
        }
    }
    return str1.substr(0, minLenght);
}

string longestCommonPrefix(vector<string>& strs, int start, int end) {
    if (start == end) {
        return strs[start];
    }
    int mid = start + (end - start)/ 2;
    string string1 = longestCommonPrefix(strs, start,mid);
    string string2 = longestCommonPrefix(strs, mid + 1,end);
    return longestCommonPrefix(string1, string2);
}

string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) {
        return "";
    } else {
        return longestCommonPrefix(strs, 0, (int)strs.size() -1);
    }
}

//  123321
bool isPalindrome(int x) {
    if (x < 0 || (x % 10 ==0 && x != 0)) {
        return  false;
    }
    
    int ret  = 0;
    while (x > ret) {
        ret = ret * 10 + x %10;
        x /=10;
    }
    return ret == x || x == ret / 10;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = head;
    ListNode *slow = dummy;
    for (int i=0; i< n; ++i) {
        fast = fast->next;
    }
    if (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);;
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = (int)nums.size();
    for (int i=0; i< n; ++i) {
        unordered_set<int> set;
        if (nums[i] > 0) {
            break;
        }
        if (i > 0 && nums[i] == nums[i -1]) {
            continue;
        }
        for (int j= i + 1; j< n; ++j) {
            if (j > i + 2 && nums[j] == nums[j-1] && nums[j -1] == nums[j-2] ) {
                continue;
            }
            int a = nums[i];
            int b = nums[j];
            int c = -(a + b);
            if (set.find(c) != set.end()) {
                result.push_back({a,b,c});
                set.erase(c);
            } else {
                set.insert(b);
            }
        }
    }
    return result;
}


string longestPalindrome(string s) {
    int n = (int)s.size();
    if (n < 2) {
        return s;
    }
    int maxLen = 1;
    int begin = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int L=2; L<= n; L++) {
        for (int i=0; i< n; i++) {
            int j = L + i - 1;
            if (j >=n) {
                break;;
            }
            if (s[i] != s[j]) {
                dp[i][j] = false;
            } else {
                if (j -i < 3) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] && j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}



int maxArea(vector<int>& height) {
    int l = 0, r = (int)height.size() - 1;
    int ans = 0;
    while (l < r) {
        int are = min(height[l], height[r])*(r - l);
        ans = max(ans, are);
        if (height[l]<= height[r]) {
            ++ l;
        }else {
            --r;
        }
    }
    return ans;
}
