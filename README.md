Lompang SDK
===========

This repository contains the API that powers the iOS carpooling app, [Lompang](http://appstore.com/lompang) It's a set of pubsub messaging functionalities which iOS developers can call from their Obj-C codes. Backend is conveniently handled for you.


#### CONCEPTS

###### Groups
Equivalent of Rooms or Channels in standard pubsub terminology. A Group can contain a mixture of Posts and Users. When a User connects to a Group, all Users and Posts residing in the Group will be pushed to User via the socketReceivedDict delegate method.

###### Users
Equivalent of Client in standard pubsub terminology. When connected to Lompang backend for the first time, a device will be allocated a unique identifier _user_ that identifies a User by device and app. This unique identifier will stay unchanged across sessions. _group_ refers to the Group from which the User is pushed from. _timestamp_ refers to the Unix timestamp the User was last seen in the Group. _timestamp= 0_ indicates User is currently online. _userload_ is the custom payload a developer attached to the User.

```
@@@ socketReceivedDict: {
    group = ABC;
    timestamp = 0;
    type = user;
    user = "7B9194EA-35D4-4BB7-89AE-2FBFD386AA60";
    userload =     {
        A = A;
        B = B;
    };
}
```

###### Posts





![Join](http://lompang.com/images/sdkjoin.png)
![Join](http://lompang.com/images/sdklisten.png)
![Join](http://lompang.com/images/sdkpost.png)

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
