//
//  ABoutViewController.m
//  swiftArithmetic
//
//  Created by zhangshuai on 2026/3/25.
//

#import "ABoutViewController.h"

// CocoaPods 引入 SDWebImage 后可用
#import <SDWebImage/UIImageView+WebCache.h>

@interface ABoutViewController ()

@end

@implementation ABoutViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = UIColor.systemBackgroundColor;

    UIImageView *imageView = [UIImageView new];
    imageView.contentMode = UIViewContentModeScaleAspectFill;
    imageView.clipsToBounds = YES;
    imageView.backgroundColor = UIColor.secondarySystemBackgroundColor;
    imageView.translatesAutoresizingMaskIntoConstraints = NO;

    [self.view addSubview:imageView];
    [NSLayoutConstraint activateConstraints:@[
        [imageView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [imageView.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor],
        [imageView.widthAnchor constraintEqualToConstant:260],
        [imageView.heightAnchor constraintEqualToConstant:260]
    ]];

    // 测试下载图片（示例 URL，可替换为你的接口地址）
    NSURL *url = [NSURL URLWithString:@"https://picsum.photos/400/400?random=1"];
    [imageView sd_setImageWithURL:url
                   placeholderImage:nil
                          options:SDWebImageRetryFailed
                        completed:^(UIImage * _Nullable image,
                                    NSError * _Nullable error,
                                    SDImageCacheType cacheType,
                                    NSURL * _Nullable imageURL) {
        if (error) {
            NSLog(@"[SDWebImage] download failed: %@", error);
        }
    }];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
