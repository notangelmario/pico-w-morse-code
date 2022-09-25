cmake_minimum_required(VERSION 3.13)

include(src/lib/pico-sdk/pico_sdk_init.cmake)
project(pico-w-morse-code)

# Set PICO_BOARD
set(PICO_BOARD pico_w)

pico_sdk_init()

# Add exec
add_executable(pico-w-morse-code src/main.c)

# Link libraries
target_link_libraries(pico-w-morse-code pico_cyw43_arch_none)

# Add extra files
pico_add_extra_outputs(pico-w-morse-code)
