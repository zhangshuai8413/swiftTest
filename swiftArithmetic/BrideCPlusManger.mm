//
//  BrideCPlusManger.m
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/1.
//

#import "BrideCPlusManger.h"
#import "DynamicProgram.hpp"
#include <iostream>
#include <bitset>

using namespace std;
@implementation BrideCPlusManger


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
@end
