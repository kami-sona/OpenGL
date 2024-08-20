#pragma once
#include <Eigen/Dense>
#define PI 3.1415926
using Eigen::Matrix4f;
using Eigen::Vector3f;
using Eigen::Vector4f;
namespace DT_Transform
{

	Matrix4f Translate(Vector3f& Targetpos);

	Matrix4f Rotate(float Angles, Vector3f& UnitVector);

	Matrix4f LookAt(Vector3f& Eye, Vector3f& Target, Vector3f& upDir);

	Matrix4f Scale(Vector3f& Targetscale);
}