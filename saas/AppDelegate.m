//
//  AppDelegate.m
//  saas
//
//  Created by Zhongcai Ng on 1/9/14.
//  Copyright (c) 2014 lompang. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window= [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor= [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    self.lompang= [[Lompang alloc] init];
    self.lompang.delegate= self;
    [self.lompang connectToAccount:@"<YOUR_EMAIL>" WithToken:@"<YOUR_TOKEN>"];
    
    return YES;
}

-(void)socketConnected:(NSDictionary *)dict {
    NSLog(@"@@@ socketConnected: %@", dict);
    [[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge|UIRemoteNotificationTypeSound|UIRemoteNotificationTypeAlert)];
}

-(void)socketDisconnected {
    NSLog(@"@@@ socketDisconnected");
}

-(void)socketReceivedErr:(NSDictionary *)dict {
    NSLog(@"@@@ socketReceivedErr: %@", dict);
}

-(void)socketRegistered:(NSDictionary *)dict {
    NSLog(@"@@@ socketRegistered: %@", dict);
    [self.lompang join:@"ABC"];
    
    NSMutableDictionary *dictTest= [[NSMutableDictionary alloc] init];
    [dictTest setObject:@"A" forKey:@"A"];
    [dictTest setObject:@"B" forKey:@"B"];
    [self.lompang post:@"PID" Pidload:dictTest To:@"ABC"];
    [self.lompang notify:@"TEST" Group:@"ABC"];
}

-(void)socketUnregistered {
    NSLog(@"@@@ socketUnregistered");
}

-(void)socketReceivedDict:(NSDictionary *)dict {
    NSLog(@"@@@ socketReceivedDict: %@", dict);
}

-(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [self.lompang registerApns:deviceToken];
}

-(void)applicationWillResignActive:(UIApplication *)application { }
-(void)applicationDidEnterBackground:(UIApplication *)application { }
-(void)applicationWillEnterForeground:(UIApplication *)application { }
-(void)applicationDidBecomeActive:(UIApplication *)application { }
-(void)applicationWillTerminate:(UIApplication *)application { }

@end