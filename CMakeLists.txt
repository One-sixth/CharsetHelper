# 最低指定的CMake版本
cmake_minimum_required(VERSION 3.15)

# 要求c++20，因为c++20 才有 u8string, u16string, u32string
SET(CMAKE_CXX_STANDARD 20)

# 设定版本号
set(VERSION 0_1_0)

# 工程名
project(CharsetHelper)

# 寻找Boost包
# find_package(Boost COMPONENTS locale REQUIRED)
find_package(Boost REQUIRED)

# 添加默认头文件搜索路径
include_directories(include)

# 搜索指定目录中所有源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src LIB_SRC_FILES)

# 搜索示例目录中所有源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/example EXAMPLE_SRC_FILES)

# message("LIB_SRC_FILES=${LIB_SRC_FILES}")

# 设定库文件的输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/lib)

# 设定可执行文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)

# 设定调试库和发行库的后缀
set(CMAKE_DEBUG_POSTFIX "_debug")
set(CMAKE_RELEASE_POSTFIX "_release")

# 设定动态库的生成目标
add_library(${CMAKE_PROJECT_NAME} SHARED ${LIB_SRC_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LIBRARY_DIRS})
# target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LOCALE_LIBRARY})

# message("${Boost_LOCALE_LIBRARY}")

# 生成可执行文件，生成的test即为可执行文件
add_executable(Example ${EXAMPLE_SRC_FILES})

# 给测试用可执行文件添加库依赖
target_link_libraries(Example PRIVATE ${CMAKE_PROJECT_NAME})

# 设定安装
install(TARGETS ${CMAKE_PROJECT_NAME} Example)
