#pragma once

#define D_KEYCODE_MAX (256)
//���͐���N���X(�����o�͐ÓI�ŏ��L����j
class InputControl
{
//��{�I�Ƀ����o�ϐ��̓v���C�x�[�g
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];
//�֐��̓p�u���b�N
public:
	static void Update();
	static InputControl* GetInstance();
	static void DeleteInstance();
	//�L�[���͎擾�n
	static bool GetKey(int key_code);
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);
//�O�����J�̕K�v�����Ȃ���΁A�v���C�x�[�g
private:

	static bool CheckKeyCodeRange(int key_code);//�L�[�R�[�h�͈̓`�F�b�N
};