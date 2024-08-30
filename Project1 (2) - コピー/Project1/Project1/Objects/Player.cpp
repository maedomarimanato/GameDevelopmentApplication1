#include"Player.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

//コンストラクタ
Player::Player() : location(), direction(0.0f), radius(15.0f)
{
}
//コンストラクタ
Player::Player(float x, float y) : location(x,y), direction(0.0f), radius(15.0f)
{
}
//コンストラクタ
Player::Player(Vector2D location) :  direction(0.0f), radius(15.0f)
{
}
//デストラクタ
Player::~Player()
{

}

//更新処理
void Player::Update()
{
	//移動処理
	Movement();
}
//描画処理
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255),
		TRUE);
}
//位置情報設定処理
void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}

void Player::SetLocation(Vector2D location)
{
	this->location = location;
}
//位置情報取得処理
Vector2D Player::GetLocation() const
{
	return location;
}
//半径取得
float Player::GetRadius()
{
	return radius;
}

//移動処理
void Player::Movement()
{
	//キー移動処理
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;
	}
	//座標移動
	location += direction;
}
