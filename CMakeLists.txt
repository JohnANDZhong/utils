# 定义模块1的库
add_library(utils
    src/factory/factory.c
    src/time/sys_time.c
)

# 设置模块1的头文件路径
target_include_directories(utils PUBLIC include/factory)
target_include_directories(utils PUBLIC include/sys)
target_include_directories(utils PUBLIC include/time)
target_include_directories(utils PUBLIC include/logger)

