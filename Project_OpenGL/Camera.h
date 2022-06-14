#pragma once
#include "Matrix4.h"
#include <GL/glew.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "../common/GlShader.h"
#include "Vector3.h"
#include "Matrix4.h"

enum class CameraDirection {
	NONE = 0,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera
{
public:
	// Position de la camera
	Vector3 cameraPosition;

	// Direction de la camera
	Vector3 cameraFront;
	Vector3 cameraUp;
	Vector3 cameraRight;

	// Axis de la camera
	float cameraYaw;
	float cameraPitch;

	// Mouvement de la camera
	float cameraSpeed;
	float cameraSensitivity;
	float cameraZoom;

	// Constructor initialize camera
	Camera(Vector3 cameraPosition = Vector3(0.f, 0.f, .0f));

	// Changer la direction avec la souris
	void updateCameraDirection(double dx, double dy);

	// Changer la direction avec le clavier
	void updateCameraPosition(CameraDirection direction, double dt);

	// Avec le scroll souris
	void updateCameraZoom(double dy);


	// Get
	Matrix4 getViewMatrix();

	float getCameraZoom();

private:

	void updateCameraVectors();
};

