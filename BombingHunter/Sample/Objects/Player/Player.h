#pragma once

#include "../GameObject.h"

class Player : public GameObject // GameObjectを継承
{
private:
    int animation[2]; //アニメーション画像
    int animation_count;//アニメーション時間
    int flip_flag; //反転グラフ


public:
    Player();
    ~Player();

    //初期化処理
    void Initialize() override;
    //更新処理
    void Update() override;
    //描画処理
    void Draw() const override;
    //初期化処理
    void Finalize() override;

   //当たり判定通知処理
    void OnHitCollision(GameObject* hit_object) override;

private:
  //移動処理
    void Movement();
    //アニメーション制御
    void AnimationControl();

};
