//
//  MyArray.hpp
//  swiftArithmetic
//
//  Created by 张帅 on 2023/8/12.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <stdio.h>
#include "CPlusHeader.h"
#include <stdio.h>

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    int p = m - 1;
    int q = n - 1;
    int k = m + n - 1;
    while (p >= 0 && q >=0) {
        nums1[k--] = nums1[p] > nums2[q] ? nums1[p--] : nums2[q--];
    }
    while (q >= 0) {
        nums1[k--] = nums2[q--];
    }
}
#endif /* MyArray_hpp */
