//
//  DoublePointer.hpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/8/19.
//

#ifndef DoublePointer_hpp
#define DoublePointer_hpp

#include <stdio.h>
#include "CPlusHeader.h"


/*
 LCR 072. x 的平方根
 简单
 56
 相关企业
 给定一个非负整数 x ，计算并返回 x 的平方根，即实现 int sqrt(int x) 函数。

 正数的平方根有两个，只输出其中的正数平方根。

 如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。

  

 示例 1:

 输入: x = 4
 输出: 2
 示例 2:

 输入: x = 8
 输出: 2
 解释: 8 的平方根是 2.82842...，由于小数部分将被舍去，所以返回 2
  

 提示:

 0 <= x <= 231 - 1
  
 作者：力扣官方题解
 链接：https://leetcode.cn/problems/jJ0w9p/solutions/1398892/qiu-ping-fang-gen-by-leetcode-solution-ybnw/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
int mySqrt(int x) {
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}


#endif /* DoublePointer_hpp */
