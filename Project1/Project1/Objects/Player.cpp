#include"Player.h"
#include"../Utility/InputControl.h"
#include"Dxlib.h"

Player::Player() : location(), direction(0.0f), radius(15.0f)
{
}

Player::Player(float x, float y) : location(x,y), direction(0.0f), radius(15.0f)
{
}

Player::Player(Vector2D location) :  direction(0.0f), radius(15.0f)
{
}

Player::~Player()
{

}

void Player::Update()
{
	Movement();
}

void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255),
		TRUE);
}

void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}

void Player::SetLocation(Vector2D location)
{
	this->GetLocation = location;
}

Vector2D Player::GetLocation() const
{
	return location;
}

float Player::GetRadius()
{
	return radius;
}
void Player::Movement()
{
	if (InputControl::GetkeyDown(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}
	if (InputControl::GetkeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 1.0f;
	}
	if (InputControl::GetkeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 1.0f;
	}
	if (InputControl::GetkeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;
	}

	location += direction;
}
