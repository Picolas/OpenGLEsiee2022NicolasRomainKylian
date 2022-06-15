#pragma once
#include "Vector3.h"

class Utils
{
public:
	static float degreeToRadian(float degree)
	{
		double pi = 3.14159265359;
		return (degree * (pi / 180));
	}

	static Vector3 cross(Vector3 x, Vector3 y)
	{
		return Vector3(
			x.y * y.z - y.y * x.z,
			x.z * y.x - y.z * x.x,
			x.x * y.y - y.x * x.y
		);
	}
	
};

