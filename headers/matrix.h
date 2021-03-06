#ifndef MATRIX
#define MATRIX
#include <new>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

class Matrix4f;
class Vec4f;

class Matrix4f {
public:
	Matrix4f();
	~Matrix4f();
	Matrix4f operator *(const Matrix4f m);
	const float get(const int, const int) const;
	void set(const int, const int, const float);
	const Vec4f *operator [](const int) const;
	void transform(const Matrix4f *);
	void subtract(const Vec4f);
	void extend(const Matrix4f *);
	void addCol(Vec4f);
	void clear();
	void print();
	int width;
private:
	std::vector<Vec4f> _cols;
};

class Vec4f {
public:
	Vec4f();
	Vec4f(const float []);
	Vec4f(const float, const float, const float, const float);
	~Vec4f() {};
	float  operator [](const int) const;
	float& operator [](const int);
	void operator =(const Vec4f *);
	float dot  (const Vec4f &);
	Vec4f cross(const Vec4f &);
private:
	float _data[4];
};
#endif
