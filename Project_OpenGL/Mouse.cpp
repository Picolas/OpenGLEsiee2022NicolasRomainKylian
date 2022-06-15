#include "Mouse.h"


double Mouse::x = 0;
double Mouse::y = 0;
double Mouse::lastX = 0;
double Mouse::lastY = 0;
double Mouse::dx = 0;
double Mouse::dy = 0;
double Mouse::scrollDx = 0;
double Mouse::scrollDy = 0;
bool Mouse::firstMouse = true;
bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsChanged[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::cursorPositionChanged(GLFWwindow* window, double x, double y)
{
    Mouse::x = x;
    Mouse::y = y;

    if (firstMouse) {
        lastX = Mouse::x;
        lastY = Mouse::y;
        firstMouse = false;
    }

    Mouse::dx = Mouse::x - lastX;
    Mouse::dy = lastY - y; // y coordinates are inverted
    lastX = Mouse::x;
    lastY = Mouse::y;
}

void Mouse::mouseButtonChanged(GLFWwindow* window, int button, int action, int mods)
{
    if (action != GLFW_RELEASE) {
        if (!buttons[button]) {
            buttons[button] = true;
        }
    }
    else {
        buttons[button] = false;
    }
    buttonsChanged[button] = action != GLFW_REPEAT;
}

void Mouse::mouseWheelChanged(GLFWwindow* window, double dx, double dy)
{
    scrollDx = dx;
    scrollDy = dy;
}

double Mouse::getDx()
{
    return 0.0;
}

double Mouse::getDy()
{
    double tempDy = dy;
    
    dy = 0;
    return tempDy;
}

double Mouse::getScrollDx() {
    double tempScrollDx = scrollDx;
    
    scrollDx = 0;
    return tempScrollDx;
}

double Mouse::getScrollDy() {
    double tempScrollDy = scrollDy;
    
    scrollDy = 0;
    return tempScrollDy;
}

bool Mouse::button(int button) {
    return buttons[button];
}


bool Mouse::buttonChanged(int button) {
    bool result = buttonsChanged[button];

    buttonsChanged[button] = false;
    return result;
}


bool Mouse::buttonUp(int button) {
    return !buttons[button] && buttonChanged(button);
}

// return if button changed and is now down
bool Mouse::buttonDown(int button) {
    return buttons[button] && buttonChanged(button);
}
