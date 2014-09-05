Lompang SDK
===========

This repository contains the API that powers the iOS carpooling app, [Lompang](http://appstore.com/lompang). It's a set of pubsub messaging functionalities which iOS developers can call from their Obj-C codes. Backend is conveniently handled for you.

Below is a simple scenerio depicting 2 devices connecting and then joining a Group A. Presence of User A and B are automatically broadcasted everyone in the group. More scenarios illustrated [below](#morescenarios)

![Join](/Scenarios/1.png)

### DEFINITIONS
Before venturing further, some basic definitions first need to be established first. 

###### Groups
Equivalent of rooms or channels in standard pubsub terminology. A Group can contain a mixture of Posts and Users. Once subscribed to a Group using the _join_ or _listen_ method, Users and Posts packets are pushed to the User through the socketReceivedDict delegate method.

###### Users
When connected to Lompang backend for the first time, a device will be allocated a unique identifier _user_ that identifies a User by device and app. This unique identifier stays unchanged across sessions, even after an uninstall. Below code snippet shows a sample User package that is sent to the socketReceivedDict delegate method. _group_ refers to the Group from which the User package is pushed from. _timestamp_ refers to the Unix timestamp in milliseconds the User was last seen in the Group. _timestamp= 0_ indicates User is currently online. _userload_ is the custom payload that is attached to the User.

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
A User can post a message to a Group via the _post_ method. Below code snippet shows a sample Post package that is sent to the socketReceivedDict delegate method. _group_ is the Group that User posted the Post to. _pid_ is the custom identifier a developer uses to uniquely identify the Post. _pidload_ is the custom payload attached to the message. _timestamp_ is the Unix timetamp in milliseconds when User posted the Post. _user_ is the User that posted the Post.  

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

#### SCENARIOS <a name="morescenarios"></a>

![Join](/Scenarios/2.png)
![Join](/Scenarios/3.png)
![Join](/Scenarios/4.png)
![Join](/Scenarios/5.png)

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
