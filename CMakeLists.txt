cmake_minimum_required(VERSION 3.5.1)
project(lab8-0 C)

set(SRC src/main.c src/Graph.c src/Errors.c src/Dsu.c src/KruskalAlg.c include/Graph.h include/Errors.h include/Dsu.h include/KruskalAlg.h)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../modules")
include(common_lab)
