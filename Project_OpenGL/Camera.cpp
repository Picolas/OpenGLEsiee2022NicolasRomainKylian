#include "Camera.h"

#include "Utils.h"

// Constructor par defaut
Camera::Camera(Vector3 cameraPosition) : cameraPosition(cameraPosition), cameraYaw(0.0f), cameraPitch(0.0f), cameraSpeed(2.5f), cameraSensitivity(1.0f), cameraZoom(45.0f), cameraFront(Vector3(1.0f, 0.0f, 0.0f))
{
    updateCameraVectors();
}

void Camera::updateCameraDirection(double dx, double dy) {
    cameraYaw += dx;
    cameraPitch += dy;

    if (cameraPitch > 89.0f) {
        cameraPitch = 89.0f;
    }
    if (cameraPitch < -89.0f) {
        cameraPitch = -89.0f;
    }

    updateCameraVectors();
}

void Camera::updateCameraPosition(CameraDirection direction, double dt) {
    float velocity = (float)dt * cameraSpeed;

    switch (direction) {
	    case CameraDirection::FORWARD:
	        cameraPosition += cameraFront * velocity;
	        break;
	    case CameraDirection::BACKWARD:
			cameraPosition -= cameraFront * velocity;
	        break;
	    case CameraDirection::RIGHT:
			cameraPosition += cameraRight * velocity;
	        break;
	    case CameraDirection::LEFT:
			cameraPosition -= cameraRight * velocity;
	        break;
	    case CameraDirection::UP:
			cameraPosition += cameraUp * velocity;
	        break;
	    case CameraDirection::DOWN:
			cameraPosition -= cameraUp * velocity;
	        break;
	}
}

void Camera::updateCameraZoom(double dy) {
    if (cameraZoom >= 1.0f && cameraZoom <= 45.0f) {
        cameraZoom -= dy;
    }
    else if (cameraZoom < 1.0f) {
        cameraZoom = 1.0f;
    }
    else {
        cameraZoom = 45.0f;
    }
}

Matrix4 Camera::getViewMatrix() {
    Matrix4 View;

    Vector3 target = cameraPosition + cameraFront;
   
    return View.lookAt(cameraPosition, target, cameraUp);
}

float Camera::getCameraZoom() {
    return cameraZoom;
}

void Camera::updateCameraVectors() {
    Vector3 direction;
    direction.x = cos(Utils::degreeToRadian(cameraYaw)) * cos(Utils::degreeToRadian(cameraPitch));
    direction.y = sin(Utils::degreeToRadian(cameraPitch));
    direction.z = sin(Utils::degreeToRadian(cameraYaw)) * cos(Utils::degreeToRadian(cameraPitch));
    cameraFront = cameraFront.normalize(direction);

    cameraRight = cameraRight.normalize(glm::cross(cameraFront, Vector3(0.f, 1.f, 0.f)));
    cameraUp = cameraUp.normalize(glm::cross(cameraRight, cameraFront));
}