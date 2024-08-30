#pragma once

#include"../Utility/Vector2D.h"
//プレイヤー用クラス
class Player
{
private:
	Vector2D location;//位置座標
	Vector2D direction;//方向
	float radius;//半径

public:
	Player();
	Player(float x, float y);
	Player(Vector2D location);
	~Player();

	void Update();//更新処理
	void Draw() const;//描画処理

	void SetLocation(float x, float y);//Locationセッター
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;//Locationゲッター
	float GetRadius();//radiusのゲッター

private:
	void Movement();//移動処理
};