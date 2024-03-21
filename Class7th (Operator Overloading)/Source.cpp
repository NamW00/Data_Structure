#include <iostream>

using namespace std;

class Vector2
{
public:
	int x;
	int y;

	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	// Vector2 Vector2::operator+(const Vector2& vector2)
	Vector2 operator+(const Vector2& vector2)
	{
		// 밑에 값과 같이 누적을 시키면 안된다.
		// this->x += vector2.x;
		// this->y += vector2.y;
		Vector2 other
		(
			this->x + vector2.x,
			this->y + vector2.y
		);
		return  other;
	}

	Vector2 operator-(const Vector2& vector2)
	{
		// 밑에 값과 같이 누적을 시키면 안된다.
		// this->x += vector2.x;
		// this->y += vector2.y;
		Vector2 other
		(
			this->x - vector2.x,
			this->y - vector2.y
		);
		return  other;
	}


	Vector2 operator*(const Vector2& vector2)
	{
		// 밑에 값과 같이 누적을 시키면 안된다.
		// this->x += vector2.x;
		// this->y += vector2.y;
		Vector2 other
		(
			this->x * vector2.x,
			this->y * vector2.y
		);
		return  other;
	}


	Vector2 operator*(int value)
	{
		Vector2 other
		(
			this->x * value,
			this->y * value
		);

		return  other;
	}


	Vector2 operator/(const Vector2& vector2)
	{
		// 밑에 값과 같이 누적을 시키면 안된다.
		// this->x += vector2.x;
		// this->y += vector2.y;
		Vector2 other
		(
			this->x / vector2.x,
			this->y / vector2.y
		);
		return  other;
	}



};

// 이미 곱 연산이 있기때문에 Class안에 선언하면 중복되어 에러가 뜨게 된다.
Vector2 operator*(int value, Vector2 vector2)
{
	return vector2 * value;
}

int main()
{
	Vector2 vector1(10, 20);
	Vector2 vector2(5, 5);



	Vector2 vector4 = vector1 + vector2;
	Vector2 vector5 = vector1 - vector2;
	Vector2 vector6 = vector1 * vector2;
	Vector2 vector7 = vector1 / vector2;
	Vector2 vector8 = vector1 * 8;
	Vector2 vector9 = 10 * vector1;

	// Vector2 operator+(const Vector2 & vector2) -> Vector
	// Vector2 Vector2::operator+(const Vector2& vector2)
	cout << "vector1 + vector2" << endl;
	cout << "vector4의 x값" << vector4.x << endl;
	cout << "vector4의 y값" << vector4.y << endl;
	cout << endl;

	cout << "vector1 - vector2" << endl;
	cout << "vector4의 x값" << vector5.x << endl;
	cout << "vector4의 y값" << vector5.y << endl;
	cout << endl;

	cout << "vector1 * vector2" << endl;
	cout << "vector6의 x값" << vector6.x << endl;
	cout << "vector6의 y값" << vector6.y << endl;
	cout << endl;

	cout << "vector1 / vector2" << endl;
	cout << "vector7의 x값" << vector7.x << endl;
	cout << "vector7의 y값" << vector7.y << endl;
	cout << endl;

	cout << "vector1 / vector2" << endl;
	cout << "vector8의 x값" << vector8.x << endl;
	cout << "vector8의 y값" << vector8.y << endl;
	cout << endl;


	cout << "vector1 / vector2" << endl;
	cout << "vector9의 x값" << vector9.x << endl;
	cout << "vector9의 y값" << vector9.y << endl;


	return 0;
}