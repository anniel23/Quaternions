#pragma once
#include<iostream>
class QVector
{
public:
	QVector(double x, double y, double z);
	QVector(const QVector& obj);
	~QVector();
	void setX(double a);
	void setY(double a);
	void setZ(double a);

	QVector sumVec(const QVector& a, const QVector& b);
	double multSka(QVector& a, QVector& b) const;
	QVector multVec(const QVector& a, const QVector& b);
	double multSmesh(const QVector& a, const QVector& b, const QVector& c)const;

	void print();
	void operator=(const QVector& obj);
	void operator[](int a);
	friend QVector operator+(const QVector& a, const QVector& b);
	friend double operator*(const QVector& a, const QVector& b);
	double x() const;
	double y() const;
	double z() const;

private:
	double x_, y_, z_;
};
QVector operator+(const QVector& a, const QVector& b);
double operator*(const QVector& a, const QVector& b);