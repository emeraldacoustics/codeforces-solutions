#include <bits/stdc++.h>

using namespace std;

typedef long long itype;
typedef long double ftype;

const ftype pi = acosl(-1); // 3.1415926535897932384626433832795l
const ftype radian = 180 / pi; // 57.295779513082320876798154814105l
const ftype eps = 1e-5l;
const int inf = 0x7f7f7f7f;
const long long infll = 0x7f7f7f7f7f7f7f7fll;
const ftype infl = 1e20l;

template <class T>
inline int sgn(const T & x)
{
	return (x > eps) - (x < -eps);
}

template <class T>
inline T trigonometric(const T & x)
{
	if (x < -1)
		return -1;
	else if (x < 1)
		return x;
	else
		return 1;
}

#define Vector Point

template <class T>
class Point
{
public:
	T x, y;

	Point(void) : x(0), y(0)
	{

	}

	Point(const T & x, const T & y) : x(x), y(y)
	{

	}

	template <class S>
	Point(const Point<S> & src) : x(src.x), y(src.y)
	{

	}

	Vector operator + (const Vector & rhs) const
	{
		return Vector(x + rhs.x, y + rhs.y);
	}

	Vector operator - (const Vector & rhs) const
	{
		return Vector(x - rhs.x, y - rhs.y);
	}

	T length(void) const
	{
		return sqrtl(x * x + y * y);
	}

	T length2(void) const
	{
		return x * x + y * y;
	}

	T distance(const Point & rhs) const
	{
		return (rhs - *this).length();
	}

	T distance2(const Point & rhs) const
	{
		return (rhs - *this).length2();
	}

	Vector operator * (const T & rhs) const
	{
		return Vector(x * rhs, y * rhs);
	}

	Vector operator / (const T & rhs) const
	{
		return Vector(x / rhs, y / rhs);
	}

	T operator * (const Vector & rhs) const
	{
		return x * rhs.y - y * rhs.x;
	}

	T operator & (const Vector & rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	T cross(const Point & lhs, const Point & rhs) const
	{
		return (lhs - *this) * (rhs - *this);
	}

	T operator ^ (const Vector & rhs) const
	{
		T l1 = length(), l2 = rhs.length();
		if (sgn(l1) == 0 || sgn(l2) == 0)
			return 0;
		int s = sgn(*this * rhs);
		T a = acosl(trigonometric((*this & rhs) / l1 / l2));
		return s < 0 ? -a : a;
	}
};

template <class T>
Point<T> bary(const Point<T> & A, const T & a, const Point<T> & B, const T & b, const Point<T> & C, const T & c)
{
	return (A * a + B * b + C * c) / (a + b + c);
}

template <class T>
Point<T> circumcenter(const Point<T> & A, const Point<T> & B, const Point<T> & C)
{
	T a = B.distance2(C), b = C.distance2(A), c = A.distance2(B);
	return bary(A, a * (b + c - a), B, b * (c + a - b), C, c * (a + b - c));
}

int main(void)
{
	ios::sync_with_stdio(false);

	Point<long double> p[3];

	for (int i = 0; i < 3; i++)
		cin >> p[i].x >> p[i].y;

	if (sgn(p[0].cross(p[1], p[2])) < 0)
		reverse(p, p + 3);

	auto o = circumcenter(p[0], p[1], p[2]);

	long double a[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = (p[i] - o) ^ (p[(i + 1) % 3] - o);
		if (sgn(a[i]) < 0)
			a[i] += pi * 2;
	}

	long double ans = o.distance2(p[0]) * pi;
	for (int k = 3; k <= 100; k++)
	{
		bool flg = true;
		for (int i = 0; i < 3; i++)
		{
			int v = a[i] * k / pi / 2 + eps;
			if (sgn(a[i] - pi * 2 * v / k) != 0)
			{
				flg = false;
				break;
			}
		}
		if (flg)
			ans = min(ans, o.distance2(p[0]) * k * sinl(pi / k) * cosl(pi / k));
	}

	cout << fixed << setprecision(20);
	cout << ans << endl;

	return 0;
}
