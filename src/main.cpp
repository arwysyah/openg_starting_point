#include <GLFW/glfw3.h>
#include <iostream>

void drawTriangle() {
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
  glVertex2f(0.0f, 0.5f);      // Top vertex
  glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
  glVertex2f(-0.5f, -0.5f);    // Bottom-left vertex
  glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
  glVertex2f(0.5f, -0.5f);     // Bottom-right vertex
  glEnd();
}

int main() {
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

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

  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // Render here
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the triangle
    drawTriangle();

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  // Clean up
  glfwTerminate();
  return 0;
}
