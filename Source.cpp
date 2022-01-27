#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


//WINDOW DIMENSIONS
const GLint WIDTH = 800, HEIGHT = 600;



int main() {

	//intialiase  GLFW
	if (!glfwInit())
	{
		printf("glfw initialisation failed!");
		glfwTerminate();
		return 1;
	}

	//setup GLFW WINDOW PROPERTIES
	//OPENGL VERSION

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// core profile = no backward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "test window", NULL, NULL);

	if (!mainWindow) {
		printf("GLFW WINDOW CREATION FAILED");
		glfwTerminate();
		return 1;
	}

	//get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// allow modern extension features
	glewExperimental = GL_TRUE;


	if (glewInit() != GLEW_OK) {

		printf("glew intialization failed");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}
	


	//setup viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// get + handle user input events
		glfwPollEvents();

		//clear window
		glClearColor(0.3f, 0.9f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;

}