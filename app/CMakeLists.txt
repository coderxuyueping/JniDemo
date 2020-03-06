cmake_minimum_required(VERSION 3.6)

add_library( # Sets the name of the library.
        # 生成的so库名称,并不需要和c/cpp文件名相同
        # 这里生产的so库名称将为libnative-lib.so
             jniUtil

        # Sets the library as a shared library.
        # STATIC：静态库，是目标文件的归档文件，在链接其它目标的时候使用
        # SHARED：动态库，会被动态链接，在运行时被加载
        # MODULE：模块库，是不会被链接到其它目标中的插件，但是可能会在运行时使用dlopen-系列的函数动态链接
             SHARED

             # Provides a relative path to your source file(s).
        # 资源文件的路径，可以是多个资源文件
             src/main/jni/jniUtil.c )

# 从系统库中查找依赖库
find_library( # Sets the name of the path variable.
        # 设置依赖库的名字，下面链接库的时候会用到
                log-lib

                # Specifies the name of the NDK library that
                # you want CMake to locate.
        # 查找log依赖库
                log )

# 配置库的依赖关系(链接关系)
target_link_libraries( # Specifies the target library.
        # 目标库
                jniUtil

              # Links the target library to the log library
              # included in the NDK.
              # 依赖库，可以是多个
              ${log-lib}  )