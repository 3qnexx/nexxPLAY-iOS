//
//  SafeUnarchiver.h
//  nexxPlay
//
//  Created by Daniel Leberle on 24/11/2016.
//  Copyright © 2016 nexx. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SafeUnarchiver : NSObject
+(NSObject* _Nullable)unarchive:(NSData* _Nonnull)data;
@end
