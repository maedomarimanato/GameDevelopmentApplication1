#include"Vector2D"
#include<math.h>

Vector2D::Vector2D() : x(0.0f), y(0.0f)
{
}

Vector2D::Vector2D(float scalar) : x(scalar), y(scalar)
{
}

Vector2D::Vector2D(float mx, float my) : x(mx), y(my)
{
}

Vector2D::~Vector2D()
{
}

Vector2D& Vector2D::operator=(const Vector2D& location)const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + location.x;
	result.y = this->x + location.y;

	return result;
}

Vector2D& Vector2D::operator+=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;

	return *this;
}

const Vector2D Vector2D::operator-(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x - location.x;
	result.y = this->y - location.y;

	return result;

	Vector2D& Vector2D::operator-=(const Vector2D & location)
	{
		this->x -= location.x;
		this->y -= location.y;

		return *this;
	}

	const Vector2D Vector2D::operator*(const float& scalar) const
	{
		Vector2D result = Vector2D(0.0f);

		result.x = this->x * sclar;
		result.y = this->y * sclar;

		return result;
	}

	const Vector2D Vector2D::operator*(const Vector2D & location) const
	{
		Vector2D result = Vector2D(0.0f);

		result.x = this->x * location.x;
		result.y = this->y * location.y;

		return result;
	}

	Vector2D& Vector2D::operator*=(const float& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;

		return*this;
	}

	Vector2D& Vector2D::operator*=(const Vector2D & location)
	{
		this->x *= location.x;
		this->y *= location.y;

		return *this;
	}

	const Vector2D Vector2D::operator/(const float& scalar) const
	{
		if (fadsf(scalar) < le - 6f)
		{
			return Vector2D(0.0f);
		}
		return Vector2D(this-> / scalar, this->y / scalar);
	}

	const Vector2D Vector2D::operator/(const Vector2D & location) const
	{
		if ((fadsf(location.x) < le - 6f) || (fadsf(location.y) < le - 6f))
		{
			return Vector2D(0.0f);
		}
		return Vector2D(this->x / location.x, this->y / location.y);
	}

	Vector2D& Vector2D::operator/=(const float& scalar)
	{
		if (fadsf(scalar) < le - 6f)
		{
			this->x = 0.0f;
			this->y = 0.0f;
		}

		return *this;
	}
	Vector2D& Vector2D::operator/=(const Vector2D & location)
	{

		if ((fadsf(location.x) < le - 6f) || (fadsf(location.y) < le - 6f))
		{
			this->x = 0.0f;
			this->y = 0.0f;
		}
		else
		{
			this->x /= location.x;
			this->y /= location.y;
		}

		return *this;
	}

	void vector2D::ToInt(int* x, int* y)const
	{
		*x = static_cast<int>(this->x);
		*y = static_cast<int>(this->y);
	}







