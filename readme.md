# nexxPLAY iOS 

## Changelog

#### v5.9.78
- getMediaData() also works after error notifications now
- offline improvements
- revolver play improvements

Compiled with XCode 10.1 (Swift 4.2)

#### v5.9.77
- URL encoding enhanced
- CMAF support added
- Hotspots enhanced
- Exit preview added

Compiled with XCode 10.1 (Swift 4.2)

#### v5.9.76
- URL encoding enhanced
- exit reporting added
- public method getMediaData() enhanced
- Seekbar image preview improved

Compiled with XCode 10 (Swift 4.2)

#### v5.9.75
- URL encoding enhanced
- Information to the user when the device is offline while streaming
- Simple hotspot support added

Compiled with XCode 10 (Swift 4.2)

#### v5.9.74
- Reporting improved
- Showing thumbs (if available) when seeking through the media with a pan gesture
- support for bumper added

Compiled with XCode 9.4.1 (Swift 4.1)

#### v5.9.73
- Reporting improved
- download2go added to nexxPLAY

Compiled with XCode 9.4.1 (Swift 4.1)

#### v5.9.72
- Reporting improved
- Google IMA improvement for midrolls
- Age restriction info screen added
- New seek icon options

Compiled with XCode 9.4.1 (Swift 4.1)

#### v5.9.71
- Ad reporting enhanced
- Age restriction UI added
- Reporting enhanced

Compiled with XCode 9.4.1 (Swift 4.1)


#### v5.9.70
- Google IMA update bugfixes
- Ad reporting enhanced
- Some public methods simplified

Compiled with XCode 9.4.1 (Swift 4.1)

## Integration

#### nexxPLAY

1. In Xcode, select your project, select your target and open the tab “General”
2. Drag the nexxPlay.framework file from the Finder to the “Embedded Binaries” section
3. Please make sure that the framework is also included in “Linked Frameworks and Libraries”
4. Change your tab to “Build Phases”
5. Drag the nexxPlay.bundle from the Finder to the “Copy Bundle resources”
6. Still in “Build Phases”, click on the “+“ icon and add a new run script phase
7. Copy the code from the file “strip-framework.sh” into the run script phase. Please make sure that this run script phase is the last phase of the build process!
8. IMPORTANT CHANGE IN XCODE 8, ONLY Objective-C: Change your tab to “Build Settings” and make sure that “Always Embed Swift Standard Libraries” is set to “YES” (the default value is “NO”)

#### 3rd party frameworks

nexxPLAY contains presenting video ads via the Google IMA SDK and from v5.9.73 also the possiblity to download media files in order to watch videos when the device is offline. Therefore two additional SDKs need to be added to the project:

- GoogleInteractiveMediaAds.framework
- DailymeSdk.framework

Please drag these frameworks into the "Embedded Binaries" section of your target (exactely as explained for the nexxPLAY framework in steps 1 and 2) and make sure they also appear in the "Linked Frameworks and Libraries" section (nexxPLAY integration step 3).













