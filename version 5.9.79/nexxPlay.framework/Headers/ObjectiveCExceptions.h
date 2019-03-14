//
//  ObjectiveCExceptions.h
//  nexxPlay
//
//  Created by Daniel Leberle on 24/11/2016.
//  Copyright © 2016 nexx. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ObjectiveCExceptions : NSObject

+ (BOOL)catchException:(void(^)())tryBlock error:(__autoreleasing NSError **)error;

@end
