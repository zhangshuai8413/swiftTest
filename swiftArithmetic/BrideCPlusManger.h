//
//  BrideCPlusManger.h
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/1.
//

#import <Foundation/Foundation.h>
#import "Person.h"

NS_ASSUME_NONNULL_BEGIN



@protocol BrideCPlusMangerDelegate <NSObject>
@required
@property (nonatomic, copy) NSString *zhangSan;

@end

@interface BrideCPlusManger : NSObject<BrideCPlusMangerDelegate>
@property (nonatomic, strong) Person *person;
@property (nonatomic, copy) NSString *name;
//@property (nonatomic, copy) NSString *zhangSan;

- (void)wei_bag_problem1;
- (void)test_1_wei_bag_problem;

- (void)targetSum;

-(void)numIslands;
-(void)test1;

-(void)quickSort;
-(void)methodtest1;

-(void)simplifyPath;

@end

NS_ASSUME_NONNULL_END
