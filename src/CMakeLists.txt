file(GLOB GL44_SRC *.cpp *.h)

add_definitions("-std=c++11 -pedantic -Wall")
add_executable(gl44lessons ${GL44_SRC})

#target_link_libraries(gl44lessons glew glfw3)
