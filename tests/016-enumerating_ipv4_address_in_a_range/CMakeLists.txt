cmake_minimum_required(VERSION 3.17)

include(GoogleTest)

set(target_name 016-enumerating_ipv4_address_in_a_range_tests)
add_executable(${target_name} enumerating_ipv4_address_in_a_range.cpp)
target_compile_features(${target_name} PRIVATE cxx_std_17)
target_link_libraries(${target_name}
    PRIVATE
        gtest
        gtest_main
        gmock
        016-enumerating_ipv4_address_in_a_range
)

gtest_discover_tests(${target_name} TEST_PREFIX 16:)
