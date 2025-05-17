cmake_minimum_required(VERSION 3.16)

project(QtTeamApp VERSION 1.0 LANGUAGES CXX)

# 使用 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动处理 Qt 的元对象、UI、资源文件
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ✅ 指定 Qt 安装路径（确保路径正确）
set(CMAKE_PREFIX_PATH "/Users/wu/Qt/6.9.0/macos")

# 查找 Qt 组件
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 添加可执行文件（你可以根据需要扩展为多个源文件）
add_executable(QtTeamApp
    src/main.cpp
)

# 链接 Qt 库
target_link_libraries(QtTeamApp PRIVATE Qt6::Widgets)