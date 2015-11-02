#include "Context.hpp"

#include <iostream>

namespace gl44 {
  Context::Context(GLFWwindow *window) : m_window(window) {
  }

  Context::~Context() {
    glfwDestroyWindow(m_window);
  }

  std::shared_ptr<Context> Context::create() {
    GLFWwindow *window = glfwCreateWindow(800, 600, "GL44", NULL, NULL);
    if (!window) {
      std::cerr << "fail to create GLFWwindow" << std::endl;
      return nullptr;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    const GLenum error = glewInit();
    if (error != GLEW_OK) {
      std::cerr << "fail to init GLEW" << std::endl;
      glfwDestroyWindow(window);
      return nullptr;
    }

    // simple method
    //return std::shared_ptr<Context>(new Context(window));

    // ugly method
    struct ContextCreator : public Context {
      ContextCreator(GLFWwindow *window) : Context(window) {
      }
    };
    return std::make_shared<ContextCreator>(window);
  }

  bool Context::isActive() const {
    return !glfwWindowShouldClose(m_window);
  }

  void Context::present() const {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
  }
}
