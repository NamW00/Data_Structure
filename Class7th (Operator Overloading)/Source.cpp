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
		// �ؿ� ���� ���� ������ ��Ű�� �ȵȴ�.
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
		// �ؿ� ���� ���� ������ ��Ű�� �ȵȴ�.
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
		// �ؿ� ���� ���� ������ ��Ű�� �ȵȴ�.
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
		// �ؿ� ���� ���� ������ ��Ű�� �ȵȴ�.
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

// �̹� �� ������ �ֱ⶧���� Class�ȿ� �����ϸ� �ߺ��Ǿ� ������ �߰� �ȴ�.
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
	cout << "vector4�� x��" << vector4.x << endl;
	cout << "vector4�� y��" << vector4.y << endl;
	cout << endl;

	cout << "vector1 - vector2" << endl;
	cout << "vector4�� x��" << vector5.x << endl;
	cout << "vector4�� y��" << vector5.y << endl;
	cout << endl;

	cout << "vector1 * vector2" << endl;
	cout << "vector6�� x��" << vector6.x << endl;
	cout << "vector6�� y��" << vector6.y << endl;
	cout << endl;

	cout << "vector1 / vector2" << endl;
	cout << "vector7�� x��" << vector7.x << endl;
	cout << "vector7�� y��" << vector7.y << endl;
	cout << endl;

	cout << "vector1 / vector2" << endl;
	cout << "vector8�� x��" << vector8.x << endl;
	cout << "vector8�� y��" << vector8.y << endl;
	cout << endl;


	cout << "vector1 / vector2" << endl;
	cout << "vector9�� x��" << vector9.x << endl;
	cout << "vector9�� y��" << vector9.y << endl;


	return 0;
}