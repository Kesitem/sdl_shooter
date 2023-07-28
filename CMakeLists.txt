cmake_minimum_required(VERSION 3.12)

project(sdl_shooter VERSION 0.0.1
                  DESCRIPTION "A simple shoter"
                  LANGUAGES CXX)

#find_package(OpenGL REQUIRED)

# Add plog
find_package(plog CONFIG REQUIRED)

# Set sources files path
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Configure version 
configure_file (
    "${SRC_DIR}/config.h.in"
    "${SRC_DIR}/config.h"
)

# List of header files
set(HEADERS
    config.h
    core.h
    engine.h
)
# List of source files
set(SRCS
    log_formatter.h
    log_formatter.cpp
    main.cpp
    engine.cpp
)

# Generate filename with path
foreach(H ${HEADERS})
    list(APPEND ALL_HEADERS ${SRC_DIR}/${H})
endforeach() 
foreach(S ${SRCS})
    list(APPEND ALL_SRCS ${SRC_DIR}/${S})
endforeach()

# Create library
# add_library(${PROJECT_NAME} STATIC ${ALL_SRCS} ${ALL_HEADERS} ${STB_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${ALL_SRCS} ${ALL_HEADERS})

# Set C++17 feature
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Add library
target_link_libraries(${PROJECT_NAME} PRIVATE plog::plog )

# Set include directory for compilation
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/src)