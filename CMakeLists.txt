cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Set PICO_BOARD and PICO_SDK_PATH
set(PICO_BOARD pico_w)
set(PICO_SDK_PATH ../src/lib/pico-sdk)

include(src/lib/pico-sdk/external/pico_sdk_import.cmake)
project(pico-w-morse-code)

pico_sdk_init()

# Add exec
add_executable(pico-w-morse-code src/main.c)

# Link libraries
target_link_libraries(pico-w-morse-code pico_stdlib)
target_link_libraries(pico-w-morse-code pico_cyw43_arch_none)

# Add extra files
pico_add_extra_outputs(pico-w-morse-code)
