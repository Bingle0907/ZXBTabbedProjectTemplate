//
//  NSObject+NSJSONSerialization.h
//  HousingEstate
//
//  Created by 周小斌 on 2017/5/15.
//  Copyright © 2017年 ZhouXiaobin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (NSJSONSerialization)

- (NSString *)mtJSONString;

@end

@interface NSData (NSJSONSerialization)

- (id)mtObjectFromJSON;

@end

@interface NSString (NSJSONSerialization)

- (id)mtJSONValue;

@end
