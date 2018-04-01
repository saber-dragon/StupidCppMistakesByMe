cmake_minimum_required(VERSION 3.0)

enable_testing()

configure_file(../CMakeLists.txt.in googletest-download/CMakeLists.txt)
message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND}  --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

include_directories(SYSTEM ${gtest_SOURCE_DIR}/include)
set(whetherOrNotAddTest true)
file(GLOB HEADERS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h" "*.hpp" )
file(GLOB SRCS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp" "*.cc" )
foreach(src ${SRCS})
    get_filename_component(subfix ${src} NAME_WE)
    set(binName "${PROJECT_NAME}_${subfix}")
    message(STATUS "Buidling ${binName} for ${src}...")
    add_executable (${binName} ${HEADERS} ${src})
    target_link_libraries(${binName} gtest_main)
    # message(STATUS "whetherOrNotAddTest: ${whetherOrNotAddTest}")
    if (${whetherOrNotAddTest})
        message(STATUS "Add test for ${binName}")
        add_test(NAME "${binName}_test"
                COMMAND "$<TARGET_FILE:${binName}>")
    endif()
endforeach()




