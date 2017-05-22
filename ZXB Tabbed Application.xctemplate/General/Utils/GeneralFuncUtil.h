//
//  GeneralFuncUtil.h
//  HousingEstate
//
//  Created by 周小斌 on 2017/5/15.
//  Copyright © 2017年 ZhouXiaobin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GeneralFuncUtil : NSObject

/**
 获取纯色图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;


/**
 linux时间戳
 */
+ (NSString *)timeIntervalWithDate:(NSDate *)date;


/**
 手机号有效
 */
+ (BOOL)isValidateMobile:(NSString *)mobile;


/**
 邮箱有效
 */
+ (BOOL)isValidateEmail:(NSString *)email;

@end
