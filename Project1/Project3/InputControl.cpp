#include"InputControl.h"
#include"DxLib.h"

char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};

void InputControl::Update()
{
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	GetHitStateAll(now_key);
}

bool InputControl::GetKey(int key_code)
{
	return ChecKKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}
bool InputControl::GetKeyDown(int key_code)
{
	return ChecKKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}
bool InputControl::GetKeyUp(int key_code)
{
	return ChecKKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) % %
		(old_key[key_code] == TRUE));
}

bool InputControl::ChecKKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}


