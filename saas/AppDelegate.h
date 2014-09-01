//
//  AppDelegate.h
//  saas
//
//  Created by Zhongcai Ng on 1/9/14.
//  Copyright (c) 2014 lompang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Lompang.h"

@class Lompang;

@interface AppDelegate: UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) Lompang *lompang;

@end