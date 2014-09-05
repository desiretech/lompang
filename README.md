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

Disconnect events are also broadcasted to Users in the Group. In the below case at Stage 4, User B is somehow disconnected. This change in presence is broadcasted to User A. Note that _timestamp_ of User B has changed from 0 in Stage3 to 1409876031645 in Stage 5. _Timestamp= 0_ indicates User B was online at Stage 3. _Timestamp= 1409876031645_ indicates User B was last seen at Sep5, 2014, 12:13:51am UTC.
![Disconnect](/images/3.png)

Method _update_ changes the userload attached to User B. This change is then broadcasted to all Groups that User B has _join_-ed.
![](/images/4.png)

User A _posts_ a message with custom payload _pidload_ to Group A. Post is then broadcasted to everyone in Group A. Upon receipt, a developer is expected to manually issue out a _unpost_ command to remove the post. Otherwise Post A will continue to be dispatched out to Users entering the Group.
![](/images/5.png)

#### INSTRUCTIONS
* Generate APNS certificate from Apple
* Make sure certificate is
 * .p12 extension
 * NOT password protected
* Go to [lompang.com/sdk.html](http://lompang.com/sdk.html)
 * Key in your email address
 * Upload your .p12 APNS cert that is NOT password protected
 * Indicate type of certificate, whether it is Sandbox or Production
* Follow instructions from email and you should receive your token key
* Please keep your token key. You will need to add it to your codes later
* Download the 3 files from Lompang folder
* Add the 3 files to Folder Group, Frameworks
* Change the architecture of app to armv7
* Link CoreData and SystemConfiguration libraries to your binary

[Click here for more information on the individual methods](https://github.com/ngzhongcai/lompang/blob/master/Lompang/Lompang.h)
