cmake_minimum_required(VERSION 3.10)
project(shell_assignments C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

file(GLOB SORT_SOURCES
    "${SRC_DIR}/*.c"
)

foreach(src IN LISTS SORT_SOURCES)
    get_filename_component(name ${src} NAME_WE)
    # map straightInstertionSort -> straightInsertionSort
    if(name STREQUAL "straightInstertionSort")
        set(target_name "straightInsertionSort")
    else()
        set(target_name ${name})
    endif()
    add_executable(${target_name} ${src})
    target_include_directories(${target_name} PRIVATE ${INC_DIR})
endforeach()
