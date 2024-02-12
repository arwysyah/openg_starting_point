#include <GL/glew.h>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <GL/glext.h>
#include <cmath>
#include <iostream>

const char *vertexShaderSource =
    "#version 330 core \n"
    "layout (location = 0) in vex3 aPos;\n"
    "{\n"
    "  gl_position = vec4(aPos.x, aPos.y,aPos.z,1.0);\n"
    "}\0";
const char *fragmentShaderSource =
    "#version 330 core \n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "  FragColor = vex4(0.8f, 0.4f, 0.02f,1.0f);\n"
    "}\n\0";

void drawTriangle() {

  GLfloat vertices[] = {-0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f,
                        -0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f,
                        -0.5f, -0.5f * float(sqrt(3)) * 2 / 3, 0.0f};
  // shaders are open gl object , in the memory , we can only access by
  // reference
  GLuint vertexShader =
      glCreateShader(GL_VERTEX_SHADER); // reference unsigned int
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glBegin(GL_TRIANGLES);

  // glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
  // glVertex2f(0.0f, 0.5f);      // Top vertex
  // glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
  // glVertex2f(-0.5f, -0.5f);    // Bottom-left vertex
  // glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
  // glVertex2f(0.5f, -0.5f);     // Bottom-right vertex
  glEnd();
}

void displayWindow(GLFWwindow *window) {
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();

    // swap front and back buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

int main() {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  // Create a windowed mode window and its OpenGL context
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "OpenGL Triangle", NULL, NULL);
  if (!window) {
    std::cerr << "Failed to create GLFW window\n";
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);
  displayWindow(window);
  // Clean up
  glfwTerminate();
  return 0;
}

// command
// g++
