cmake_minimum_required(VERSION 3.20)

add_executable(time_test libcsc/libcsc/time.cpp)

set_compile_options(time_test)

target_include_directories(time_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/gtest/googletest/include/gtest)
target_include_directories(time_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/libcsc/libcsc/time)

target_link_libraries(time_test PRIVATE my_time)


target_link_libraries(
        time_test PRIVATE
        gtest gtest_main
)

add_custom_target(check ALL COMMAND time_test)