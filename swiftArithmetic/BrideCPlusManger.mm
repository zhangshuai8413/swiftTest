//
//  BrideCPlusManger.m
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/1.
//

#import "BrideCPlusManger.h"
#import "DynamicProgram.hpp"
#import "Greedy.hpp"
#include "Graph.hpp"
#include <iostream>
#include <bitset>
#include "MyArray.hpp"
using namespace std;
@implementation BrideCPlusManger

+ (void)load {
    NSLog(@"BrideCPlusManger------");
}

-(void)test1 {
    NSLog(@"BrideCPlusManger");
}

void printArray(vector<vector<int>> result) {
    for (int i = 0; i < result.size(); i ++) {
        cout << "\n 换行了" << endl;
        for (int j = 0; j < result[0].size() ; j++) {
            cout << result[i][j] << endl;
        }
    }
}

- (void)wei_bag_problem1 {
    Knapsack *knapsack = new Knapsack;
    vector<vector<int>> aa = knapsack->test_2_wei_bag_problem1();
    printArray(aa);
}

- (void)test_1_wei_bag_problem {
    cout << "dp----: " << endl;
    Knapsack *knapsack = new Knapsack;
    knapsack->test_1_wei_bag_problem();
    
}

- (void)targetSum {
    vector<int>nums = {1};
    int target = 1;
    SumOfZeroOne * sumOfZero = new SumOfZeroOne;
    
   int count = sumOfZero->findTargetSumWays(nums, target);
    cout << "target Sum Count" << count << endl;
}

-(void)numIslands {
    NumIslands * number =  new NumIslands;
    
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    number->numIslands(grid);

}

-(void)quickSort {
//    int aa[]  = {1,10,3,11,6,4,5,7,8};
//    FLQuickSort *quick = new FLQuickSort;
//    int n = sizeof(aa)/ sizeof(int);
//
//    quick->quickSort(aa, 0, n -1);
//    for (int i=0; i< n; ++i) {
//        cout << aa[i] << endl;
//    }
    
    vector<int> bb = {1,10,3,11,6,4,5,7,8, 6};
    
    FLQuickSort *quick = new FLQuickSort;
    quick->quicksort(bb, 0, (int)bb.size() );
    
    for (int i=0; i< bb.size(); ++i) {
           cout << bb[i] << endl;
    }
}

@end
