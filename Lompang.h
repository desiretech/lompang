//
//  Lompang.h
//  Lompang
//
//  Created by Zhongcai on 15/6/14.
//  Copyright (c) 2014 Zhongcai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol LompangDelegate <NSObject>
@required

-(void)socketConnected;
-(void)socketDisconnected;
-(void)socketSignedIn:(NSDictionary *)dict;
-(void)socketSignedOut:(NSDictionary *)dict;
-(void)socketRegistered;
-(void)socketUnregistered;
-(void)socketReceivedDict:(NSDictionary *)dict;

@end

@interface Lompang: NSObject

@property (nonatomic, weak) id delegate;

-(void)connect;
-(void)disconnect;
-(void)signInAs:(NSString *)user;
-(void)update:(NSMutableDictionary *)userload;
-(void)registerApns:(NSData *)token;
-(void)unregisterApns;
-(void)join:(NSString *)group;
-(void)unjoin:(NSString *)group;
-(void)listen:(NSString *)group;
-(void)unlisten:(NSString *)group;
-(void)post:(NSString *)pid And:(NSMutableDictionary *)pidload To:(NSString *)group;
-(void)message:(NSString *)message And:(NSString *)pid And:(NSMutableDictionary *)pidload To:(NSString *)group;
-(void)remove:(NSString *)pid;

@end