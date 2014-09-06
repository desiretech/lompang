Lompang SDK
===========

This repository contains the API that powers the iOS carpooling app, [Lompang](http://appstore.com/lompang). It's a set of pubsub messaging functionalities which iOS developers can call from their Obj-C codes. Backend is conveniently handled for you.

<a name="previousscenario"></a> Below scenerio depicts 2 devices connecting and then joining Group A. Presence of User A and B are automatically broadcasted everyone in the group. More scenarios illustrated [below](#morescenarios).

![Join](/images/1.png)

### DEFINITIONS
Before venturing further, some basic definitions need to be established first. 

###### Groups
Equivalent of rooms and channels in standard pubsub terminology. A Group can contain a mixture of Posts and Users. Once a User is subscribed to a Group using the _join_ or _listen_ method, Users and Posts packets are pushed through the socketReceivedDict delegate method.

###### Users
When connecting to Lompang SDK for the first time, a device will be allocated a unique identifier _user_ that identifies a User by device and app. This unique identifier stays unchanged across sessions, even after an app uninstall. Below snippet shows a sample User package that is sent through the socketReceivedDict delegate method. _group_ refers to the Group from which the User package is pushed from. _timestamp_ refers to the Unix timestamp in milliseconds the User was last seen in the Group. _timestamp= 0_ indicates User is currently online. _userload_ is the custom payload that is attached to the User.

```
@@@ socketReceivedDict: {
    group = ABC;
    timestamp = 0;
    type = user;
    user = "7B9194EA-35D4-4BB7-89AE-2FBFD386AA60";
    userload =     {
        a = A;
        b = B;
    };
}
```

###### Posts
A User can _post_ a message to a Group via the _post_ method. Below snippet shows a sample Post package that is sent through the socketReceivedDict delegate method. _group_ is the Group that User _posted_ the Post to. _pid_ is the custom identifier that a developer uses to uniquely identify the Post. _pidload_ is the custom payload attached to the message. _timestamp_ is the Unix timetamp in milliseconds when User _posted_ the Post. _user_ is the User that _posted_ the Post.

```
@@@ socketReceivedDict: {
    group = ABC;
    pid = PID;
    pidload =     {
        a = A;
        b = B;
    };
    timestamp = 1409876031645;
    type = post;
    user = "45DC9C41-6047-4871-9AF4-357E8E4425A3";
}
```

### SCENARIOS <a name="morescenarios"></a>

Below illustrates the _listen_ method. Note that User B is unaware of User A's presence in the group. Compare this with the [previous](#previousscenario) scenario.
![Listen](/images/2.png)

Disconnect events are also broadcasted to Users in the Group. Illustrated below, User B is somehow disconnected at Stage 4. This change in presence is broadcasted to User A. Note that _timestamp_ of User B changed from 0 in Stage3 to 1409876031645 in Stage 5. _Timestamp= 0_ indicates User B was online at Stage 3. _Timestamp= 1409876031645_ indicates User B was last seen at Sep5, 2014, 12:13:51am UTC.
![Disconnect](/images/3.png)

Method _update_ changes the userload attached to User B. This change is then broadcasted to **all** Groups that User B has _join_-ed.
![Update](/images/4.png)

User A _posts_ a message with custom payload _pidload_ to Group A. Post is then broadcasted to everyone in Group A. Upon receipt, a developer is expected to issue out a _unpost_ command to remove the post. Otherwise Post A will continue to be dispatched out to all Users entering the Group.
![Post](/images/5.png)

### INSTRUCTIONS
* Generate APNS certificate from Apple.
 * Make sure certificate is in **.p12 extension** and is **NOT password protected**.
 * Not sure how? [Here for detailed instructions.](https://github.com/ngzhongcai/lompang/wiki/Generate-Certificates)
* Go to [lompang.com/sdk.html](http://lompang.com/sdk.html)
 * Key in your email address
 * Upload your **.p12 APNS cert that is NOT password protected**
 * Indicate type of certificate, whether it is Sandbox or Production
* Follow instructions from email and you should receive your token key
* Please keep your token key. You will need to add it to your codes later
* Create a new xCode project
* Change the architecture to armv7
<br/>
![Add Files](/images/changeArchitecture.png)
* Download the 3 files from [Lompang folder](https://github.com/ngzhongcai/lompang/tree/master/Lompang) in Github
 * Lompang.h, libLompang.a, lompang.mom
* Drag and drop the 3 files under Frameworks folder group
 * When prompted, select "Copy items into destination group's folder"  
* Link CoreData and SystemConfiguration, Foundation, CoreGraphics and UIKit libraries to your binary
<br/>
![Add Files](/images/addfiles.png)
* In [AppDelegate.h](https://github.com/ngzhongcai/lompang/blob/master/saas/AppDelegate.h)
 * ```#import "Lompang.h"```
 * ```@class Lompang;```
 * ```@property (strong, nonatomic) Lompang *lompang;```
* In [AppDelegate.m](https://github.com/ngzhongcai/lompang/blob/master/saas/AppDelegate.m)
    * Under didFinishLaunchingWithOptions, add the following lines
        * ```self.lompang= [[Lompang alloc] init];```
        * ```self.lompang.delegate= self; ```
        * ```[self.lompang connectToAccount:@"<YOUR_EMAIL>" WithToken:@"<YOUR_TOKEN>"];``` 
    * Add the following delegate methods
        * ```-(void)socketConnected:(NSDictionary *)dict;```
        * ```-(void)socketDisconnected;```
        * ```-(void)socketReceivedErr:(NSDictionary *)dict;```
        * ```-(void)socketRegistered:(NSDictionary *)dict;```
        * ```-(void)socketUnregistered;```
        * ```-(void)socketReceivedDict:(NSDictionary *)dict;```
    * Under socketConnected, register for APNS push notifications
        * ```[[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge|UIRemoteNotificationTypeSound|UIRemoteNotificationTypeAlert)];```
    * Add the following APNS delegate method
        * ```-(void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;```
    * Under didRegisterForRemoteNotificationsWithDeviceToken, add
        * ```[self.lompang registerApns:deviceToken];```
* Under socketRegistered, start making the calls out to Lompang SDK.
* [For more information, please refer here.](https://github.com/ngzhongcai/lompang/blob/master/Lompang/Lompang.h)
