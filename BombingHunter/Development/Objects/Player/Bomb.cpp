#include "Bomb.h"
#include "DxLib.h"

// コンストラクタ
Bomb::Bomb(const Vector2D& position, const Vector2D& velocity)
    : position(position), velocity(velocity)
{
    image = LoadGraph("Resource/Images/Bomb.png");
     soundHandle = LoadSoundMem("Resource/Sounds/pan.wav"); // 音声ファイルを読み込む
    PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK); // 音声を再生する
}

// 更新処理
void Bomb::Update()
{
    position += velocity;
}

// 描画処理
void Bomb::Draw() const
{
    DrawGraph((int)position.x, (int)position.y, image, TRUE);
}

// 画面外判定
bool Bomb::IsOffScreen() const
{
    return position.x < 0 || position.x > SCREEN_WIDTH || position.y < 0 || position.y > SCREEN_HEIGHT;
}

