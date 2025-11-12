cmake_minimum_required(VERSION 3.10)
project(shell_assignments C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

# Explicit list of executable targets (keeps the CMake file small and predictable)
set(TARGETS
    bubbleSort
    heapsort
    quickSort
    selectionSort
    shellSort
    straightInsertionSort
)

foreach(t IN LISTS TARGETS)
    set(src "${SRC_DIR}/${t}.c")
    if(EXISTS ${src})
        add_executable(${t} ${src})
        target_include_directories(${t} PRIVATE ${INC_DIR})
    endif()
endforeach()
