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
##### -(void)connect;


##### WORK IN PROGRESS

- This page
- Instructions on how to deploy this SDK to your iOS codes 
- GeoSpatial functionalities that sit on top of the messaging layer
- Sample codes / Quick projects



##### WARNING

Do not store anything critical yet. I will be clearing the backend at the end of everyday. Do email me at admin@lompang.com if you want to buy me coffee. =)
