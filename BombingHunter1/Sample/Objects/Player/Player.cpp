#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

// コンストラクタ
Player::Player() : animation_count(0), flip_flag(FALSE), background_image(NULL)
{
    animation[0] = NULL;
    animation[1] = NULL;
    background_size = Vector2D(800.0f, 600.0f); //背景画像のサイズ
    player_size = Vector2D(64.0f, 64.0f); //プレイヤー画像のサイズ
}

// デストラクタ
Player::~Player()
{
    Finalize();
}

// 初期化処理
void Player::Initialize()
{
    // 当たり判定の短形の大きさを指定
    box_size = Vector2D(32.0f);
    // 初期位置を設定
    location = Vector2D(200.0f, 240.0f);

    // 画像の読み込み
    animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
    animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");

    // エラーチェック
    if (animation[0] == -1 || animation[1] == -1)
    {
        throw("鳥パイロットの画像がありません\n");
    }

    // 背景画像の読み込み
    background_image = LoadGraph("Resource/Images/BackGround.png");

    // エラーチェック
    if (background_image == -1)
    {
        throw("背景画像がありません\n");
    }

    // 向きの設定
    radian = 0.0f;

    // 当たり判定の大きさを設定
    box_size = Vector2D(64.0f);

    // 初期位置を画面上部に設定
    location = Vector2D(34.0f, player_size.y / 2.0f);
    // 初期画像の設定
    image = animation[0];
}

// 更新処理
void Player::Update()
{
    // 移動処理
    Movement();
    // アニメーション制御
    AnimationControl();
}

// 描画処理
void Player::Draw() const
{
    // 背景画像の描画
    DrawExtendGraph(0, 0, background_size.x, background_size.y, background_image, FALSE);

    // プレイヤー画像の描画
    DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

    // デバッグ用
#if _DEBUG
    // 当たり判定の可視化
    Vector2D ul = location - (box_size / 2.0f);
    Vector2D br = location + (box_size / 2.0f);

    DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

// 終了時処理
void Player::Finalize()
{
    // 使用した画像を開放する
    DeleteGraph(animation[0]);
    DeleteGraph(animation[1]);
    DeleteGraph(background_image);
}

// 当たり判定
void Player::OnHitCollision(GameObject* hit_object)
{
    // 当たった時の処理
}

// 移動処理
void Player::Movement()
{
    // 移動の速さ
    Vector2D velocity = 0.0f;

    // 左右移動
    if (InputControl::GetKey(KEY_INPUT_LEFT))
    {
        velocity.x -= 1.0f;
        flip_flag = TRUE;
    }
    else if (InputControl::GetKey(KEY_INPUT_RIGHT))
    {
        velocity.x += 1.0f;
        flip_flag = FALSE;
    }

    // 現在の位置座標に速さを加算する
    location += velocity;

    // 位置の制限
    float half_width = player_size.x / 1.3f;
    float half_height = player_size.y / 0.3f;

    if (location.x < half_width)
    {
        location.x = half_width;
    }
    else if (location.x > SCREEN_WIDTH - half_width)
    {
        location.x = SCREEN_WIDTH - half_width;
    }

    if (location.y < half_height)
    {
        location.y = half_height;
    }
    else if (location.y > SCREEN_HEIGHT - half_height)
    {
        location.y = SCREEN_HEIGHT - half_height;
    }
}

// アニメーション制御
void Player::AnimationControl()
{
    // フレームカウントを加算する
    animation_count++;

    // 60フレーム目に到達したら
    if (animation_count >= 60)
    {
        // カウントのリセット
        animation_count = 0;

        // 画像の切り替え
        if (image == animation[0])
        {
            image = animation[1];
        }
        else
        {
            image = animation[0];
        }
    }
}
