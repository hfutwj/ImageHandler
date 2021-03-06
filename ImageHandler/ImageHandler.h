//
//  ImageHandler.h
//  ImageHandler
//
//  Created by 吴健 on 2018/7/11.
//  Copyright © 2018年 吴健. All rights reserved.
//

#ifndef ImageHandler_h
#define ImageHandler_h

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 分离YUV420文件的Y分量和UV分量，并分别保存到对应的文件中去
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DepartY_UV(char* src_path, int srcWidth, int srcHeight);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 根据输入的区域将YUV420文件进行裁剪，目前只支持NV12和NV21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CropYUV420(char* src_path, int srcWidth, int srcHeight, int left, int top, int desWidth, int desHeight);

#endif /* ImageHandler_h */
