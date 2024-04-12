#include"Player.h"
#include"../../Utility/InputControl.h"
#include"DxLib.h"

//�R���X�g���N�^
Player::Player() : animation_conut(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Player::~Player()
{

}
//����������
void Player::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/Tri-pilot/1.png");
	animation[1] = LoadGraph("Resource/images/Tri-pilot/2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�g���p�C���b�g�̉摜������܂���\n");
	}

	// �����̐ݒ�
	radian = 0.0;

	//�傫���̐ݒ�
	scale = 64.0;

	//�����摜�̐ݒ�
	image = animation[0];
}

//�X�V����
void Player::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

	}
}