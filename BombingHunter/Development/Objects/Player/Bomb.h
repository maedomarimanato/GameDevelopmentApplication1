#pragma once

#include"DxLib.h"
#include "../../Utility/Vector2D.h"

class Bomb
{
public:
    Bomb(const Vector2D& position, const Vector2D& velocity);
  

    //更新処理
    void Update();
    //描画処理
    void Draw() const;
    bool IsOffScreen() const;

private:
    Vector2D position;
    Vector2D velocity;
    int image;//画像
    int soundHandle; // 追加：音声のハンドル


    // 画面の幅と高さ
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 600;
};


