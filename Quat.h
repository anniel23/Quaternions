#pragma once

#include "QVector.h"
#include<iostream>
#include <vector>
#include <complex>

class Quat
{
public:

	Quat(double a, double b, double c, double d);

	Quat(double rotate_angle, QVector rotate_vector);
	Quat(std::complex<double> x, std::complex<double> y);
	Quat(const Quat& obj);

	~Quat();

	QVector normals(QVector& vec);

	Quat& quat_scale(Quat& q, double val);
	double quat_length(Quat& q);
	Quat& normalize(Quat& q);
	Quat quat_invert(Quat& q);

	Quat& quat_mul_vector(Quat& a, QVector& b);

	void operator=(const Quat& obj);
	friend Quat  operator*(const Quat& a, const Quat& b);
	void print();
	double x() const;
	double y() const;
	double z() const;
	double w() const;

private:
	double w_;
	double x_, y_, z_;
};

Quat operator*(const Quat& a, const Quat& b);