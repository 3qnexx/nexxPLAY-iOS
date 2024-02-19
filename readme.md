# nexxPLAY iOS 

## Player documentation

Please find the complete documentation of the nexxPLAY iOS SDK following this [link](https://play.docs.nexx.cloud/native-players/nexxplay-for-ios)

## Widget documentation

Please find the complete documentation of the nexxPLAY Widget following this [link](https://play.docs.nexx.cloud/widgets/widgets-for-native-apps/ios-widget)

## Changelog

### v6.4.6
- adding chapters for audio
- refactoring reporting
- update IMA SDK

Compiled with XCode 15.0 (Swift 5.9)

### v6.4.5
- adding Support for enhanced Content-Moderated Metadata
- adding Support for 3Q CDP LiveStreams
- added Support for Campaigns
- update IMA SDK

Compiled with XCode 15.0 (Swift 5.9)

### v6.4.4
- enhance reporting
- add support for right to left languages
- add option for muted start

Compiled with XCode 14.2 (Swift 5.7)

### v6.4.3
- update to iOS 16
- update to the latest Google IMA SDK integration (v3.17)
- remove _adType_ and all variables regarding banner from the configuration model
- remove _captionMode_ from the configuration model
- replace interface method _getCaptions_ with _getTextTracks_ that returns all text tracks
- remove player skins

Compiled with XCode 14.0.1 (Swift 5.7)

### v6.4.2
- add accessibility feature voice over
- include caption styles defined in the iOS settings

Compiled with XCode 13.4.1 (Swift 5.6.1)

### v6.4.02

- remove interface methods _getCaptionLanguages()_ and _getAudioLanguages()_
- rename interface method _getCaptionData()_ to _getCaptions_
- add interface methods _getCurrentMediaParent()_ and _getAudioTracks()_
- enhance captions
- add haptic feedback for some interactions

Compiled with XCode 13.3.1 (Swift 5.6.1)

### v6.4.01

- UI fixes

Compiled with XCode 13.2.1 (Swift 5.5.2)

### v6.4.0

- new config values  _adVASTTimeout_ and _adMediaTimeout_  
- new hotspot types added
- add low data mode
- modify user info in notifications
- enhance _getMediaData()_ call
- rename widget configuration objects
- new playmode _scenelist_
- rename _MetadataLoaded_ notification to _Metadata_
- rewrite getMediaData() function to getCurrentMedia() and getCurrentPlaybackState()
- rename _DownloadSuccess_ notification to _DownloadReady_

Compiled with XCode 13.1 (Swift 5.5.1)
