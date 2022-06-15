#pragma once
#include <GL/glew.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>

class Mouse
{

public:
    static double x;
    static double y;
    static double lastX;
    static double lastY;
    static double dx;
    static double dy;
    static double scrollDx;
    static double scrollDy;
    static bool firstMouse;
    static bool buttons[];
    static bool buttonsChanged[];
	
    static void cursorPositionChanged(GLFWwindow* window, double x, double y);
    
    static void mouseButtonChanged(GLFWwindow* window, int button, int action, int mods);
    
    static void mouseWheelChanged(GLFWwindow* window, double dx, double dy);

    static double getDx();

    static double getDy();

    static double getScrollDx();
	
    static double getScrollDy();

    static bool button(int button);

    static bool buttonChanged(int button);

    static bool buttonUp(int button);

    static bool buttonDown(int button);
};

