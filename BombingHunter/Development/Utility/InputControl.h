#pragma once

#define D_KEYCODE_MAX (256)
//入力制御クラス(メンバは静的で所有する）
class InputControl
{
//基本的にメンバ変数はプライベート
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];
//関数はパブリック
public:
	static void Update();
	static InputControl* GetInstance();
	static void DeleteInstance();
	//キー入力取得系
	static bool GetKey(int key_code);
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);
//外部公開の必要性がなければ、プライベート
private:

	static bool CheckKeyCodeRange(int key_code);//キーコード範囲チェック
};