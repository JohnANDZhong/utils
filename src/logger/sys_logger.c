#include "sys_logger.h"

// 从路径中提取文件名
const char* extractFileName(const char* path) {
    const char* fileName = strrchr(path, '/'); // 在路径中查找最后一个斜杠'/'
    if (fileName != NULL) {
        return fileName + 1; // 返回斜杠之后的部分作为文件名
    } else {
        return path; // 如果没有斜杠，则整个路径都是文件名
    }
}