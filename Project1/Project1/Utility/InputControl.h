#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

public:
	static void Update();

	static bool Getkey(int key_code);
	static bool GetkeyDown(int key_code);
	static bool GetkeyUp(int key_code);

private:
	static bool ChecKKeyCoderange(int key_code);
};