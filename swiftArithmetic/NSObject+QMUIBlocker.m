//
//  NSObject+QMUIBlocker.m
//  swiftArithmetic
//
//  Created by zhangshuai on 2026/3/31.
//

#import "NSObject+QMUIBlocker.h"
#import <objc/runtime.h>
#import <Foundation/Foundation.h>

@implementation NSObject (QMUIBlocker)


+ (void)load {
    // 只有在预览模式或特定环境下执行
    if (NSProcessInfo.processInfo.environment[@"XCODE_RUNNING_FOR_PREVIEWS"] ||
        NSProcessInfo.processInfo.environment[@"IDE_DISABLED_QMUI"]) {
        
        Class qmuiConfig = NSClassFromString(@"QMUIConfiguration");
        if (qmuiConfig) {
            // 重点：将 applyInitialTemplate 替换为一个空实现 (Empty Block)
            SEL targetSelector = NSSelectorFromString(@"applyInitialTemplate");
            Method originalMethod = class_getInstanceMethod(qmuiConfig, targetSelector);
            
            if (originalMethod) {
                imp_implementationWithBlock(^{
                    NSLog(@"⚠️ [Security] QMUI auto-init has been blocked by Runtime Hook.");
                });
                // 这样它就永远不会抛出那个“GitHub Issue”的断言异常了
            }
        }
    }
}

@end
