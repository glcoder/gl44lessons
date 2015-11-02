#include "OpenGL.hpp"

#include <iostream>

namespace gl44 {
  static void error(int error, char const * description) {
    std::cerr << "GLFW error [" << error << "] " << description << std::endl;
  }

  bool create() {
    glfwSetErrorCallback(error);

    if (glfwInit() != GL_TRUE) {
      std::cerr << "fail to init GLFW" << std::endl;
      return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return true;
  }

  void destroy() {
    glfwTerminate();
  }
}
