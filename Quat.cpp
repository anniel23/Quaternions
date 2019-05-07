#include "Quat.h"



Quat::Quat(double a, double b, double c, double d)
	:w_(a), x_(b), y_(c), z_(d)
{
}

Quat::Quat(double rotate_angle, QVector rotate_vector)
{
	rotate_vector = normals(rotate_vector);
	w_ = cos(rotate_angle / 2);
	x_ = rotate_vector.x() * sin(rotate_angle / 2);
	y_ = rotate_vector.y() * sin(rotate_angle / 2);
	z_ = rotate_vector.z() * sin(rotate_angle / 2);
}

Quat::Quat(std::complex<double> x, std::complex<double> y)
{
	w_ = x.real();
	x_ = x.imag();
	y_ = y.real();
	z_ = y.imag();
}
Quat::Quat(const Quat & obj)
{
	w_ = obj.w_;
	x_ = obj.x_;
	y_ = obj.y_;
	z_ = obj.z_;
}


Quat::~Quat()
{
}


QVector Quat::normals(QVector & vec)
{
	double length;
	length = sqrt(vec.x() * vec.x() + vec.y() * vec.y() + vec.z() * vec.z());
	x_ = vec.x() / length;
	y_ = vec.y() / length;
	z_ = vec.z() / length;

	return QVector(x_, y_, z_);
}


Quat & Quat::quat_scale(Quat & q, double val)
{
	q.w_ = q.w_ * val;
	q.x_ = q.x_ * val;
	q.y_ = q.y_ * val;
	q.z_ = q.z_ * val;
	return q;

}

double Quat::quat_length(Quat & q)
{
	return sqrt(q.w_ * q.w_ + q.x_ * q.x_ + q.y_ * q.y_ + q.z_ * q.z_);
}

Quat& Quat::normalize(Quat & q)
{
	double n;
	n = quat_length(q);
	if (n != 0)	return quat_scale(q, 1 / n);
}

Quat Quat::quat_invert(Quat & q)
{
	Quat res(0, 0, 0, 0);

	res.w_ = q.w_;
	res.x_ = -q.x_;
	res.y_ = -q.y_;
	res.z_ = -q.z_;
	normalize(res);
	*this = res;
	return *this;
}

Quat& Quat::quat_mul_vector(Quat & a, QVector & b) {

	Quat res(0, 0, 0, 0);
	w_ = -a.x_ * b.x() - a.y_ * b.y() - a.z_ * b.z();
	x_ = a.w_ * b.x() + a.y_ * b.z() - a.z_ * b.y();
	y_ = a.w_ * b.y() - a.x_ * b.z() + a.z_ * b.x();
	z_ = a.w_ * b.z() + a.x_ * b.y() - a.y_ * b.x();
	return *this;

}

void Quat::operator=(const Quat & obj)
{
	w_ = obj.w_;
	x_ = obj.x_;
	y_ = obj.y_;
	z_ = obj.z_;

}

void Quat::print()
{
	std::cout << w_ << " " << x_ << " " << y_ << " " << z_ << std::endl;
}

double Quat::x() const
{
	return x_;
}

double Quat::y() const
{
	return y_;
}

double Quat::z() const
{
	return z_;
}

double Quat::w() const
{
	return w_;
}



Quat operator*(const Quat & a, const Quat & b)
{
	Quat res(0, 0, 0, 0);
	res.w_ = a.w_ * b.w_ - a.x_ * b.x_ - a.y_ * b.y_ - a.z_ * b.z_;
	res.x_ = a.w_ * b.x_ + a.x_ * b.w_ + a.y_ * b.z_ - a.z_ * b.y_;
	res.y_ = a.w_ * b.y_ - a.x_ * b.z_ + a.y_ * b.w_ + a.z_ * b.x_;
	res.z_ = a.w_ * b.z_ + a.x_ * b.y_ - a.y_ * b.x_ + a.z_ * b.w_;
	return res;
}