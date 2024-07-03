#include "Bomb.h"
#include "DxLib.h"

// �R���X�g���N�^
Bomb::Bomb(const Vector2D& position, const Vector2D& velocity)
    : position(position), velocity(velocity)
{
    image = LoadGraph("Resource/Images/Bomb.png");
     soundHandle = LoadSoundMem("Resource/Sounds/pan.wav"); // �����t�@�C����ǂݍ���
    PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK); // �������Đ�����
}

// �X�V����
void Bomb::Update()
{
    position += velocity;
}

// �`�揈��
void Bomb::Draw() const
{
    DrawGraph((int)position.x, (int)position.y, image, TRUE);
}

// ��ʊO����
bool Bomb::IsOffScreen() const
{
    return position.x < 0 || position.x > SCREEN_WIDTH || position.y < 0 || position.y > SCREEN_HEIGHT;
}

