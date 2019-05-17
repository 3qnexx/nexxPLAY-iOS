#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface SLCCryptedAssetResourceLoaderDelegate : NSObject<AVAssetResourceLoaderDelegate>

- (instancetype)initWithStreaming:(BOOL)stream withAESCrypt:(BOOL)aesCrypt stopDownload:(BOOL)stopDownload  playlistFileSize: (UInt64)playlistFileSize streamingUrl:(NSURL *) streamingUrl localPath:(NSString *)localPath  key:(NSString *) key;

@end
