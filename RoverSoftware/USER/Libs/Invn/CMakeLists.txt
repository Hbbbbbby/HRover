cmake_minimum_required(VERSION 3.22)

project(Invn_Icm20948)
add_library(Invn_Icm20948 INTERFACE)

enable_language(C ASM)

target_compile_definitions(Invn_Icm20948 INTERFACE 
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(Invn_Icm20948 INTERFACE
    ./
    ./Invn/Devices
    ./Invn/Devices/Drivers/Icm20948
    ./Invn/DynamicProtocol
    ./Invn/EmbUtils
    ./Invn/Images
    ./Invn/VSensor
)

file(GLOB SOURCES 
    ./Invn_icm20948/*.c
    ./Invn/Devices/*.c
    ./Invn/Devices/Drivers/Icm20948/*.c
    ./Invn/DynamicProtocol/*.c
    ./Invn/EmbUtils/*.c
    ./Invn/Images/*.c
    ./Invn/VSensor/*.c
)

target_sources(Invn_Icm20948 INTERFACE
    ${SOURCES}
)

target_link_directories(Invn_Icm20948 INTERFACE
)

target_link_libraries(Invn_Icm20948 INTERFACE

)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()