include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        first_check.cpp
        second_check.cpp)

target_include_directories(runBasicTests PUBLIC ../../src)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests vanilla_lib)