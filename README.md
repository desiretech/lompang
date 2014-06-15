Lompang SDK
===========

This repository contains the API that powers the iOS carpooling app, [Lompang](http://appstore.com/lompang) It's a set of pubsub messaging functionalities which iOS developers can call from their Obj-C codes. Backend is conveniently handled for you.


##### INSTRUCTIONS
- Download the 3 files.
- Add the 3 files to Folder Group, "Frameworks"
- Link CoreData library to your binary
- Import Lompang.h in your AppDelegate.h
    - #import "Lompang.h"
    - @class Lompang;
- Declare Lompang in your AppDelegate.h
    - @property (strong, nonatomic) Lompang *lompang;
- Under applicationDidFinishLaunching, add the following lines
    - self.lompang= [[Lompang alloc] init];
    - self.lompang.delegate= self;
    - [self.lompang connect];
- Add in the following required delegate methods in AppDelegate.m
    - -(void)socketConnected;
        - Upon connection, sign in as with as a user
    - -(void)socketDisconnected;
    - -(void)socketSignedOut:(NSDictionary *)dict;
    - -(void)socketSignedIn:(NSDictionary *)dict;
    - -(void)socketSignedOut;
    - -(void)socketRegistered;
    - -(void)socketUnregistered;
    - -(void)socketReceivedDict:(NSDictionary *)dict;

##### METHODS
###### -(void)connect;
- Log onto the backend
- Once logged on, delegate method, -(void)socketConnected will be called
- From -(void)socketConnected, call -(void)signInAs:(NSString *)user to sign in a user

###### -(void)disconnect
- Opposite of connect 

###### -(void)join:(NSString *)group
- To add user to a group
- Joining a group is more permanent than listening to a group
- By joining a group, user's presence is also published to other members in the group
- User will receive any broadcasts sent to a group via delegate method, -(void)socketReceivedDict:(NSDictionary *)dict
- Unlike listening to a group, subscription to the group is persistant across multiple socket sessions

###### -(void)unjoin:(NSString *)group
- Opposite of join

###### -(void)listen:(NSString *)group to listen to a group
- To listen to a group
- Listening a group is more invisible
- Once the socket session is over, subscription to the group is also destroyed with the socket session
- Like joining a group, a user listening to a group will receive any broadcasts sent to a group via delegate method, -(void)socketReceivedDict:(NSDictionary *)dict

###### -(void)unlisten:(NSString *)group
- Opposite of listen

###### -(void)update:(NSMutableDictionary *)userload
- Every user has a userload tagged to it
- Feel free to add any information in NSMutableDictionary format to it
- This userload is broadcasted to other members in groups user has joined
- Upon signing in, this userload is also broadcasted to other members in the group

###### -(void)post:(NSString *)pid And:(NSMutableDictionary *)pidload To:(NSString *)group
- Posts are different from userload in that a user can have multiple posts but there can only be 1 userload per user
- Feel free to add any information in NSMutableDictionary format under Pidload
- A post is recognized by its unique pid
- Posting pid broadcasts the post to other members in the group

###### -(void)message:(NSString *)message And:(NSString *)pid And:(NSMutableDictionary *)pidload To:(NSString *)group
- Messaging is like posting, except that messaging also dispatches an iOS push notification to other members in the group with a message
- This function is only available on dedicated instances. Please email me for more information.

###### -(void)remove:(NSString *)pid
- This function removes posts
- Upon removal, a message with type= "remove" will be dispatched out to the group in which the pid was originally residing in

###### -(void)registerApns:(NSData *)token
- Registers the APNS string for iOS push notifications
- This function is only available on dedicated instances. Please email me for more information.

###### -(void)unregisterApns
- Unregisters the device from iOS push notifications
- This function is only available on dedicated instances. Please email me for more information.



##### WORK IN PROGRESS

- This page
- Instructions on how to deploy this SDK to your iOS codes 
- GeoSpatial functionalities that sit on top of the messaging layer
- Sample codes / Quick projects



##### WARNING

Do not store anything critical yet. I will be clearing the backend at the end of everyday. Do email me at admin@lompang.com if you want to buy me coffee. =)
