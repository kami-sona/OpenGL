#include "DT_Math.h"

Matrix4f DT_Transform::Translate(Vector3f& Targetpos)
{
	Matrix4f UnitMatrix = Matrix4f::Identity();
	UnitMatrix(0, 3) = Targetpos.x();
	UnitMatrix(1, 3) = Targetpos.y(); 
	UnitMatrix(2,3) = Targetpos.z();

	return UnitMatrix;
}

Matrix4f DT_Transform::Rotate(float Angles, Vector3f& UnitVector)
{
	Matrix4f Target = Matrix4f::Identity();
	float Angle = PI * (Angles / 180);
	float c = cos(Angle);
	float s = sin(Angle);
	Target(0, 0) = (1 - c) * UnitVector.x() * UnitVector.x() + c;
	Target(0, 1) = (1 - c) * UnitVector.x() * UnitVector.y() - s * UnitVector.z();
	Target(0, 2) = (1 - c) * UnitVector.x() * UnitVector.z() + s * UnitVector.y();

	Target(1, 0) = (1 - c) * UnitVector.x() * UnitVector.y() + s * UnitVector.z();
	Target(1,1) = (1 - c)* UnitVector.y() * UnitVector.y() + c;
	Target(1,2) = (1 - c) * UnitVector.y() * UnitVector.z() - s * UnitVector.x();

	Target(2,0) = (1 - c) * UnitVector.x() * UnitVector.z() - s * UnitVector.y();
	Target(2,1) = (1 - c) * UnitVector.y() * UnitVector.z() + s * UnitVector.x();
	Target(2, 2) = (1 - c) * UnitVector.z() * UnitVector.z() + c;

	return Target;
}

Matrix4f DT_Transform::Scale(Vector3f& Targetscale)
{
	Matrix4f UnitMatrix = Matrix4f::Identity();
	UnitMatrix(0, 0) *= Targetscale.x();
	UnitMatrix(1, 1) *= Targetscale.y(); 
	UnitMatrix(2, 2) *= Targetscale.z();

	return UnitMatrix;
}

Matrix4f DT_Transform::LookAt(Vector3f& Eye, Vector3f& Target, Vector3f& upDir)
{
	Vector3f forawrd = Eye - Target;
	forawrd = forawrd.normalized();

	Vector3f right = forawrd.cross(upDir);
	right = right.normalized();

	Vector3f up = forawrd.cross(right);
	up = up.normalized();

	Matrix4f mat = Matrix4f::Identity();
	mat(0, 0) = right.x();
	mat(0, 1) = right.y();
	mat(0, 2) = right.z();
	mat(1, 0) = up.x();
	mat(1, 1) = up.y();
	mat(1, 2) = up.z();

	mat(0, 3) = -right.x() * Eye.x() - right.y() * Eye.y() - right.z() * Eye.z();
	mat(1, 3) = -up.x() * Eye.x() - up.y() * Eye.y() - up.z() * Eye.z();
	mat(2, 3) = -forawrd.x() * Eye.x() - forawrd.y() * Eye.y() - forawrd.z() * Eye.z();

	return mat;
}

