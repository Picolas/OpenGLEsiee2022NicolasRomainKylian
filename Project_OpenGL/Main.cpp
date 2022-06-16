#define GLEW_STATIC // nécessite glew32s.lib
#include <GL/glew.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

#include "../common/GlShader.h"
#include "Vector3.h"
#include "Matrix4.h"

#include <stdio.h>
#include <stdlib.h>

#include "../common/tinyobj/tiny_obj_loader.h"

#include "../common/shader.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

#include "Camera.h"
#include "Mouse.h"
#include "Utils.h"

using namespace std;


// SHADER
GLShader g_BasicShader;
GLShader g_PhongShader;

GLFWwindow* window;


Camera camera;
Matrix4 view;
Matrix4 projection;
Matrix4 textProjection;
Vector3 cameraPosition;

double screenWidth = 1024;
double screenHeight = 768;

// timing
float currentFrame = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;
float deltaTime = 0.f;


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(float deltaTime);

void updateDeltaTime();

void mainInit();

int initGLWF();

int initGlew();

int initWindows();

int main(void)
{
	// Initilialisation main
	mainInit();

	do {
		updateDeltaTime();

		processInput(deltaTime); // Get inputs

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);








		glDisableVertexAttribArray(0);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);


	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(float deltaTime) {
	
	double dx = Mouse::getDx();
	double dy = Mouse::getDy();
	if (dx != 0 || dy != 0) {
		camera.updateCameraDirection(dx, dy);
	}

	double scrollDy = Mouse::getScrollDy();
	if (scrollDy != 0) {
		camera.updateCameraZoom(scrollDy);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cout << "test";
		camera.updateCameraPosition(CameraDirection::FORWARD, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		camera.updateCameraPosition(CameraDirection::BACKWARD, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		camera.updateCameraPosition(CameraDirection::RIGHT, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		camera.updateCameraPosition(CameraDirection::LEFT, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		camera.updateCameraPosition(CameraDirection::UP, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		camera.updateCameraPosition(CameraDirection::DOWN, deltaTime);
	}

	view = camera.getViewMatrix();
	projection = projection.perspective(
		Utils::degreeToRadian(camera.getCameraZoom()),
		(float)screenWidth / (float)screenHeight,	
		0.1f, 100.0f									
	);

	cameraPosition = camera.cameraPosition;

	cout << "Position : x " << cameraPosition.x << ",y " << cameraPosition.y << " z, " << cameraPosition.z << " zoom" << camera.getCameraZoom() << endl;
}

void updateDeltaTime()
{
	currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void mainInit() {
	// Initialise GLFW
	initGLWF();

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	initWindows();

	// Initialize GLEW
	initGlew();

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// OPTION
	// depth testing
	glEnable(GL_DEPTH_TEST); // doesn't show vertices not visible to camera (back of object)

	// blending for text textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// stencil testing
	glEnable(GL_STENCIL_TEST);
	// keep fragments if either stencil or depth fails, replace if both pass
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	// v-sync
	glfwSwapInterval(1);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // disable cursor
}

int initGLWF()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}
}

int initWindows()
{
	window = glfwCreateWindow(1024, 768, "Projet OpenGL | Nicolas PIPLARD | Romain CORDIER |Kylian MAHEU", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
}

int initGlew()
{
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}
}
