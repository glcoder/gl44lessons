#ifdef _MSC_VER
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "core/OpenGL.hpp"
#include "core/Context.hpp"

int main() {
  if (!gl44::create())
    return 1;

  if (std::shared_ptr<gl44::Context> context = gl44::Context::create()) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (context->isActive()) {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      context->present();
    }
  }

  gl44::destroy();
  return 0;
}
