
#include "Quat.h"
#include "QVector.h"

#include <iostream>

QVector quat_transform_vector(QVector vec, Quat q) {

	Quat t(0, 0, 0, 0);
	Quat m(0, 0, 0, 0);
	QVector res(0, 0, 0);
	t.quat_mul_vector(q, vec);
	t = (t * m.quat_invert(q));
	res.setX(t.x());
	res.setY(t.y());
	res.setZ(t.z());
	return res;

}
int main()
{
	QVector q(1, 2, 1);
	std::complex< double > z1(1.0, 2.0);
	std::complex< double > z2(3.0, 4.0);

	Quat p(5, 4, 3, 2);//конструирование вручную
	Quat z(3, 4, 5, 6);
	Quat r(0.707, 0, 0.707, 0);

	Quat vu(30.0, q);//с помощью вектора и угла

	Quat com(z1, z2);// с помощью комплексных чисел

	//умножение кватернионов
	std::cout << "multiplication Quats " << std::endl;
	(p * z).print();
	r = (com * vu);
	r.print();

	Quat m(0, 0, 0, 0);
	//нахождение обратного
	std::cout << "invert " << std::endl;
	m.quat_invert(r);
	m.print();

	QVector k(5, 2, 3);
	QVector n(2, 7, 4);
	QVector v(0, 0, 0);

	//сложение векторов
	std::cout << "addition vectors " << std::endl;
	(k + n).print();
	v = (k + n);
	v.print();

	//скалярное произведение векторов
	std::cout << "scalar  multiplication" << std::endl;
	std::cout << (k * n) << std::endl;

	//векторное произведние векторов
	std::cout << "vector  multiplication" << std::endl;
	v.multVec(k, n);
	v.print();

	//смешанное умножение
	std::cout << "mixed multiplication" << std::endl;
	std::cout << k.multSmesh(k, n, q) << std::endl;

	//перегрузка []
	std::cout << "override []" << std::endl;
	v[5];
	v.print();


	//поворот вектора на основе кватерниона
	std::cout << "quat_transform_vector" << std::endl;
	quat_transform_vector(n, p).print();

}
