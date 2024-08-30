#include"DxLib.h"
#include"Utility/inputControl.h"
#include "Objects/Player.h"

//メイン関数
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hprevInstance,
	_In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//異常を通知
		return -1;
	}
	//プレイヤーのオブジェクト作成
	Player* player = new Player();

	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//入力制御機能更新処理
		InputControl::Update();

		//プレイヤー更新処理
		player->Update();

		//壁に触れたら反対側に移動する処理
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;//左の壁から右の壁
			}
			else
			{
				tmp.x = 0.0f;//右の壁から左の壁
			}
			player->SetLocation(tmp);
		}

		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;//上の壁から下の壁
			}
			else
			{
				tmp.y = 0.0f;//座標更新
			}
		}
		//座標更新
		player->SetLocation(tmp);

		//画面クリア
		ClearDrawScreen();

		//描画処理
		player->Draw();

		//画面の内容を表画面に反映
		ScreenFlip();

		//終了ボタン処理
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	//プレイヤー削除
	delete player;

	//DXライブラリの終了時処理
	DxLib_End(); 

	//正常終了を通知
	return 0;
	}
