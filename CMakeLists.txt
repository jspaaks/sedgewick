cmake_minimum_required(VERSION 3.23...3.28)

project(sedgewick LANGUAGES C)

set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "${CMAKE_BINARY_DIR}/dist")
endif()

add_subdirectory(${PROJECT_ROOT}/src/101200000)
add_subdirectory(${PROJECT_ROOT}/src/101500000)
add_subdirectory(${PROJECT_ROOT}/src/101700000)
add_subdirectory(${PROJECT_ROOT}/src/101901004)
add_subdirectory(${PROJECT_ROOT}/src/101901005)
add_subdirectory(${PROJECT_ROOT}/src/101901007)
add_subdirectory(${PROJECT_ROOT}/src/108203001)
add_subdirectory(${PROJECT_ROOT}/src/108203002)
add_subdirectory(${PROJECT_ROOT}/src/108203003)
add_subdirectory(${PROJECT_ROOT}/src/108203004)
add_subdirectory(${PROJECT_ROOT}/src/108203006)
