project(GoogleTest)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Tests Tests/basic_tests.cpp)
target_link_libraries(Tests gtest gtest_main)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Tests Hare_core)