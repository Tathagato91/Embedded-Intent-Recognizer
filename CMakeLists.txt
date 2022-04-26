cmake_minimum_required (VERSION 3.1.3)
include(GNUInstallDirs)

## Project
project (EmbeddedIntentRecognitionTool CXX)

## Build
set (TARGET EmbeddedIntentRecognizer)
add_executable (${TARGET} "")

## Sources
target_sources(
    ${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/sources/main.C
        ${PROJECT_SOURCE_DIR}/sources/EmbeddedIntentRecognizer.C
)

## Headers
target_include_directories (
    ${TARGET}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/headers
)

# Link external/3rd party libs
target_link_libraries (
    ${TARGET}
    PRIVATE
)

# Compilation Params
target_compile_options (
    ${TARGET}
    PRIVATE
        -std=c++17
        -Wall
        -Werror
        -Wunused
        -pedantic
)

# Custom Commands

# Installation 
install (
    TARGETS         ${TARGET}
    DESTINATION     ${PROJECT_SOURCE_DIR}/build
)

# Unit Tests
#add_subdirectory(tests)