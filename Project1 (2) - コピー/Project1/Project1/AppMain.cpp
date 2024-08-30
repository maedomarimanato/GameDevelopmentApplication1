#include"DxLib.h"
#include"Utility/inputControl.h"
#include "Objects/Player.h"

//���C���֐�
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hprevInstance,
	_In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}
	//�v���C���[�̃I�u�W�F�N�g�쐬
	Player* player = new Player();

	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���͐���@�\�X�V����
		InputControl::Update();

		//�v���C���[�X�V����
		player->Update();

		//�ǂɐG�ꂽ�甽�Α��Ɉړ����鏈��
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;//���̕ǂ���E�̕�
			}
			else
			{
				tmp.x = 0.0f;//�E�̕ǂ��獶�̕�
			}
			player->SetLocation(tmp);
		}

		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;//��̕ǂ��牺�̕�
			}
			else
			{
				tmp.y = 0.0f;//���W�X�V
			}
		}
		//���W�X�V
		player->SetLocation(tmp);

		//��ʃN���A
		ClearDrawScreen();

		//�`�揈��
		player->Draw();

		//��ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		//�I���{�^������
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	//�v���C���[�폜
	delete player;

	//DX���C�u�����̏I��������
	DxLib_End(); 

	//����I����ʒm
	return 0;
	}
