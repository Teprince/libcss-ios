//
//  ViewController.m
//  libcss-test
//
//  Created by HuGuanqin on 7/22/16.
//  Copyright © 2016 Teprince. All rights reserved.
//

#import "ViewController.h"

extern int css_test();

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    css_test();
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
