cmake_minimum_required(VERSION 3.17)

set(target_name 016-enumerating_ipv4_address_in_a_range)

add_library(${target_name} STATIC src/IPv4Address.cpp)
target_include_directories(${target_name}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/enumerating_ipv4_address_in_a_range>
)

target_compile_options(${target_name} 
   INTERFACE
        -Wall -Wextra -pedantic -Werror
)
