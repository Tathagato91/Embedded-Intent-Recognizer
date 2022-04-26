cmake_minimum_required(VERSION 3.5)

# Set the project name
project (google_unit_test)


# add googletest subdirectory
add_subdirectory(googletest) 


# this is so we can #include <gtest/gtest.h>
include_directories(googletest/include)


# add the library for test
add_library(example_google_unit_test
    ../sources/EmbeddedIntentRecognizer.C
)

# include directories to use when compiling a given target
target_include_directories(example_google_unit_test
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# link google test to this executable
target_link_libraries(example_google_unit_test PRIVATE gtest)

#############################################
# Unit tests

# enable CTest testing
enable_testing()

# define a test
add_executable(unit_tests Unittests.C)

target_link_libraries(unit_tests example_google_unit_test gtest)

add_test(test_all unit_tests)