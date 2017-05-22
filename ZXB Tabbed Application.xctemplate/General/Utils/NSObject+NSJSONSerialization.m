//
//  NSObject+NSJSONSerialization.m
//  HousingEstate
//
//  Created by 周小斌 on 2017/5/15.
//  Copyright © 2017年 ZhouXiaobin. All rights reserved.
//

#import "NSObject+NSJSONSerialization.h"

@implementation NSObject (NSJSONSerialization)

- (NSString *)mtJSONString
{
    NSError *error = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:self
                                                       options:0
                                                         error:&error];
    if ([jsonData length] > 0 && error == nil) {
        return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    } else {
        return nil;
    }
}

@end

@implementation NSData (NSJSONSerialization)

- (id)mtObjectFromJSON
{
    if (![NSJSONSerialization isValidJSONObject:self]) {
        NSError *error = nil;
        id objectJson = [NSJSONSerialization JSONObjectWithData:self options:NSJSONReadingMutableContainers error:&error];
        if (error) {
            return nil;
        } else {
            return objectJson;
        }
    } else {
        return self;
    }
}

@end

@implementation NSString (NSJSONSerialization)

- (id)mtJSONValue
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    if (data) {
        __autoreleasing NSError* error = nil;
        id result = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&error];
        if (error != nil) return nil;
        return result;
    } else {
        return nil;
    }
}

@end

