//
//  Lompang.h
//  Lompang
//
//  Created by Zhongcai on 8/6/14.
//  Copyright (c) 2014 Zhongcai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol LompangDelegate <NSObject>
@required

-(void)socketConnected;
-(void)socketDisconnected;
-(void)socketSignedIn;
-(void)socketSignedOut;
-(void)socketRegistered;
-(void)socketUnregistered;
-(void)socketReceivedDict:(NSDictionary *)dict;

@end

@interface Lompang: NSObject

@property (nonatomic, weak) id delegate;

-(void)connect;
-(void)disconnect;
-(void)signInJoinAndSubscribe:(NSString *)group;
-(void)signOutLeaveAndUnsubscribe;
-(void)joinAndSubscribe:(NSString *)group;
-(void)leaveAndUnsubscribe:(NSString *)group;
-(void)queryGroup:(NSString *)group ForTop:(int)num;
-(void)subscribe:(NSString *)group;
-(void)unsubscribe:(NSString *)group;
-(void)queryJoinAndSubscribe:(NSString *)group ForTop:(int)num;
-(void)postPid:(NSString *)pid Payload:(NSMutableDictionary *)payload To:(NSString *)group;
-(void)publishPayload:(NSMutableDictionary *)payload To:(NSString *)group;
-(void)removeAndPublishPid:(NSString *)pid From:(NSString *)group;
-(void)postAndPublishPid:(NSString *)pid Payload:(NSMutableDictionary *)payload To:(NSString *)group;

// PLEASE CONTACT admin@lompang.com for PUSH NOTIFICATION SUPPORT
// -(void)registerApns:(NSData *)token;
// -(void)unregisterApns;
// -(void)postPublishNotifyPid:(NSString *)pid Payload:(NSMutableDictionary *)payload Message:(NSString *)message To:(NSString *)group;

@end