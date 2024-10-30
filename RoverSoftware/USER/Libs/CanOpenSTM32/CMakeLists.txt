cmake_minimum_required(VERSION 3.22)

project(CANopenNode_STM32)
add_library(CANopenNode_STM32 INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(CANopenNode_STM32 INTERFACE
    ./CANopenNode_STM32
    ./CANopenNode
    ./CANopenNode/301
    ./CANopenNode/303
    ./CANopenNode/304
    ./CANopenNode/305
    ./CANopenNode/309
    ./CANopenNode/extra
    ./CANopenNode/storage
)

file(GLOB SOURCES 
    ./CANopenNode_STM32/*.c
    ./CANopenNode/*.c
    ./CANopenNode/301/*.c
    ./CANopenNode/303/*.c
    ./CANopenNode/304/*.c
    ./CANopenNode/305/*.c
    ./CANopenNode/309/*.c
    ./CANopenNode/extra/*.c
    ./CANopenNode/storage/*.c
)

target_sources(CANopenNode_STM32 INTERFACE
    ${SOURCES}
)

target_link_directories(CANopenNode_STM32 INTERFACE
)

target_link_libraries(CANopenNode_STM32 INTERFACE
)

if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()
