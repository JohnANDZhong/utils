# 定义模块1的库
add_library(utils
    src/factory/factory.c
    src/time/sys_time.c
    src/logger/sys_logger.c
    src/list/list.c
    src/queue/queue.c
)

# 设置模块1的头文件路径
target_include_directories(utils PUBLIC include/factory)
target_include_directories(utils PUBLIC include/sys)
target_include_directories(utils PUBLIC include/time)
target_include_directories(utils PUBLIC include/logger)
target_include_directories(utils PUBLIC include/list)
target_include_directories(utils PUBLIC include/queue)
