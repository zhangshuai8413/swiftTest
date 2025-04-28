//
//  BrideCPlusManger.m
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/1.
//

#import "BrideCPlusManger.h"
#import "BrideCPlusManger+a.h"
#import "DynamicProgram.hpp"
#import "Greedy.hpp"
#include "Graph.hpp"
#include <iostream>
#include <bitset>
#include "MyArray.hpp"
#include "CPlusHeader.h"

using namespace std;

@implementation BrideCPlusManger
//@synthesize zhangSan = _zhangSan;
+ (void)load {
    NSLog(@"BrideCPlusManger------");
    
    [BrideCPlusManger testMethod];
    [BrideCPlusManger testLoad];
    
}

- (instancetype)init {
    if (self == [super init]) {
//        Person *person = [[Person alloc] init];
//        self.person = person;
//        dispatch_async(dispatch_get_global_queue(0, 0), ^{
//            // 添加观察者
//            [self.person addObserver:self forKeyPath:@"name" options:NSKeyValueObservingOptionNew context:nil];
//            // 修改Person对象的name属性，触发KVO通知
//            self.person.name = @"John";
//        });
        [self testSyn];
    }
    return self;
    
}

- (void)testSyn {
    
    dispatch_queue_t serialQueue = dispatch_queue_create("com.example.serialQueue", DISPATCH_QUEUE_CONCURRENT);
    dispatch_sync(serialQueue, ^{
        NSLog(@"任务3：%@", [NSThread currentThread]);
    });
    dispatch_async(serialQueue, ^{
        NSLog(@"任务4：%@", [NSThread currentThread]);
    });
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        dispatch_sync(serialQueue, ^{
            NSLog(@"任务1：%@", [NSThread currentThread]);
        });
        NSLog(@"任务2：%@", [NSThread currentThread]);
        
    });
  
}
- (void)testString {
//    self.strongString = [NSString stringWithFormat:@"dad"];
////    [NSString stringWithFormat:@"%@",@"string1"];
//    self.weakString =  self.strongString;
//    self.strongString = nil;
//    NSLog(@"weakString-------%@", self.weakString);
    @autoreleasepool {
        self.strongString = [NSMutableString stringWithFormat:@"%@", @"string1"];
        self.weakString = self.strongString;
        self.strongString = nil;
    }
    NSLog(@"weakString-------%@", self.weakString);
}

// 观察者方法，当name属性发生变化时会调用此方法
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    if ([keyPath isEqualToString:@"name"]) {
        NSString *newName = change[NSKeyValueChangeNewKey];
        NSLog(@"Name changed to %@", newName);
    }
}

+ (void)testMethod {
    NSLog(@"testMethod------");
}


-(void)methodtest1 {
    NSLog(@"BrideCPlusManger");

//    self.zhangSan =  @"q22";
//    NSString *Aa = self.zhangSan;
    
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

- (void)mapLearn {
    
    std::map<double, std::string> products;
    
    // 插入商品及其价格
    products[19.99] = "Book";
    products[9.99] = "Pen";
    products[49.99] = "Shoes";
    products[29.99] = "Shirt";
    
    for (auto rit  = products.rbegin(); rit != products.rend(); rit++) {
        std:: cout  << rit->first << ":" << rit->second << std::endl;
    }
}



@end
