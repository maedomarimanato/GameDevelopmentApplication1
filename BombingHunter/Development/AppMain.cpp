#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Scene/Scene.h"


//メイン関数(プログラムはここから始まります)
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hprevInstance,
	_In_ LPSTR IpCmdline, _In_ int nShowCmd)
{
	//Windowモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドサイズ（横 : 780px, 縦 : 480px)を設定
	SetGraphMode(780, 480, 32);
	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//異常を検知z
		return -1;
	}
	//敵の初期化

	//ローカル変数定義
	Scene* scene = new Scene(); //シーン情報
	int result = 0; //終了状態情報

	//描画先を裏画面から始めるように指定する
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//シーンの初期化
		scene->Initialize();

		//メインループ（ウィンドウの異常発生 or ESCキーが押されたら、ループ終了)
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) !=
			TRUE)
		{
			//入力機能の更新
			InputControl::Update();

			//シーンの更新処理
			scene->Update();

			//画面の初期化
			ClearDrawScreen();

			//シーンの描画処理
			scene->Draw();

			//裏画面の内容を表画面に反映する
			ScreenFlip();
		}
	}
	catch (const char* error_log)
	{
		//エラー情報をLog.txtに出力する
		OutputDebugString(error_log);
		//異常状態に変更する
		result = -1;
	}
	//シーン情報の削除をする
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DXライブラリの終了時処理
	DxLib_End();

	//終了状態を通知
	return result;
}
