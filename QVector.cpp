#include "QVector.h"


QVector::QVector(double x, double y, double z)
	:x_(x), y_(y), z_(z)
{

}

QVector::QVector(const QVector& obj)
{
	x_ = obj.x_;
	y_ = obj.y_;
	z_ = obj.z_;

}

QVector::~QVector()
{
}

void QVector::setX(double a)
{
	x_ = a;
}

void QVector::setY(double a)
{
	y_ = a;
}

void QVector::setZ(double a)
{
	z_ = a;
}

QVector QVector::sumVec(const QVector& a, const  QVector& b)
{
	QVector res(0, 0, 0);
	res.x_ = a.x_ + b.x_;
	res.y_ = a.y_ + b.y_;
	res.z_ = a.z_ + b.z_;

	return res;
}

double QVector::multSka(QVector& a, QVector& b)const
{
	return (a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_);
}

QVector QVector::multVec(const QVector & a, const  QVector & b)
{
	QVector res(0, 0, 0);
	res.x_ = a.y_ * b.z_ - a.z_ * b.y_;
	res.y_ = (-1) * (a.x_ * b.z_ - a.z_ * b.x_);
	res.z_ = a.x_ * b.y_ - a.y_ * b.x_;
	return res;
}

double QVector::multSmesh(const  QVector & a, const  QVector & b, const  QVector & c) const
{
	return (a.x_ * b.y_ * c.z_ + a.y_ * b.z_ * c.x_ + a.z_ * b.x_ * c.y_ - a.z_ * b.y_ * c.x_ - a.y_ * b.x_ * c.z_ - a.x_ * b.z_ * c.y_);
}

double QVector::x() const
{
	return x_;
}

double QVector::y() const
{
	return y_;
}

double QVector::z() const
{
	return z_;
}


QVector operator+(const QVector & a, const QVector & b)
{
	QVector res(0, 0, 0);
	res.x_ = a.x_ + b.x_;
	res.y_ = a.y_ + b.y_;
	res.z_ = a.z_ + b.z_;

	return res;
}

double operator*(const QVector & a, const QVector & b)
{
	return (a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_);
}

void QVector::print()
{
	std::cout << x_ << " " << y_ << " " << z_ << std::endl;
}

void QVector::operator=(const QVector & obj)
{
	x_ = obj.x_;
	y_ = obj.y_;
	z_ = obj.z_;
}

void QVector::operator[](int a)
{
	x_ *= a;
	y_ *= a;
	z_ *= a;
}