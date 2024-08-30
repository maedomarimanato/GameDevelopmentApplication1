#pragma once

#include"../GameObject.h"

class Player : public GameObject
{
private:
	int animation[2]; //アニメーション画像
	int animation_count;//アニメーション時間
	int flip_flag; //反転グラフ


public:
	Player();
	~Player();

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
	int background_image;
	// 画像サイズのメンバ変数
	Vector2D background_size;
	Vector2D player_size;

	// 画面の幅と高さ
	static constexpr int SCREEN_WIDTH = 800;
	static constexpr int SCREEN_HEIGHT = 600;


};