//
//  DefineMacro.h
//
//  Created by 张勇杰 on 15/5/2.
//  Copyright © 2015年 YJ. All rights reserved.
//

//文件目录
#define PathTemp NSTemporaryDirectory()
#define PathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define PathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define PathFile(fileName) [kPathDocument stringByAppendingPathComponent:(fileName)]

// 属性的存取
#define DEFAULTS_INFO(_OBJECT, _NAME) [[NSUserDefaults standardUserDefaults] setObject:_OBJECT forKey:_NAME]
#define DEFAULTS_SYNCHRONIZE [[NSUserDefaults standardUserDefaults] synchronize]

// 根据iPhone6的屏幕来适配不同屏幕的像数
#define PixelValue(number) (number) / 750.f * [[UIScreen mainScreen] bounds].size.width

// 获取屏幕的宽高
#define ScreenW [[UIScreen mainScreen] bounds].size.width
#define ScreenH [[UIScreen mainScreen] bounds].size.height

// 替换系统自带的Log，增加文件名，文件行数，函数名
#define NSLog(format, ...) do {                                                                          \
fprintf(stderr, "<%s : %d> %s  ",                                           \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
__LINE__, __func__);                                                        \
(NSLog)((format), ##__VA_ARGS__);                                           \
} while (0)

// 单例.h文件
#define SingletonClassH(name) + (instancetype)shared##name;

// 单例.m文件
#define SingletonClassM(name) \
static id _instance; \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
\
+ (instancetype)shared##name { \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone { \
return _instance; \
}

// 判断是否使用了ARC，做不同操作
#if __has_feature(objc_arc)
// compiling with ARC
#else
// compiling without ARC
#endif
