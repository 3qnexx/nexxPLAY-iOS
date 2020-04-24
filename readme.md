# nexxPLAY iOS 

## Latest version

### v6.0.2
- UI updates
- new skin "simple" added
- bitcode support added
- podcast sharing added
- reporting enhanced
- URL creation adapted 

Compiled with XCode 11.4 (Swift 5.2)

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

```swift
import UIKit
import nexxPlay

class ViewController: UIViewController {

    override func viewDidLoad() { 
        super.viewDidLoad()
        let player = NexxPLAYView(frame: CGRect(x: 0, y: 0, width: 300, height: 300)) view.addSubview(v_player)
        player.setEnvironment(NexxPLAYEnvironment(client: "1"))
        player.startPlay(streamType: "video", mediaID: "12345", configuration: NexxPLAYConfiguration())
    }
}
```

#### removing a player instance

As soon as the PlayerView is deallocated, the player will automatically stop.

## Environment

The NexxPLAYEnvironment object contains global settings for the player object. Except for the `client` all the settings are optional and have a predefined value. The settings are:

•    `client:String` = the ID of the client (mandatory)                 
•    `sessionID:String` = the ID of the current session (default is "0")                 
•    `language:String?` = an override for the system language to get language specific data from the backend (e.g. "en")                 
•    `userHash:String` = the hash of the current user (default is "")                 
•    `affiliatePartner:Int` = the ID of the affiliate partner regarding the tracking (default is 0)                 
•    `playLicensePartner:Int` = the ID of the play license partner for the backend (default is 0)                 
•    `contextReference:String` = the context reference for reporting (default is "")                 
•    `foceSSL:Bool` = defines whether URLs are created with SSL (defualt is true)                 
•    `trackingOptOuted:Bool` = defines whether tracking is allowed or not (default is false)                 
•    `cordovaEnabled:Bool` = set this option to true if you run the SDK in a cordova app (default is false)                 
•    `alwaysInFullscreen:Bool` = tell the SDK whether you show the player in fullscreen or not (defualt is false)                 
•    `showCloseButtonOnFullscreen:Bool` = defines whether to show the close button in fullscreen mode or not (default is true)                 
•    `googleIMAReferenceViewController:UIViewController?` = the Google IMA SDK presents the advertisement modally on a UIViewController once the user taps the video ad. If the Google IMA SDK is used but no view controller is set, the advertisement will open in Safari (default is `nil`)                 

## Configuration

The NexxPLAYConfiguration object contains settings regarding the player UI and behaviour. All the settings are optional and have a predefined value. The settings object will be set via the various `startPlay` methods. The settings are:

•    `dataMode:String` = can be "api" or "static" (defualt is "api")                 
•    `backgroundColor:UIColor` = defines the background color of the player if the background is visible due to the media format (defualt is black)                 
•    `loaderSkin:String` = defines the loading animation, can be "default" or "doublebounce" (default is "default")                 
•    `hidePrevNext:Int` = overrides the visiblity of the previous and next buttons for lists (default is 0, can be 0 or 1)                 
•    `autoPlay:Int` = if set to 0 or 1, the API information will be overwritten and the media starts automatically (1) or not (0) (default is -1)                 
•    `autoNext:Int` = if set to 0 or 1, the API information will be overwritten and the player shows the next media elements (1) or not (0) after the media stopped (default is -1)                 
•    `exitMode:String` = overrides the APIs exitMode after the video. The different modes are "replay" (no exit page, only a replay button in the center), "navigate" (presents an exit page), "playlist" ( nothing is shown) (default is "")                 
•    `titleMode:Int` = overrides the APIs mode of the video titles. The titles can be hidden (0), always visible (1) or only visible when the player is fullscreen (2) (default is -1)                 
•    `menuMode:Int` = overrides the APIs setting defining whether the menu is never visible (0), visible on tap (1) or always visible (2) (default is -1)                 
•    `captionMode:String` = overrides the APIs caption mode for the player. Possible values are "none", "select", "selectandstart" and "always" (default is "")                 
•    `watermarkMode:Int` = overrides the APIs setting to show(1) or hide(1) the watermarks (default is -1)                 
•    `delay:Double` = start the media at a specific spot (default is 0)                 
•    `startPosition:Int` = start a playlist at a specific index (default is 0)                 
•    `adProvider:String` = overrides the APIs ad provider setting (default is "")                 
•    `adType:String` = overrides the APIs ad type setting (default is "")                 
•    `adPrerollURL:String` = overrides the APIs ad preroll URL (default is "")                 
•    `adMidrollURL:String` = overrides the APIs ad midroll URL (default is "")                 
•    `adPostrollURL:String` = overrides the APIs ad postroll URL (default is "")                 
•    `adBannerURL:String` = overrides the APIs ad banner URL (default is "")                 
•    `adMidrollInterval:Int` = overrides the APIs ad midroll intervall setting (default is -1)                 
•    `adBannerInterval:Int` = overrides the APIs ad banner intervall setting (default is -1)                 
•    `disableAds:Int` = overrides the APIs setting to disable all ads if set to 1 (default is 0)                 
•    `disablePrerolls:Int` = overrides the APIs setting to disable preroll ads if set to 1 (default is 0)                 
•    `disableMidrolls:Int` = overrides the APIs setting to disable midroll ads if set to 1 (default is 0)                 
•    `disablePostrolls:Int` = overrides the APIs setting to disable postroll ads if set to 1 (default is 0)                 
•    `disableBanners:Int` = overrides the APIs setting to disable banner ads if set to 1 (default is 0)                 
•    `enableInteractions:Int` = if set to 0, several sidebar buttons are disabled (default is 1)                 
•    `enableScenes:Int` = if set to 0, the scene selection will not be shown in the sidebar (default is 1)                 
•    `enableSidebar:Int` = if set to 0, the sidebar will not be shown (default is 1)                 
•    `enableAirPlay:Int` = overrides the APIs setting to show(1) or hide(1) the airplay option (default is -1)                 
•    `enableFullscreen:Int` = if set to 0, the fullscreen button will not be shown (default is 1)                 
•    `enableAutoResume:Int` = if set to 0, the auto resume feature is disabled (default is 1)                 
•    `webURLReference:Int` = set the web reference for reporting                 
•    `streamingFilter:String` = overrides the APIs streaming filter (default is "")                                  
•    `startedVia:String` = overrides session call reason for reporting (default is "")                 

## Public methods

The following methods can be used to start and control the player:

#### setEnvironment(environment:NexxPLAYEnvironment)
Sets the environment object for the player. This method __must__ be called before any start method is called

#### startPlay(streamType:String, mediaID:String, configuration:NexxPLAYConfiguration)
Initial method to get the client data, ad data and video data

#### startPlayWithGlobalID(globalID:String, configuration:NexxPLAYConfiguration)
Initial method to get the client data, ad data and video data via a global ID

#### startPlayWithRemoteMedia(streamType:String, reference:String, provider:String, configuration:NexxPLAYConfiguration)
Initial method to get the client data, ad data and video data of a remote media

#### play()
The player starts/continues playing.

#### pause()
The player pauses.

#### toggle()
The player pauses if playing, otherwise starts.

#### mute()
The player is muted.

#### unmute()
The player is unmuted.

#### seekTo(time:Float)
The current media is set to the defined position (in seconds).

#### seekBy(time:Float)
The current media seeked by the defined time (in seconds).

#### next()
The player plays the next media in a list.

#### previous()
The player plays the previous media in a list.

#### swapToPosition(position:Int)
The player switches to the media at the defined position in a list.

#### swapToMediaItem(mediaID:String, streamType:String? = nil,  startPosition:Int = 0, delay:Double = 0) 
The player reloads the media data and plays the new data.

#### swapToGlobalID(globalID:String, startPosition:Int = 0, delay:Double = 0) 
The player reloads the media data given a global ID and plays the new data.

#### swapToRemoteMedia(reference:String, provider:String, delay:Double = 0) 
The player reloads the media data given a remote referenc and plays the new data.

#### getMediaData() -> [String:String] 
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
* `mediaSession` The session id of the current video      
* `mediaSessionParent` The parent id of the current video     
* `currentDuration` The duration the player is playing. Can be different to currentTime if the user skips seconds or jumps to other timestamps     
* `currentTime` The current timestamp of the playing video     
* `streamType` The stream type     
* `isAutoPlay` Defining whether the video was started automatically (_1_ or _0_)

If there is no current video, the method returns an empty dictionary. If the dictionary is not empty, the attributes mediaID, hash and title are set. All other attributes are optional and may not be available.

#### getCaptionData(language:String? = nil) -> [String:String]
Use this method to retrieve the captions of a media element. If there is no current element or the element does not contain captions, this method returns nil. In case you want to get captions for a specific language, you can set the 2 digit language code as parameter.

#### getCurrentTime() -> Float
The player returns the current playback time.

#### isPlaying() -> Bool 
The player returns if a media element is currently playing

#### isPlayingAd() -> Bool 
The player returns if an ad is currently playing

#### isMuted() -> Bool 
The player returns if it is muted

#### isInPiP() -> Bool
The player returns if it is in picture in picture mode

#### clearCache()
The data received by the nexxPlay API is cached for 30 minutes. Call this method to clear the cache manually. 

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

```swift
NSNotificationCenter.defaultCenter().addObserver(self, selector: "notificationReceived:", name: nexxPlay.nexxPlayErrorNotification, object: playerView)
```
The appropriate function that is called when the notification is received:

```swift
@objc func notificationReceived(notification:NSNotification) {
    println(notification.name)        // prints “NexxPlayErrorNotification”
    if notification.name == nexxPlay.nexxPlayPlayPosNotification, let userInfo = notification.userInfo {
        // use the additional data in userInfo
        
    }
}
```

If you have multiple players you can determine the player that sent the notification by checking notification.object 

If you want to receive all notifications from the player, there is a convenience function:

```swift
playerView.addObserverForAllNotifications(observer, selector:”notificationReceived:”)
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

### v6.0.1
- minor UI updates
- media URL creation for remote audio enhanced

Compiled with XCode 11.4 (Swift 5.2)

### v6.0.0
- intreface rewrite
- minor UI updates
- media URL creation enhanced

Compiled with XCode 11.4 (Swift 5.2)

### v5.9.90
- internal renaming
- interface method renamed: startPlayByForeignReference() is now startByRemoteMedia

Compiled with XCode 11.3.1 (Swift 5.1)

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
