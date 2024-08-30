#pragma once

#define D_KEYCODE_MAX (256)//キーコードの総数

//入力管理機能
class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];//現在の入力情報
	static char old_key[D_KEYCODE_MAX];//前フレームの入力情報

public:
	//キー情報更新
	static void Update();//キー情報更新

	//キー情報取得
	static bool GetKey(int key_code);
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);

private:
	//キーコードの有効範囲内チェック
	static bool CheckKeyCodeRange(int key_code);
};