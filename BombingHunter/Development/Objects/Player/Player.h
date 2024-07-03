#pragma once


#include "Bomb.h"
#include <vector>
#include "../GameObject.h"

class Player : public GameObject // GameObjectを継承
{
public:
    Player();
    ~Player();

    //初期化処理
    void Initialize() override;
    //更新処理
    void Update() override;
    //描画処理
    void Draw() const override;
    //終了時処理
    void Finalize() override;

    //当たり判定通知処理
    void OnHitCollision(GameObject* hit_object) override;

private:
    //移動処理
    void Movement();
    //アニメーション制御
    void AnimationControl();
    void FireBomb(); // 爆弾発射のための新しい関数

    Vector2D location;
    //画像大きさ
    Vector2D player_size;
    Vector2D background_size;
    Vector2D box_size;

    float radian;//半径
    int animation_count;//アニメーション制御
    int flip_flag;
    int background_image;//背景画像
    int image;//画像
    int animation[2];//アニメーション

    std::vector<Bomb> bombs; // 爆弾のリスト


    // 画面の幅と高さ
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 500;
    static constexpr int SCREEN_UP = 600;
    static constexpr int SCREEN_DOWN = 450;

};
