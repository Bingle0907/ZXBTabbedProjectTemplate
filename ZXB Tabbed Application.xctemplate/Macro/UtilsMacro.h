//
//  UtilsMacro.h
//  HousingEstate
//
//  Created by 周小斌 on 2017/5/12.
//  Copyright © 2017年 ZhouXiaobin. All rights reserved.
//

#ifndef UtilsMacro_h
#define UtilsMacro_h

#ifdef DEBUG

#define ATLog(FORMAT, ...) fprintf(stderr,"%s\n",[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);

#else

#define ATLog(fmt, ...) /* */

#endif

#define ATError(domain,errorCode,description) [NSError errorWithDomain:domain code:errorCode userInfo:@{NSLocalizedDescriptionKey : description }];

#define IS_IPHONE_5_5 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )736 ) < DBL_EPSILON )
#define IS_IPHONE_4_7 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )667 ) < DBL_EPSILON )
#define IS_IPHONE_4_0 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#define IS_IPHONE_3_5 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )480 ) < DBL_EPSILON )

// 定义颜色简便方法
#define RGB(r,g,b)        [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:1.f]
#define RGBA(r,g,b,a)     [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:a]
#define RGBAHEX(hex,a)    RGBA((float)((hex & 0xFF0000) >> 16),(float)((hex & 0xFF00) >> 8),(float)(hex & 0xFF),a)

#define IMAGENAMED(file)            [UIImage imageNamed:file]

// 定义系统版本比对方法
#define COMPARE_SYSTEM_VERSION(v)                   ([[[UIDevice currentDevice] systemVersion] compare:(v) options:NSNumericSearch])
#define SYSTEM_VERSION_EQUAL_TO(v)                  (COMPARE_SYSTEM_VERSION(v) == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              (COMPARE_SYSTEM_VERSION(v) == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  (COMPARE_SYSTEM_VERSION(v) != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 (COMPARE_SYSTEM_VERSION(v) == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     (COMPARE_SYSTEM_VERSION(v) != NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO_7_0 (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0"))
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO_8_0 (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0"))
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO_9_0 (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"9.0"))

#define UIViewAutoresizingWidthAndHeight       UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight
#define UIViewAutoresizingAll               UIViewAutoresizingFlexibleLeftMargin| \
UIViewAutoresizingFlexibleWidth|\
UIViewAutoresizingFlexibleRightMargin|\
UIViewAutoresizingFlexibleTopMargin|\
UIViewAutoresizingFlexibleHeight|\
UIViewAutoresizingFlexibleBottomMargin
//屏幕尺寸
#define KScreenWidth [UIScreen mainScreen].bounds.size.width
#define KScreenHeight [UIScreen mainScreen].bounds.size.height

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

#define Alert(title,msg)  [[[UIAlertView alloc] initWithTitle:title message:msg delegate:self cancelButtonTitle:NSLocalizedString(@"OK", nil) otherButtonTitles:nil, nil] show];

//单例模式
#define SYNTHESIZE_SINGLETON_FOR_HEADER(className) \
\
+ (className *)shared##className;
#define SYNTHESIZE_SINGLETON_FOR_CLASS(className) \
\
+ (className *)shared##className { \
static className *shared##className = nil; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
shared##className = [[self alloc] init]; \
}); \
return shared##className; \
}

#define DegreesToRadian(x)      (M_PI * (x) / 180.0)
#define RadianToDegrees(radian) (radian*180.0)/(M_PI)

#define FileManager     [NSFileManager defaultManager]
#define Appdelegate     ((AppDelegate *)[[UIApplication sharedApplication] delegate])
#define KeyWindow       [[UIApplication sharedApplication] keyWindow]
#define UserDefault     [NSUserDefaults standardUserDefaults]

#define DocumentDirectory   [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define Directory(NSSearchPathDirectory) [NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory, NSUserDomainMask, YES) objectAtIndex:0]

#define LOADNIBWITHNAME(CLASS, OWNER) [[[NSBundle mainBundle] loadNibNamed:CLASS owner:OWNER options:nil] lastObject]

#define GCDBackAsync(block)   dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define GCDMainAsync(block)   dispatch_async(dispatch_get_main_queue(),block)

#define SystemVersion   [[UIDevice currentDevice] systemVersion]
#define CurrentLanguage [[NSLocale preferredLanguages] objectAtIndex:0]

#define ViewWidth(v)                        v.frame.size.width
#define ViewHeight(v)                       v.frame.size.height
#define ViewX(v)                            v.frame.origin.x
#define ViewY(v)                            v.frame.origin.y

#define SelfViewWidth                       self.view.bounds.size.width
#define SelfViewHeight                      self.view.bounds.size.height

#define RectX(rect)                            rect.origin.x
#define RectY(rect)                            rect.origin.y
#define RectWidth(rect)                        rect.size.width
#define RectHeight(rect)                       rect.size.height

#define RectSetWidth(rect, w)                  CGRectMake(RectX(rect), RectY(rect), w, RectHeight(rect))
#define RectSetHeight(rect, h)                 CGRectMake(RectX(rect), RectY(rect), RectWidth(rect), h)
#define RectSetX(rect, x)                      CGRectMake(x, RectY(rect), RectWidth(rect), RectHeight(rect))
#define RectSetY(rect, y)                      CGRectMake(RectX(rect), y, RectWidth(rect), RectHeight(rect))

#define RectSetSize(rect, w, h)                CGRectMake(RectX(rect), RectY(rect), w, h)
#define RectSetOrigin(rect, x, y)              CGRectMake(x, y, RectWidth(rect), RectHeight(rect))

#pragma mark -
#pragma mark iOS Version

#define IOS_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define IOS_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define IOS_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define IOS_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define IOS_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#pragma mark -
#pragma mark Syntactic sugar

#define NOT_ANIMATED NO
#define ANIMATED YES

#pragma mark -
#pragma mark UIColor

// example usage: UIColorFromHex(0x9daa76)
#define UIColorFromHexWithAlpha(hexValue,a) [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0 green:((float)((hexValue & 0xFF00) >> 8))/255.0 blue:((float)(hexValue & 0xFF))/255.0 alpha:a]
#define UIColorFromHex(hexValue)            UIColorFromHexWithAlpha(hexValue,1.0)
#define UIColorFromRGBA(r,g,b,a)            [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define UIColorFromRGB(r,g,b)               UIColorFromRGBA(r,g,b,1.0)

#pragma mark -
#pragma mark Collections

#define IDARRAY(...) (id []){ __VA_ARGS__ }
#define IDCOUNT(...) (sizeof(IDARRAY(__VA_ARGS__)) / sizeof(id))

#define ARRAY(...) [NSArray arrayWithObjects: IDARRAY(__VA_ARGS__) count: IDCOUNT(__VA_ARGS__)]

#define DICT(...) DictionaryWithIDArray(IDARRAY(__VA_ARGS__), IDCOUNT(__VA_ARGS__) / 2)

#define POINTERIZE(x) ((__typeof__(x) []){ x })
#define NSVALUE(x) [NSValue valueWithBytes: POINTERIZE(x) objCType: @encode(__typeof__(x))]

#pragma mark -
#pragma mark Blocks

#define BLOCK_SAFE_RUN(block, ...) block ? block(__VA_ARGS__) : nil

#pragma mark -
#pragma mark Logging

#define LOG(fmt, ...) NSLog(@"%s: " fmt, __PRETTY_FUNCTION__, ## __VA_ARGS__)

#ifdef DEBUG
#define INFO(fmt, ...) LOG(fmt, ## __VA_ARGS__)
#else
// do nothing
#define INFO(fmt, ...)
#endif

#define ERROR(fmt, ...) LOG(fmt, ## __VA_ARGS__)
#define TRACE(fmt, ...) LOG(fmt, ## __VA_ARGS__)

#define METHOD_NOT_IMPLEMENTED() NSAssert(NO, @"You must override %@ in a subclass", NSStringFromSelector(_cmd))

#pragma mark -
#pragma mark NSNumber

#define NUM_INT(int) [NSNumber numberWithInt:int]
#define NUM_FLOAT(float) [NSNumber numberWithFloat:float]
#define NUM_BOOL(bool) [NSNumber numberWithBool:bool]

#pragma mark -
#pragma mark Frame Geometry

#define CENTER_VERTICALLY(parent,child) floor((parent.frame.size.height - child.frame.size.height) / 2)
#define CENTER_HORIZONTALLY(parent,child) floor((parent.frame.size.width - child.frame.size.width) / 2)

// example: [[UIView alloc] initWithFrame:(CGRect){CENTER_IN_PARENT(parentView,500,500),CGSizeMake(500,500)}];
#define CENTER_IN_PARENT(parent,childWidth,childHeight) CGPointMake(floor((parent.frame.size.width - childWidth) / 2),floor((parent.frame.size.height - childHeight) / 2))
#define CENTER_IN_PARENT_X(parent,childWidth) floor((parent.frame.size.width - childWidth) / 2)
#define CENTER_IN_PARENT_Y(parent,childHeight) floor((parent.frame.size.height - childHeight) / 2)

#define WIDTH(view) view.frame.size.width
#define HEIGHT(view) view.frame.size.height
#define X(view) view.frame.origin.x
#define Y(view) view.frame.origin.y
#define LEFT(view) view.frame.origin.x
#define TOP(view) view.frame.origin.y
#define BOTTOM(view) (view.frame.origin.y + view.frame.size.height)
#define RIGHT(view) (view.frame.origin.x + view.frame.size.width)

#pragma mark -
#pragma mark IndexPath

#define INDEX_PATH(a,b) [NSIndexPath indexPathWithIndexes:(NSUInteger[]){a,b} length:2]

#define ALWAYS_TRUE YES ||
#define NEVER_TRUE NO &&

#pragma mark -
#pragma mark Screen size

#define SCREEN_WIDTH [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height

#pragma mark -
#pragma mark Device type.
// Corresponds to "Targeted device family" in project settings
// Universal apps will return true for whichever device they're on.
// iPhone apps will return true for iPhone even if run on iPad.

#define TARGETED_DEVICE_IS_IPAD UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad
#define TARGETED_DEVICE_IS_IPHONE UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone

/**
 *  弱引用
 */
#define weakSelf(object)            __weak typeof(object) weakSelf = object
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

#endif /* UtilsMacro_h */
