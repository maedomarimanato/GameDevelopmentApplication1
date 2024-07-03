#pragma once


#include "Bomb.h"
#include <vector>
#include "../GameObject.h"

class Player : public GameObject // GameObject���p��
{
public:
    Player();
    ~Player();

    //����������
    void Initialize() override;
    //�X�V����
    void Update() override;
    //�`�揈��
    void Draw() const override;
    //�I��������
    void Finalize() override;

    //�����蔻��ʒm����
    void OnHitCollision(GameObject* hit_object) override;

private:
    //�ړ�����
    void Movement();
    //�A�j���[�V��������
    void AnimationControl();
    void FireBomb(); // ���e���˂̂��߂̐V�����֐�

    Vector2D location;
    //�摜�傫��
    Vector2D player_size;
    Vector2D background_size;
    Vector2D box_size;

    float radian;//���a
    int animation_count;//�A�j���[�V��������
    int flip_flag;
    int background_image;//�w�i�摜
    int image;//�摜
    int animation[2];//�A�j���[�V����

    std::vector<Bomb> bombs; // ���e�̃��X�g


    // ��ʂ̕��ƍ���
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 500;
    static constexpr int SCREEN_UP = 600;
    static constexpr int SCREEN_DOWN = 450;

};
