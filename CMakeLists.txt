cmake_minimum_required(VERSION 3.10)
project(AlgorithmProblems VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB_RECURSE SOURCE_FILES
     ${CMAKE_SOURCE_DIR}/src/*.c
     ${CMAKE_SOURCE_DIR}/src/*.cpp)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})



# Define the include DIRs
include_directories(
	"${CMAKE_SOURCE_DIR}/include"
)

set(LIBS pthread)

target_link_libraries(${PROJECT_NAME} ${LIBS})