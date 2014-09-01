//
//  Lompang.h
//  Lompang
//
//  Created by Zhongcai Ng on 1/9/14.
//  Copyright (c) 2014 lompang. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LompangDelegate <NSObject>
@required

-(void)socketConnected:(NSDictionary *)dict;
-(void)socketDisconnected;
-(void)socketReceivedErr:(NSDictionary *)dict;
-(void)socketRegistered:(NSDictionary *)dict;
-(void)socketUnregistered;
-(void)socketReceivedDict:(NSDictionary *)dict;

@end

@interface Lompang: NSObject

@property (nonatomic, weak) id delegate;

-(void)connectToAccount:(NSString *)acct WithToken:(NSString *)token;
-(void)disconnect;
-(void)update:(NSMutableDictionary *)userload;
-(void)registerApns:(NSData *)deviceToken;
-(void)unregisterApns;
-(void)join:(NSString *)group;
-(void)unjoin:(NSString *)group;
-(void)listen:(NSString *)group;
-(void)unlisten:(NSString *)group;
-(void)post:(NSString *)pid Pidload:(NSMutableDictionary *)pidload To:(NSString *)group;
-(void)unpost:(NSString *)pid;
-(void)notify:(NSString *)message Group:(NSString *)group;

@end