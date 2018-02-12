cmake_minimum_required(VERSION 2.8)

project(dessinImage)

set(EXECUTABLE_OUTPUT_PATH
        bin/
        )

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -W -Wall -ansi -std=c++14 -g -Weffc++ -Wfatal-errors"
        )

set(ALL_LIBRARIES
        effolkronium_random
        )

include_directories(
        include/
        /usr/include/
        third-party/random-1.1.0/include
)

add_subdirectory(third-party/random-1.1.0/)

file(GLOB_RECURSE
        SOURCE_FILES
        src/*
        )

file(GLOB HEADER_FILES
        *.hpp)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if (BUILD_DOCUMENTATION)
    set(VERSION_MAJOR 0 CACHE STRING "Project major version number.")
    set(VERSION_MINOR 0 CACHE STRING "Project minor version number.")
    set(VERSION_PATCH 1 CACHE STRING "Project patch version number.")
    mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

    if (NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif ()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
endif ()


add_executable(
        dessinImage
        ${SOURCE_FILES}
        ${HEADER_FILES}
)
target_link_libraries(
        dessinImage
        ${ALL_LIBRARIES}
)
