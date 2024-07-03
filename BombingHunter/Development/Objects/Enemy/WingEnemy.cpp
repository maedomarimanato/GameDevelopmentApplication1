#include"WingEnemy.h"
#include"DxLib.h"

//�R���X�g���N�^
WingEnemy::WingEnemy() : animation_count(0), direction(0.0f), flip_flag(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
WingEnemy::~WingEnemy()
{

}
//����������
void WingEnemy::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/WingEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/WingEnemy/2.png");


	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[2] == -1)
	{
		throw("�n�R�e�L�̉摜������܂���/n");
	}

	// �����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = Vector2D(32.0f);

	//�����摜�̐ݒ�
	image = animation[0];


	location = Vector2D(340.0f, 240.0f);

	//�����i�s�����̐ݒ�
	direction = Vector2D(1.0f, 0.0f);
}


//�X�V����
void WingEnemy ::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}
//�`�揈��
void WingEnemy::Draw() const
{
	//�摜���]�O���t
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//������Ƀn�R�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.6, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}


//�I��������
void WingEnemy::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��
void WingEnemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
}
//�ړ�����
void WingEnemy::Movement()
{

	//���E�ړ�
	if (((location.x + direction.x) < box_size.x) ||
		(780.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= -1.0f;
	}
	if (((location.y + direction.y) < box_size.y) ||
		(780.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= -1.0f;
	}

	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//�A�j���[�V��������
void WingEnemy::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;;

	//�R�O�t���[���ɓ��B������
	if (animation_count >= 30)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}

	}
}




