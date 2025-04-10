cmake_minimum_required(VERSION 3.30)
project(temp)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

## 指定 Homebrew 安装的 GCC 编译器路径
## 替换 <version> 为你的 GCC 版本号，例如 13
#set(CMAKE_C_COMPILER /opt/homebrew/bin/gcc-14)
#set(CMAKE_CXX_COMPILER /opt/homebrew/bin/g++-14)

# 添加可执行文件
add_executable(temp main.cpp)