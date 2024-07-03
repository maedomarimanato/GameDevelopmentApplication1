#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"


// コンストラクタ
Player::Player() : animation_count(0), flip_flag(FALSE)
{
    animation[0] = NULL;
    animation[1] = NULL;
    player_size = Vector2D(34.0f, 34.0f);      // プレイヤー画像のサイズ
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
    box_size = Vector2D(32.0f, 32.0f);

    // 初期位置を設定
    location = Vector2D(300.0f, 130.0f);

    // 画像の読み込み
    animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
    animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");


    // エラーチェック
    if (animation[0] == -1 || animation[1] == -1)
    {
        printf("鳥パイロットの画像がありません\n");
        return;
    }

 

    // 向きの設定
    radian = 0.0f;

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
    // 爆弾発射処理
    FireBomb();

    // 爆弾の更新
    for (auto it = bombs.begin(); it != bombs.end();)
    {
        it->Update();
        if (it->IsOffScreen())
        {
            it = bombs.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// 描画処理
void Player::Draw() const
{
    

    // プレイヤー画像の描画
    DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

    // 爆弾の描画
    for (const auto& bomb : bombs)
    {
        bomb.Draw();
    }

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
    if (animation[0] != NULL) DeleteGraph(animation[0]);
    if (animation[1] != NULL) DeleteGraph(animation[1]);
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
    Vector2D velocity(0.0f, 0.0f);

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
    // 左右移動
    if (InputControl::GetKey(KEY_INPUT_UP))
    {
        velocity.y -= 1.0f;
        flip_flag = TRUE;
    }
    else if (InputControl::GetKey(KEY_INPUT_DOWN))
    {
        velocity.y += 1.0f;
        flip_flag = FALSE;
    }
    

    // 現在の位置座標に速さを加算する
    location += velocity;

    // 位置の制限
    float half_width = player_size.x / 2.0f;
    float half_height = player_size.y / 2.0f;
    float half_up = player_size.y / 2.0f;
    float half_down = player_size.y / 2.0f;

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
    if (location.y < half_up)
    {
        location.y = half_up;
    }

    else if (location.y > SCREEN_UP - half_up)
    {
        location.y = SCREEN_UP - half_up;
    }

    if (location.y < half_down)
    {
        location.y = half_down;
    }
    else if (location.y > SCREEN_DOWN - half_down)
    {
        location.y = SCREEN_DOWN - half_down;
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
// 爆弾発射処理
void Player::FireBomb()
{
    if (InputControl::GetKey(KEY_INPUT_SPACE))
    {
        Vector2D bomb_velocity(0.0f, 3.0f); // 爆弾の速度を下向きに設定
        bombs.emplace_back(location, bomb_velocity);

    }
}
