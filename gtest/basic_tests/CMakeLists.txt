include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        neuron_tests.cpp
        weight_test.cpp weights_test.cpp weightless_connection_test.cpp internally_weighted_connection_test.cpp externally_weighted_connection_test.cpp)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests vanilla_lib)