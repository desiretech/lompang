Lompang SDK
===========

This repository contains the API that powers the iOS carpooling app, [Lompang](http://appstore.com/lompang) It's a set of pubsub messaging functionalities which iOS developers can call from their Obj-C codes. Backend is conveniently handled for you.


#### CONCEPTS
There are 2 entities within LompangSDK.

Users

Posts


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
