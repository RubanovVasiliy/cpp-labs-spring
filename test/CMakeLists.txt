cmake_minimum_required(VERSION 3.20)

add_executable(time_test libcsc/libcsc/time/time.cpp)
add_executable(smartptr_test libcsc/libcsc/smartptr/smartptr.cpp)

set_compile_options(time_test)
set_compile_options(smartptr_test)

target_include_directories(time_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/gtest/googletest/include/gtest)
target_include_directories(time_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/libcsc/libcsc/time)

target_include_directories(smartptr_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/gtest/googletest/include/gtest)
target_include_directories(smartptr_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/libcsc/libcsc/smartptr)

target_link_libraries(time_test PRIVATE my_time)
target_link_libraries(smartptr_test PRIVATE my_smartptr)

target_link_libraries(time_test PRIVATE gtest gtest_main)
target_link_libraries(smartptr_test PRIVATE gtest gtest_main)

add_custom_target(time_check ALL COMMAND time_test)
add_custom_target(smartptr_check ALL COMMAND smartptr_test)
