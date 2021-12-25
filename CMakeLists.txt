cmake_minimum_required(VERSION 3.0)

project(Matrix)


add_compile_options(
   -Werror
   -Wall
   -Wextra
   -pedantic
   -Wcast-align
   -Wcast-qual
   -Wdisabled-optimization
   -Winit-self
   -Wmissing-include-dirs
   -Wold-style-cast
   -Woverloaded-virtual
   -Wredundant-decls
   -Wshadow
   -Wsign-promo
   -Wno-unused 
   -Wno-variadic-macros
   -Wno-parentheses
   -fdiagnostics-show-option
   )

enable_testing()

set(TEST_NAME MY_TEST)

configure_file(gitignore.in .gitignore COPYONLY)

include(FetchContent)
FetchContent_Declare(
  googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB TST_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(inc)

add_executable(
    ${TEST_NAME}
    ${SRC_FILES}
    ${TST_FILES}
    )


target_link_libraries(
    ${TEST_NAME}  
    gtest_main
    pthread
    )

add_test(
    NAME ${TEST_NAME}
    COMMAND ${TEST_NAME}
)