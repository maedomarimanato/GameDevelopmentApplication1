#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"


// �R���X�g���N�^
Player::Player() : animation_count(0), flip_flag(FALSE)
{
    animation[0] = NULL;
    animation[1] = NULL;
    player_size = Vector2D(34.0f, 34.0f);      // �v���C���[�摜�̃T�C�Y
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
    box_size = Vector2D(32.0f, 32.0f);

    // �����ʒu��ݒ�
    location = Vector2D(300.0f, 130.0f);

    // �摜�̓ǂݍ���
    animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
    animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");


    // �G���[�`�F�b�N
    if (animation[0] == -1 || animation[1] == -1)
    {
        printf("���p�C���b�g�̉摜������܂���\n");
        return;
    }

 

    // �����̐ݒ�
    radian = 0.0f;

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
    // ���e���ˏ���
    FireBomb();

    // ���e�̍X�V
    for (auto it = bombs.begin(); it != bombs.end();)
    {
        it->Update();
        if (it->IsOffScreen())
        {
            it = bombs.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// �`�揈��
void Player::Draw() const
{
    

    // �v���C���[�摜�̕`��
    DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

    // ���e�̕`��
    for (const auto& bomb : bombs)
    {
        bomb.Draw();
    }

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
    if (animation[0] != NULL) DeleteGraph(animation[0]);
    if (animation[1] != NULL) DeleteGraph(animation[1]);
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
    Vector2D velocity(0.0f, 0.0f);

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
    // ���E�ړ�
    if (InputControl::GetKey(KEY_INPUT_UP))
    {
        velocity.y -= 1.0f;
        flip_flag = TRUE;
    }
    else if (InputControl::GetKey(KEY_INPUT_DOWN))
    {
        velocity.y += 1.0f;
        flip_flag = FALSE;
    }
    

    // ���݂̈ʒu���W�ɑ��������Z����
    location += velocity;

    // �ʒu�̐���
    float half_width = player_size.x / 2.0f;
    float half_height = player_size.y / 2.0f;
    float half_up = player_size.y / 2.0f;
    float half_down = player_size.y / 2.0f;

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
    if (location.y < half_up)
    {
        location.y = half_up;
    }

    else if (location.y > SCREEN_UP - half_up)
    {
        location.y = SCREEN_UP - half_up;
    }

    if (location.y < half_down)
    {
        location.y = half_down;
    }
    else if (location.y > SCREEN_DOWN - half_down)
    {
        location.y = SCREEN_DOWN - half_down;
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
// ���e���ˏ���
void Player::FireBomb()
{
    if (InputControl::GetKey(KEY_INPUT_SPACE))
    {
        Vector2D bomb_velocity(0.0f, 3.0f); // ���e�̑��x���������ɐݒ�
        bombs.emplace_back(location, bomb_velocity);

    }
}
