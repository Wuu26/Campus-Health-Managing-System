cmake_minimum_required(VERSION 3.16)
project(CampusHealth LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 替换为你的 Qt 安装路径
set(Qt6_DIR "/Users/wu/Qt/6.9.0/macos/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(CampusHealth
    src/main.cpp
    src/mainwindow.cpp
    src/interfaces.cpp       # ✅ 包含逻辑函数实现
    src/mainwindow.ui
)

target_link_libraries(CampusHealth PRIVATE Qt6::Widgets)

# IDE 提示友好哦
target_include_directories(CampusHealth PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
