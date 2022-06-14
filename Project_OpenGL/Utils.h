#pragma once
class Utils
{
public:
	static float degreeToRadian(float degree)
	{
		double pi = 3.14159265359;
		return (degree * (pi / 180));
	}

	// TODO CROSS GLM
	static void crossProduct(int v_A[], int v_B[], int c_P[]) {
		c_P[0] = v_A[1] * v_B[2] - v_A[2] * v_B[1];
		c_P[1] = -(v_A[0] * v_B[2] - v_A[2] * v_B[0]);
		c_P[2] = v_A[0] * v_B[1] - v_A[1] * v_B[0];
	}
	
};

