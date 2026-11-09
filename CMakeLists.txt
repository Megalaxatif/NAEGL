cmake_minimum_required(VERSION 3.27)

project(NEAGLE)

set(EXEC_NAME "NEAGLE")

file(GLOB SRC_FILES "src/*.c")

add_executable(${EXEC_NAME} ${SRC_FILES})

target_include_directories(${EXEC_NAME} PUBLIC include)

target_link_libraries(${EXEC_NAME} SDL2 SDL2_image SDL2_ttf)
