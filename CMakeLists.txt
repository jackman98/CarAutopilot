cmake_minimum_required (VERSION 2.8)
project (main)
add_definitions(-std=gnu++0x)

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
    include_directories(
        ${ROOTFS_PATH}/usr/include/
        )
    link_directories(${ROOTFS_PATH}/usr/lib)
else()
    include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        )
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
endif()


#indicate the entry point for the executable
add_executable (main main.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries (main ${picar_LIB} ${wiringPi_LIB} ${PYTHON_LIBRARIES})
if(CMAKE_CROSSCOMPILING)
    target_link_libraries (main -L${ROOTFS_PATH}/usr/lib ${picar_LIB} ${wiringPi_LIB} -L${ROOTFS_PATH}/usr/lib/arm-linux-gnueabihf -lz -lexpat -lcrypt -lrt ${PYTHON_LIBRARIES} )
else()
    target_link_libraries (main -lz -lexpat -lpicar -lcrypt -lrt ${wiringPi_LIB} ${PYTHON_LIBRARIES})
endif()

install (TARGETS main DESTINATION bin)
