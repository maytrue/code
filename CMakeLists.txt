cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 11)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

include_directories(./TwoPointer)
include_directories(./BFS)
include_directories(./include)

add_subdirectory(./BinarySearch)
add_subdirectory(./TwoPointer)
add_subdirectory(./BFS)
add_subdirectory(./maze)
add_subdirectory(./DFS)

include(./cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

enable_testing(test)
add_subdirectory(test)