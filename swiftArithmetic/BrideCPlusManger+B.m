//
//  BrideCPlusManger+B.m
//  swiftArithmetic
//
//  Created by 张帅 on 2023/8/5.
//

#import "BrideCPlusManger+B.h"

@implementation BrideCPlusManger (B)

//+ (void)initialize {
//    NSLog(@"BrideCPlusManger (B) ---------initialize");
//}

+ (void)load {
    NSLog(@"BrideCPlusManger B");
}

- (void)test1 {
    NSLog(@"test1 -----b");
}
@end
