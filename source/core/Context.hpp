#pragma once

#include "OpenGL.hpp"

#include <memory>

namespace gl44 {
  class Context {
  public:
    virtual ~Context();
    static std::shared_ptr<Context> create();

    bool isActive() const;
    void present() const;

  private:
    Context(GLFWwindow *window);
    GLFWwindow *m_window;
  };
}
