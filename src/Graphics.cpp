#include "Graphics.h"
#include "includes.h"

Graphics::Graphics() {

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLAD");
    }

    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading language version : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // GLint num;
    // glGetIntegerv(GL_NUM_EXTENSIONS, &num);

    // std::cout << "Start" << std::endl;
    //
    // for (int i = 0; i < num; ++i) {
    //     std::cout<< glGetStringi(GL_EXTENSIONS, i) <<std::endl;
    // }
    // std::cout << "End" << std::endl;
    glEnable(GL_DEPTH_TEST);
}

Graphics::~Graphics() {
}

void Graphics::cleanColor() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}
