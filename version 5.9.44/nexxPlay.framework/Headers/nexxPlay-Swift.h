// Generated by Apple Swift version 3.1 (swiftlang-802.0.53 clang-802.0.42)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if defined(__has_attribute) && __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import CoreGraphics;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSCoder;
@class UIViewController;

SWIFT_CLASS("_TtC8nexxPlay10PlayerView")
@interface PlayerView : UIView
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (void)startPlay:(NSString * _Nonnull)sessionID client:(NSString * _Nonnull)client playmode:(NSString * _Nonnull)playmode param:(NSString * _Nonnull)param startPosition:(double)startPosition startItem:(NSInteger)startItem;
- (void)swap:(NSString * _Nonnull)param;
- (void)swapToPos:(NSString * _Nonnull)newParam;
- (void)swapComplex:(NSString * _Nonnull)playMode param:(NSString * _Nonnull)param startPosition:(double)startPosition startItem:(NSInteger)startItem;
- (void)setDelay:(double)delay;
- (void)seek:(NSInteger)time;
- (void)play;
- (void)pause;
- (void)mute;
- (void)unmute;
- (void)overrideMenu:(NSInteger)visibility;
- (void)overrideAutoPlay:(BOOL)autoPlayMode;
- (void)overrideStartMuted:(BOOL)startMuted;
- (void)overrideExitMode:(NSString * _Nonnull)exitMode;
- (void)overrideAutoNext:(BOOL)autoNext;
- (void)overridePreroll:(NSString * _Nonnull)url;
- (void)overrideMidroll:(NSString * _Nonnull)url interval:(NSInteger)interval;
- (void)overrideBanner:(NSString * _Nonnull)url interval:(NSInteger)interval;
- (void)overridePostroll:(NSString * _Nonnull)url;
- (void)overrideTitles:(NSInteger)visibility;
- (void)overrideAdProvider:(NSString * _Nonnull)provider;
- (void)overrideAdType:(NSString * _Nonnull)adType;
- (void)overrideVASTData:(NSString * _Nonnull)provider prerollURL:(NSString * _Nonnull)prerollURL midrollURL:(NSString * _Nonnull)midrollURL midrollInterval:(NSInteger)midrollInterval bannerURL:(NSString * _Nonnull)bannerURL bannerInterval:(NSInteger)bannerInterval postRollURL:(NSString * _Nonnull)postRollURL adType:(NSString * _Nonnull)adType;
- (NSDictionary<NSString *, NSString *> * _Nonnull)getMediaDataWithGetEnhanced:(BOOL)getEnhanced SWIFT_WARN_UNUSED_RESULT;
- (void)addObserverForAllNotifications:(id _Nonnull)observer selector:(NSString * _Nonnull)selector;
- (void)removeObserverForAllNotifications:(id _Nonnull)observer;
- (void)checkPayment;
- (void)enableCordova;
- (void)clearCache;
- (void)setPlayerBackgroundColor:(NSString * _Nonnull)backgroundColor;
- (void)setDatamode:(NSString * _Nonnull)mode;
- (void)setGoogleIMAReferenceViewController:(UIViewController * _Nonnull)viewController;
- (void)setWebURLRepresentation:(NSString * _Nonnull)url;
- (void)setViewParentID:(NSString * _Nonnull)mode;
- (void)setPlayLicense:(NSInteger)playLicense;
- (void)setLoaderSkin:(NSString * _Nonnull)skin;
- (void)setSessionCallReason:(NSString * _Nonnull)reason;
- (void)setDeviceID:(NSString * _Nonnull)deviceID;
- (void)setStreamingFilter:(NSString * _Nonnull)filter;
- (float)getCurrentTime SWIFT_WARN_UNUSED_RESULT;
- (void)setUserHash:(NSString * _Nonnull)userHash;
- (void)overrideCaptionMode:(NSString * _Nonnull)mode;
- (void)disableAds:(BOOL)disablePre disableMid:(BOOL)disableMid disableBanner:(BOOL)disableBanner disablePost:(BOOL)disablePost;
@end


@interface UIButton (SWIFT_EXTENSION(nexxPlay))
@end


@interface UILabel (SWIFT_EXTENSION(nexxPlay))
@end

#pragma clang diagnostic pop
