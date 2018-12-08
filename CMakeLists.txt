cmake_minimum_required (VERSION 2.8)
project (main)
add_definitions(-std=gnu++0x)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -fdata-sections -ffunction-sections -fPIC -fpermissive")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g -ggdb -O0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#version number
set (main_VERSION_MAJOR 1)
set (main_VERSION_MINOR 0)

find_library(wiringPi_LIB wiringPi)

if(NOT wiringPi_LIB)
  message(FATAL_ERROR "wiringPi library not found")
endif()


find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

if(CMAKE_CROSSCOMPILING)
    find_library(picar_LIB picar)
    if(NOT picar_LIB)
        message(FATAL_ERROR "picar library not found")
    endif()
    find_library(asn1_LIB asn1)
    if(NOT asn1_LIB)
        message(FATAL_ERROR "asn1 library not found")
    endif()
    include_directories(
        ${ROOTFS_PATH}/usr/include/
        ${ROOTFS_PATH}/usr/include/v2x
        ${ROOTFS_PATH}/usr/include/v2x/asn_src
        )
    link_directories(${ROOTFS_PATH}/usr/lib)
else()
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/asn_src
        )
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
endif()

file(GLOB BINARY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB BINARY_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    )

set(BINARY_SOURCE_FILES ${BINARY_SOURCES} ${BINARY_HEADERS})

add_executable(main main.cpp ${BINARY_SOURCE_FILES})

# Indicate which libraries to include during the link process.
target_link_libraries (main ${picar_LIB} ${wiringPi_LIB} ${asn1_LIB}  ${PYTHON_LIBRARIES})
if(CMAKE_CROSSCOMPILING)
    target_link_libraries (main -L${ROOTFS_PATH}/usr/lib ${asn1_LIB} ${picar_LIB} ${wiringPi_LIB} -L${ROOTFS_PATH}/usr/lib/arm-linux-gnueabihf -lz -lexpat -lcrypt -lrt ${PYTHON_LIBRARIES} )
else()
    target_link_libraries (main -lz -lexpat -lpicar -lasn1 -lcrypt -lrt -lpthread ${wiringPi_LIB} ${PYTHON_LIBRARIES})
endif()

install (TARGETS main DESTINATION bin)
