add_executable(test
        ${CMAKE_CURRENT_SOURCE_DIR}/libcsc/time/time.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libcsc/smartptr/uniqueptr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libcsc/smartptr/sharedptr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/libcsc/list/list.cpp)

set_compile_options(test)

target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/external/gtest/googletest/include/gtest)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/src/libcsc/libcsc)

target_link_libraries(test PRIVATE my_time my_smartptr my_list)
target_link_libraries(test PRIVATE gtest gtest_main)

add_custom_target(check ALL COMMAND test)