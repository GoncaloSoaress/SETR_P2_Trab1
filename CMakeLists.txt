# Set CMAKE minimum required version 
cmake_minimum_required(VERSION 3.10)

# set the project name
project(FIFO        VERSION 1.0
                    DESCRIPTION "A simple FIFO module"
                    LANGUAGES C)

# Add the FIFOLib folder to the build
# CMake will look for a CMakeLists.txt in that folder and will process it
add_subdirectory(libs)

# Generate executable "libdemo" from source file "main.c"
add_executable(FIFO_Module main.c)

# Generate variables with set of libs and include folders
# Dependencies for libraries files are automatically set 
list(APPEND EXTRA_LIBS FIFOLib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/libs")

# Specify libraries or flags to use when linking a given target 
# and/or its dependents
target_link_libraries(FIFO_Module PUBLIC ${EXTRA_LIBS})

# Specifies include directories to use when compiling a given target
target_include_directories(FIFO_Module PUBLIC ${EXTRA_INCLUDES})

# Set compiler options for module

	