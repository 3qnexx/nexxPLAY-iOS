# nexxPLAY iOS 

## Latest version

### v5.9.90
- internal renaming
- interface method renamed: startPlayByForeignReference() is now startByRemoteMedia

Compiled with XCode 11.3.1 (Swift 5.1)

## Integration

### nexxPLAY integration into project

1. In Xcode, select your project, select your target and open the tab “General”
2. Drag the nexxPlay.framework file from the Finder to the “Embedded Binaries” section
3. Please make sure that the framework is also included in “Linked Frameworks and Libraries”
4. Change your tab to “Build Phases”
5. Drag the nexxPlay.bundle from the Finder to the “Copy Bundle resources”
6. Still in “Build Phases”, click on the “+“ icon and add a new run script phase
7. Copy the code from the file “strip-framework.sh” into the run script phase. Please make sure that this run script phase is the last phase of the build process!
8. IMPORTANT CHANGE IN XCODE 8, ONLY Objective-C: Change your tab to “Build Settings” and make sure that “Always Embed Swift Standard Libraries” is set to “YES” (the default value is “NO”)

#### 3rd party frameworks

nexxPLAY contains presenting video ads via the Google IMA SDK. Therefore the additional SDK need to be added to the project:

- GoogleInteractiveMediaAds.framework (please download v3.10.1 from https://developers.google.com/interactive-media-ads/docs/sdks/ios/download)

Please drag these frameworks into the "Embedded Binaries" section of your target (exactely as explained for the nexxPLAY framework in steps 1 and 2) and make sure they also appear in the "Linked Frameworks and Libraries" section (nexxPLAY integration step 3).

##### IMPORTANT

Since v5.9.86 of the nexxPLAY framework, offline features are not supported anymore. Hence the DailyMe SDK is not needed in that and the following versions!


### Code samples

#### Adding a player instance

##### Swift

```swift
import UIKit
import nexxPlay

class ViewController: UIViewController {

    override func viewDidLoad() { 
        super.viewDidLoad()
        let v_player = PlayerView(frame: CGRect(x: 0, y: 0, width: 300, height: 300)) view.addSubview(v_player)
        //possible predefinitions v_player.overrideMidroll(“http://vastURL”, interval:5) v_player.overrideAutoPlay(true)
        v_player.startPlay("0", client: "571", playmode: "single", param: "40164") 
    }
}
```

##### Objective C

```objective-c
#import "ViewController.h" #import <nexxPlay/nexxPlay.h>

@interface ViewController () @end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view, typically from a nib.
    PlayerView* view = [[PlayerView alloc] initWithFrame:CGRectMake(0.0, 0.0, 300.0, 300.0)];
    [self.view addSubview:view];
    //possible predefinitions
    [v_player overrideMidroll:@“http://vastURL” interval:5]; [v_player overrideAutoPlay:YES];
    [view startPlay:@"0" client:@"571" playmode:@"single" param:@"40164" startPosition:0 startItem:0];
}

@end
```

#### removing a player instance

As soon as the PlayerView is deallocated, the player will automatically stop.

## Public methods

The following methods can be called prior to the initial method `startPlay()` in order to predefine information for the player. In case the backend also provides this information when calling `startPlay()`, only the information that was not provided before `startPlay()` is used from the backend.

### VAST presets

#### overridePreroll(url:String) 
Sets the URL for the VAST preroll.

#### overrideMidroll(url:String, interval:Int) 
Sets the URL and time interval (minutes) for the VAST midroll. 

#### overrideBanner(url:String, interval:Int)
Sets the URL and time interval (minutes) for the VAST banner roll.

#### overridePostroll(url:String) 
Sets the URL for the VAST postroll

#### overrideAdProvider(provider:String) 
Sets the ad provider. 

#### overrideAdType(adType:String) 
The different values for ad type can be `vast` and `ima`, `vast` is set as default parameter. In case you want to use the Google IMA SDK to play video ads, override the default setting with `ima`.

#### overrideVASTData(provider:String, prerollURL:String, midrollURL:String, midrollInterval:Int ,bannerURL:String, bannerInterval:Int,postRollURL:String, adType:String) 
Sets all VAST information for the player.

### Other player presets

#### overrideMenu(visibility:Int)
Updates the setting defining whether the menu is never visible (0), visible on tap (1) or always visible(2)

#### overrideAutoPlay(autoPlayMode:Bool)
Updates the setting defining whether videos should start automatically

#### overrideExitMode(exitMode:String)
Updates the exitMode after the video. The different modes are:
•    `replay`: no exit page, only a replay button in the center
•    `navigate`: presents an exit page
•    `playlist`: nothing is shown

#### overrideAutoNext(autoNext:Bool)
Updates the setting defining whether the next video should start automatically after some seconds

#### setPlayerBackgroundColor(backgroundColor:String)
Updates the background color of the player. The default color is black. Please enter the color as a 6 digit hex value (e.g. white is `ffffff`).

#### setDelay(delay:Int)
Defines the start position of the video (in seconds).

#### overrideTitles(visibility:Int)
Defines the visibility of the video titles. The titles can be hidden (0), always visible (1) or only visible when the player is fullscreen (2).

#### addObserverForAllNotifications(observer:AnyObject, selector:String)
Convenience function to add an observer on all notifications the player will send. Whenever a notification is sent by the player, the function defined by selector is called on observer. For more information see [Notifications](#Notifications).

#### removeObserverForAllNotifications(observer:AnyObject)
Convenience function to remove an observer on all notifications the player will send. 

#### enableCordova() 
If the player is used in a cordova app, this method must be called before start play to enable cordova specific features.

#### clearCache() 
The data received by the nexxPlay API is cached for 30 minutes. Call this method to clear the cache manually. 

#### setDatamode(datamode:String) 
By default, the video data is received from the API. If your set the data mode to `static`, instead a static url is called to receive all the necessary data.

#### setGoogleIMAReferenceViewController(viewController:UIViewController) 
The Google IMA SDK presents the advertisement modally on a UIViewController once the user taps the video ad. If the Google IMA SDK is used but no view controller is set, the advertisement will open in Safari.

#### setWerbURLRepresentation(url:String) 
In case any of the VAST urls contains the placeholder `(page.host)`, the given string will replace it.

#### setViewParentID(mode:String) 
Sets the parent ID for playlists in order to add references for the reporting.

#### setPlayLicense(playLicense:Int) 
Use this method if you want to group videos coming from the same domain ID.

#### setLoaderSkin(skin:String) 
Changes the default loading skin. Possible values are:
•    `default`: the default loading skin. If you want to use this skin, you don’t need to call this method
•    `doublebounce`

#### setSessionCallReason(reason:String) 
Use this method if you want to set a reason how the player was opened (for reporting).

#### setDeviceID(deviceID:String) 
Use this method if you want to manually set the deviceID for reporting. Otherwise the player will create a deviceID.

#### setStreamingFilter(filter:String) 
Use this method if you want to exclude quality tracks from your stream.

#### setUserHash(userHash:String) 
Use this method if you have a logged in user with which you want to start your session.

#### overrideCaptionMode(mode:String) 
Use this method to override the caption mode for the player. Possible values are:
•    `none`
•    `select`
•    `selectandstart`
•    `always`

#### disableAds(disablePre:Bool, disableMid:Bool, disableBanner:Bool, disablePost:Bool) 
Use this method to override any ad definitions yet set in the player.

#### setSSL(useSSL:Bool) 
Use this method to define whether api and media URLs should be created with or without SSL.

#### disableWatermark() 
Hide the watermark image with this method.




### Controlling the player

#### startPlay(sessionID:String, client:String, playmode:String, param:String, startPosition:Int = 0, startItem:Int = 0)
Initial method to get the client data, ad data and video data. The attributes `startPosition` and `startItem` are optional.

#### startPlayWithGlobalID(sessionID:String, client:String, globalID:String, startPosition:Int = 0, startItem:Int = 0)
Initial method to get the client data, ad data and video data via a global ID. The attributes `startPosition` and `startItem` are optional.

#### startPlayWithRemoteMedia(sessionID:String, client:String, playmode:String, reference:String, provider:String, startPosition:Int = 0, startItem:Int = 0)
Initial method to get the client data, ad data and video data of a remote media. The attributes `startPosition` and `startItem` are optional.

#### swap(param:String)
This method changes the video ID, thus the player will load the necessary information about the new video and restart with the new data

#### swapToPos(newParam:String)
In case the player currently plays a playlist, it will switch to the video with the provided ID (newParam)

#### swapComplex(playMode:String, param:String, startPosition:Int = 0, startItem:Int = 0)
Like `swap()` this method changes the video ID but also lets you define a new playmode as well as the first item to be played (for playlists) and the position, the video is started from (in seconds). The attributes `startPosition` and `startItem` are optional.

#### play()
The player starts/continues playing.

#### pause()
The player pauses.

#### mute()
The player is muted.

#### unmute()
The player is unmuted.

#### seek(time:Int)
The current video is set to the defined position (in seconds).

#### getMediaData(getEnhanced:Bool) -> [String:String]
Returns details about the current video as a dictionary. These details contain:
* `mediaID` The id of the current media   
* `mediaDomain` The domain of the current media    
* `hash` The hash value    
* `title` The title of the media     
* `subtitle` The subtitle (optional)     
* `runtime` The runtime of the media (optional)     
* `actors` The actors (optional)     
* `channel` The channel (optional)     
* `channel_id` The channel id (optional)     
* `channel_adref` The channel ad reference (optional)      
* `thumb` The url of the thumb (optional)      
* `uploaded` The UNIX Timestamp stating when the media was uploaded (optional)      
* `created` The UNIX Timestamp stating when the media was created (optional)      
* `orderhint` The order hint (optional)       
* `licenseBy` (optional)      
* `studio` (optional)      
* `studio_adref` (optional)       
* `currentCaptionLanguage` The order hint (optional)      
* `currentPlaybackSpeed` The playback speed (currently always 1)       
* `isStitched` static value (0)      
* `isPresentation` static value (0)       
* `currentAudioLanguage` The name of the current language if the media fiel supports multiple languages (optional)       

If there is no current video, the method returns an empty dictionary. If the dictionary is not empty, the attributes mediaID, hash and title are set. All other attributes are optional and may not be available.
If you set the optional getEnhanced attribute to true, you will get additional parameters:

* `mediaSession` The session id of the current video      
* `mediaSessionParent` The parent id of the current video     
* `currentDuration` The duration the player is playing. Can be different to currentTime if the user skips seconds or jumps to other timestamps     
* `currentTime` The current timestamp of the playing video     
* `streamType` The stream type (_live_ oder _video_)     
* `isAutoPlay` Defining whether the video was started automatically (_1_ or _0_)     

#### checkPayment() 
In case the player was automatically paused because a preview of a video was shown, this method can trigger the check for payment in case the check is positive, the player resumes the video.

#### getCaptionData(language:String? = nil) 
Use this method to retrieve the captions of a media element. If there is no current element or the element does not contain captions, this method returns nil. In case you want to get captions for a specific language, you can set the 2 digit language code as parameter.

#### getCurrentTime() 
Returns the playback time for the current media in seconds.

#### disableFullscreenCloseButton() 
If you don’t want to show the extra fullscreen close button on the top left when the player is in fullscreen, call this method.

#### setPlayerFullscreen() 
In case you present the player always on the full screen of the device, call this method so there are no fullscreen buttons in the player.

#### setUserIsTrackingOptOuted() 
If you call this method, there will be no ad tracking in the player.

#### setLanguage(code:String)
Use this call to set the language code in the initial API call

## Player notifications

To observe the player’s behaviour the framework provides multiple notifications for the application. Some notifications contain additional data in the userInfo dictionary. The different notifications and how to receive them is described below

### Notifications

##### nexxPlayErrorNotification
The player shows the error view.

##### nexxPlayStartPlaybackNotification
The player did load the video data.

##### nexxPlayStartPlayNotification
The player starts playing the content video. If there is an ad before the actual content video, this notification is fired once the ad is ended and the content will start.

##### nexxPlayPlayNotification
Whenever the video starts to play (also after pause).    
__userInfo:__    
* `byUserAction` : Whether the player was started by the user or not

##### nexxPlayPauseNotification
Whenever the video pauses.    
__userInfo:__    
* `byUserAction` : Whether the player was started by the user or not

##### nexxPlayEndedNotification
Whenever the video is finished.

##### nexxPlayEndedAllNotification
When the last media of a playlist has finished. Also triggered at the end of a single media.

##### nexxPlayPlayPosNotification
The player switches to a new video in the playlist.    
__userInfo:__    
* `position` : The video position

##### nexxPlayAdCalledNotification
The player asks for ad information.    
__userInfo:__    
* `mode` : The adMode, “ima” or “vast”     
* `type` : “preroll”, “midroll”, “banner” or “postroll”


##### nexxPlayAdStartedNotification
The player starts a video ad.    
__userInfo:__    
* `mode` : The adMode, “ima” or “vast”      
* `type` : “preroll”, “midroll”, “banner” or “postroll”

##### nexxPlayAdEndedNotification
A video ad is finished (or skipped if possible).    
__userInfo:__    
* `mode` : The adMode, “ima” or “vast”      
* `type` : “preroll”, “midroll”, “banner” or “postroll”

##### nexxPlayAdErrorNotification
An error regarding the video ad occured.    
__userInfo:__    
* `mode` : The adMode, “ima” or “vast”      
* `type` : “preroll”, “midroll”, “banner” or “postroll”

##### nexxPlayAdClickedNotification
The video ad was clicked.    
__userInfo:__    
* `mode` : The adMode, “ima” or “vast”      
* `type` : “preroll”, “midroll”, “banner” or “postroll”

##### nexxPlayAdResumedNotification
The video ad continues playing after the user clicked on it.    
__userInfo:__    
* `mode` : The adMode, “ima” or “vast”      
* `type` : “preroll”, “midroll”, “banner” or “postroll”


##### nexxPlayPayPreviewEndedNotification
If the video is shown in preview mode and the preview minutes are over.

##### nexxPlayFullscreenCloseNotification
If the player is used in combination with cordova and the user presses the close button (only available when cordova is enabled).

##### nexxPlayMetaDataLoadedNotification
Every time the meta data for a video is loaded.     
__userInfo:__    
* `orientation` : the media orientation, for audio streams “none”     
* `hasAudio` : 1 if the media  has audio, 0 otherwise

##### nexxPlayShowUINotification 
Every time the player controls become visible.

##### nexxPlayHideUINotification 
Every time the player controls will hide.

##### nexxPlayFullscreenEnteredNotification 
Every time the player enters fullscreen.

##### nexxPlayFullscreenExitedNotification 
Every time the player exits the fullscreen mode.

##### nexxPlayProgress25Notification, nexxPlayProgress50Notification, nexxPlayProgress75Notification, nexxPlayProgress95Notification
Every time the video duration reaches 25%, 50%, 75% and 95% of its length.

##### nexxPlayMuteNotification 
The player has been muted.

##### nexxPlayUnmuteNotification 
The player has been unmuted.

##### nexxPlaySecondNotification 
Is sent every second when the player is playing a video.    
__userInfo:__    
* `duration` : The played duration

##### nexxPlayQuarterNotification 
Is sent every 15 seconds when the player is playing a video.    
__userInfo:__    
* `progress` : The played duration

##### nexxPlayStartSessionNotification 
The player has been assigned a session ID.

##### nexxPlayPIPEnteredNotification 
The video is presented via picture in picture.

##### nexxPlayPIPExitedNotification 
The picture in picture media presentation stopped.

##### nexxPlayStartSessionNotification 
Picture in picture did stop and the video is presented in the application.

##### nexxPlayRemoteEnteredNotification 
The video is presented via airplay on an external device.    
__userInfo:__    
* `device` : “airplay”

##### nexxPlayRemoteExitedNotification 
Airplay is stopped and the video is presented by the application.    
__userInfo:__    
* `device` : “airplay”

##### nexxPlayReplayNotification 
The video is finished and restarted, either automatically or by user interaction.    
__userInfo:__    
* `byUserAction` : 1 or 0

##### nexxPlayMainInteractionNotification 
The video presentation is started by pressing the main start button.

##### nexxPlayDownloadStartedNotification 
The download of an offline media has started    
__userInfo:__    
* `item` : media ID
* `title`: title of the media

##### nexxPlayDownloadProgressNotification 
There is new progress on the download of an offline media    
__userInfo:__    
* `item` : media ID
* `title`: title of the media
* `progress`: the current progress

##### nexxPlayDownloadSuccessNotification 
The download of an offline media is finished    
__userInfo:__    
* `item` : media ID
* `title`: title of the media

##### nexxPlayDownloadErrorNotification 
An error occured while downloading an offline media    
__userInfo:__    
* `item` : media ID
* `title`: title of the media
* `error`: the error description

### Observing notifications

The notifications are sent by the NSNotificationCenter. To receive a notification you can use the following code snippet:

##### Swift

```swift
NSNotificationCenter.defaultCenter().addObserver(self, selector: "notificationReceived:", name: nexxPlay.nexxPlayErrorNotification, object: playerView)
```

##### Objective-C

```objective-c
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationReceived:) name:@"NexxPlayErrorNotification" object:playerView];
```
The appropriate function that is called when the notification is received:

##### Swift

```swift
@objc func notificationReceived(notification:NSNotification) {
    println(notification.name)        // prints “NexxPlayErrorNotification”
    if notification.name == nexxPlay.nexxPlayPlayPosNotification, let userInfo = notification.userInfo {
        // use the additional data in userInfo
        
    }
}
```

##### Objective-C

```objective-c
- (void)notificationReceived:(NSNotification*)notification {
    NSLog(notification.name);
    if ([notification.name isEqualToString:@"NexxPlayPlayPosNotification"]) {
        if (notification.userInfo != nil) {
        // use the additional data in userInfo
        }
    }
}
```
If you have multiple players you can determine the player that sent the notification by checking notification.object 

If you want to receive all notifications from the player, there is a convenience function:

##### Swift

```swift
playerView.addObserverForAllNotifications(observer, selector:”notificationReceived:”)
```

##### Objective-C

```objective-c
[playerView addObserverForAllNotifications:self selector:@"notificationReceived:"];
``` 
Whenever a notification from playerView is received by the observer, the function `notificationReceived:` is called. With `notification.name` you can determine which notification was received and act accordingly.
                                                                                          

## Further information

### Fullscreen

When the player switches to fullscreen, a subview (containing the video and all controls) of the PlayerView is added to the applications key window `UIApplication.sharedApplication().keyWindow`. Once the user switches back, the subview is added back to the PlayerView.

### Orientation

When the device is rotated, the video automatically rotates accordingly.

### Airplay and Picture in Picture support

The player does support Airplay and PiP, if it is also supported by the device. Furthermore the __Background Modes__ capability _Audio, Airplay and Picture in Picture_ must be activated in your project settings in Xcode.


## Changelog

### v5.9.89
- reporting enhanced
- interface methods added: startPlayByGlobalID() and startPlayByForeignReference()
- media url creation enhanced

Compiled with XCode 11.3.1 (Swift 5.1)

### v5.9.88
- reporting enhanced
- new cdn types added
- api update
- media url creation enhanced

Compiled with XCode 11.3.1 (Swift 5.1)

### v5.9.87
- Google IMA SDK update
- reporting enhanced: contextReference can be set by a public function and will be sent with every event

Compiled with XCode 11.0 (Swift 5.1)

### v5.9.86
- player skin improvements
- reporting enhanced
- ad reporting enhanced
- dailyMe SDK dependency removed
- advertisement URL creation updated

Compiled with XCode 10.3 (Swift 5.0)

### v5.9.85
- reporting enhanced: SDK version added to events
- hls stream creation updated
- new hotspot types added
- VAST parsing improved

Compiled with XCode 10.3 (Swift 5.0)

### v5.9.84
- reporting improved: SDK version added to events
- story mpde integrated
- adMode attribute considered in collections

Compiled with XCode 10.3 (Swift 5.0)

### v5.9.83
- reporting improved
- scene selection added
- subtitle parsing improved

Compiled with XCode 10.2.1 (Swift 5.0)

### v5.9.82
- reporting improved
- notification 'EndedAll' added
- new skin 'Glass66' added
- speed selection added
- ad reporting bugfixes

Compiled with XCode 10.2.1 (Swift 5.0)

### v5.9.81
- preview mode enhanced
- reporting improved

Compiled with XCode 10.2.1 (Swift 5.0)

### v5.9.80
- UI and UX improvements
- different exit hotspot possible
- reporting enhanced

Compiled with XCode 10.2.1 (Swift 5.0)
