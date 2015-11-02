project(gl44lessons)
cmake_minimum_required(VERSION 2.8)

set(VENDORS_DIR ${PROJECT_SOURCE_DIR}/vendors)
add_subdirectory(${VENDORS_DIR}/glfw-3.1.2)
add_subdirectory(${VENDORS_DIR}/glew-1.12.0/build/cmake)
add_subdirectory(${VENDORS_DIR}/glm-0.9.7.1)

include_directories(
	${PROJECT_SOURCE_DIR}/source
	${VENDORS_DIR}/glfw-3.1.2/include
	${VENDORS_DIR}/glew-1.12.0/include
	${VENDORS_DIR}/glm-0.9.7.1
)

if(CMAKE_COMPILER_IS_GNUCXX)
	add_definitions("-std=c++11 -pedantic -Wall")
endif()

file(GLOB GL44_SOURCES
	source/core/*.cpp
	source/core/*.hpp
	source/main.cpp
)

add_executable(gl44 ${GL44_SOURCES})
target_link_libraries(gl44 glfw glew_s ${GLFW_LIBRARIES})

if(MINGW)
	target_link_libraries(gl44 -mwindows)
endif()
