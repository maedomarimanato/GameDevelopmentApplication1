#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

// �R���X�g���N�^
Player::Player() : animation_count(0), flip_flag(FALSE), background_image(NULL)
{
    animation[0] = NULL;
    animation[1] = NULL;
    background_size = Vector2D(800.0f, 600.0f); //�w�i�摜�̃T�C�Y
    player_size = Vector2D(64.0f, 64.0f); //�v���C���[�摜�̃T�C�Y
}

// �f�X�g���N�^
Player::~Player()
{
    Finalize();
}

// ����������
void Player::Initialize()
{
    // �����蔻��̒Z�`�̑傫�����w��
    box_size = Vector2D(32.0f);
    // �����ʒu��ݒ�
    location = Vector2D(200.0f, 240.0f);

    // �摜�̓ǂݍ���
    animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
    animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");

    // �G���[�`�F�b�N
    if (animation[0] == -1 || animation[1] == -1)
    {
        throw("���p�C���b�g�̉摜������܂���\n");
    }

    // �w�i�摜�̓ǂݍ���
    background_image = LoadGraph("Resource/Images/BackGround.png");

    // �G���[�`�F�b�N
    if (background_image == -1)
    {
        throw("�w�i�摜������܂���\n");
    }

    // �����̐ݒ�
    radian = 0.0f;

    // �����蔻��̑傫����ݒ�
    box_size = Vector2D(64.0f);

    // �����ʒu����ʏ㕔�ɐݒ�
    location = Vector2D(34.0f, player_size.y / 2.0f);
    // �����摜�̐ݒ�
    image = animation[0];
}

// �X�V����
void Player::Update()
{
    // �ړ�����
    Movement();
    // �A�j���[�V��������
    AnimationControl();
}

// �`�揈��
void Player::Draw() const
{
    // �w�i�摜�̕`��
    DrawExtendGraph(0, 0, background_size.x, background_size.y, background_image, FALSE);

    // �v���C���[�摜�̕`��
    DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

    // �f�o�b�O�p
#if _DEBUG
    // �����蔻��̉���
    Vector2D ul = location - (box_size / 2.0f);
    Vector2D br = location + (box_size / 2.0f);

    DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

// �I��������
void Player::Finalize()
{
    // �g�p�����摜���J������
    DeleteGraph(animation[0]);
    DeleteGraph(animation[1]);
    DeleteGraph(background_image);
}

// �����蔻��
void Player::OnHitCollision(GameObject* hit_object)
{
    // �����������̏���
}

// �ړ�����
void Player::Movement()
{
    // �ړ��̑���
    Vector2D velocity = 0.0f;

    // ���E�ړ�
    if (InputControl::GetKey(KEY_INPUT_LEFT))
    {
        velocity.x -= 1.0f;
        flip_flag = TRUE;
    }
    else if (InputControl::GetKey(KEY_INPUT_RIGHT))
    {
        velocity.x += 1.0f;
        flip_flag = FALSE;
    }

    // ���݂̈ʒu���W�ɑ��������Z����
    location += velocity;

    // �ʒu�̐���
    float half_width = player_size.x / 1.3f;
    float half_height = player_size.y / 0.3f;

    if (location.x < half_width)
    {
        location.x = half_width;
    }
    else if (location.x > SCREEN_WIDTH - half_width)
    {
        location.x = SCREEN_WIDTH - half_width;
    }

    if (location.y < half_height)
    {
        location.y = half_height;
    }
    else if (location.y > SCREEN_HEIGHT - half_height)
    {
        location.y = SCREEN_HEIGHT - half_height;
    }
}

// �A�j���[�V��������
void Player::AnimationControl()
{
    // �t���[���J�E���g�����Z����
    animation_count++;

    // 60�t���[���ڂɓ��B������
    if (animation_count >= 60)
    {
        // �J�E���g�̃��Z�b�g
        animation_count = 0;

        // �摜�̐؂�ւ�
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
