#pragma once

#include "../GameObject.h"

class Player : public GameObject // GameObject���p��
{
private:
    int animation[2]; //�A�j���[�V�����摜
    int animation_count;//�A�j���[�V��������
    int flip_flag; //���]�O���t


public:
    Player();
    ~Player();

    //����������
    void Initialize() override;
    //�X�V����
    void Update() override;
    //�`�揈��
    void Draw() const override;
    //����������
    void Finalize() override;

   //�����蔻��ʒm����
    void OnHitCollision(GameObject* hit_object) override;

private:
  //�ړ�����
    void Movement();
    //�A�j���[�V��������
    void AnimationControl();

};
