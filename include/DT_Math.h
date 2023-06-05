#pragma once
#include <Eigen/Dense>
#define PI 3.1415926
using Eigen::Matrix4f;
using Eigen::Vector3f;
namespace DT_Transform
{

	Matrix4f Translate(Vector3f& Targetpos, Matrix4f& UnitMatrix = Matrix4f{ {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} });

	Matrix4f Rotate(float Angles, Vector3f& UnitVector = Vector3f{ 1.0,1.0,1.0 });

	Matrix4f LookAt(Vector3f& Eye, Vector3f& Target, Vector3f& upDir);
}