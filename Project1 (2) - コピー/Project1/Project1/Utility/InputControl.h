#pragma once

#define D_KEYCODE_MAX (256)//�L�[�R�[�h�̑���

//���͊Ǘ��@�\
class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];//���݂̓��͏��
	static char old_key[D_KEYCODE_MAX];//�O�t���[���̓��͏��

public:
	//�L�[���X�V
	static void Update();//�L�[���X�V

	//�L�[���擾
	static bool GetKey(int key_code);
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);

private:
	//�L�[�R�[�h�̗L���͈͓��`�F�b�N
	static bool CheckKeyCodeRange(int key_code);
};