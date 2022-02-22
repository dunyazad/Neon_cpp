#include <iostream>
#include <filesystem>
using namespace std;

#include <GLFW/glfw3.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#include <ft2build.h>
#include FT_FREETYPE_H

#pragma comment(lib, "freetype.lib")

#include <filesystem>
//
//int main(int argc, char** argv)
//{
//    cout << std::filesystem::current_path() << endl;
//
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    FT_Library  library;
//    auto error = FT_Init_FreeType(&library);
//    if (error)
//    {
//        cout << error << endl;
//    }
//
//    FT_Face     face;
//    error = FT_New_Face(library,
//        "../../res/fonts/arial.ttf",
//        0,
//        &face);
//    if (error == FT_Err_Unknown_File_Format)
//    {
//        cout << error << endl;
//    }
//    else if (error)
//    {
//        cout << error << endl;
//    }
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
