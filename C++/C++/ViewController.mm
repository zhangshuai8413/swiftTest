//
//  ViewController.m
//  C++
//
//  Created by 张帅 on 2023/5/1.
//

#import "ViewController.h"
#include "FFList.hpp"
#include <iostream>
using namespace std;
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor redColor];
    
    // Do any additional setup after loading the view.
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
     string str = longestPalindrome("aabbbac");
     printf("%s",str.c_str());
}


@end
