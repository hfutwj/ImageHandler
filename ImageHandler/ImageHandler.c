//
//  ImageHanler.c
//  ImageHandler
//
//  Created by 吴健 on 2018/7/11.
//  Copyright © 2018年 吴健. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 分离YUV420文件的Y分量和UV分量，并分别保存到对应的文件中去
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DepartY_UV(char* src_path, int srcWidth, int srcHeight) {
    FILE* srcFile = NULL;
    FILE* desFile_Y = NULL;
    FILE* desFile_UV = NULL;
    //文件长度
    int filelen = srcWidth*srcHeight*3/2;
    int filelen_y = srcWidth*srcHeight;
    int filelen_uv = filelen-filelen_y;
    int read_count = 0;
    
    //读取源图像文件，目前只支YUV420格式
    srcFile = fopen(src_path, "rb+");
    if(srcFile == NULL)
        return;
    
    //为源图像文件的Y分量和UV分量分配相应大小的内存块
    unsigned char* srcBuffer_Y = (unsigned char*)malloc(srcWidth*srcHeight);
    unsigned char* srcBuffer_UV = (unsigned char*)malloc(srcWidth*srcHeight/2);
    
    //读取Y分量数据内容
    read_count = fread(srcBuffer_Y, 1, filelen_y, srcFile);
    if (read_count == filelen_y) {
        desFile_Y = fopen("image_y.yuv", "w");
        if (desFile_Y != NULL) {
            fwrite(srcBuffer_Y, 1, filelen_y, desFile_Y);
        }
    }
    
    //读取UV分量的数据内容
    read_count = fread(srcBuffer_UV, 1, filelen_uv, srcFile);
    if (read_count == filelen_uv) {
        desFile_UV = fopen("image_uv.yuv", "w");
        if (desFile_UV != NULL) {
            fwrite(srcBuffer_UV, 1, filelen_uv, desFile_UV);
        }
    }
    
    //关闭文件释放内存
    fclose(srcFile);
    fclose(desFile_Y);
    fclose(desFile_UV);
    free(srcBuffer_Y);
    free(srcBuffer_UV);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 根据输入的区域将YUV420文件进行裁剪，目前只支持NV12和NV21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CropYUV420(char* src_path, int srcWidth, int srcHeight, int left, int top, int desWidth, int desHeight) {
    
}












