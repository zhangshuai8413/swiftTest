//
//  BrideCPlusManger+a.m
//  swiftArithmetic
//
//  Created by 张帅 on 2023/8/5.
//

#import "BrideCPlusManger+a.h"

@implementation BrideCPlusManger (a)


//+ (void)initialize {
//    NSLog(@"BrideCPlusManger initialize");
//}
+ (void)load {
    NSLog(@"BrideCPlusManger a");
}

-(void)test1 {
    NSLog(@"test1 -----a");
}
+(void)testLoad {
    NSLog(@"test-------testLoad");
}

@end
