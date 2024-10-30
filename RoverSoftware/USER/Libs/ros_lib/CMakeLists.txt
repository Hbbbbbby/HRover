cmake_minimum_required(VERSION 3.22)

project(ROS)
add_library(ROS INTERFACE)

enable_language(CXX)

target_compile_definitions(ROS INTERFACE 
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(ROS INTERFACE
    ./
)

file(GLOB SOURCES 
    ./*.cpp
)

target_sources(ROS INTERFACE
    ${SOURCES}
)

target_link_directories(ROS INTERFACE
)

target_link_libraries(ROS INTERFACE
)

