#pragma once

#include"../GameObject.h"

class Gold : public GameObject
{
private:
	int flip_flag;//反転グラフ
	int animation[5]; //アニメーション画像
	int animation_count;//アニメーション時間
	Vector2D direction;//進行方向


public:
	Gold();
	~Gold();

	void Initialize(const Vector2D& player_position);

	virtual void Initialize() override; //初期化処理
	virtual void Update() override; //更新処理
	virtual void Draw() const override;//描画処理
	virtual void Finalize() override; //終了時処理



	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* Hit_object) override;

private:

	//移動処理
	void Movement();
	//アニメーション制御
	void AnimationControl();
};