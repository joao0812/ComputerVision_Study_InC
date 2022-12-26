cmake_minimum_required(VERSION 3.0.0)
project(showimage VERSION 0.1.0)

# rm -rf build - Para riniciar o repositório

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(showimage src/show_image.cpp)
target_link_libraries(showimage ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
