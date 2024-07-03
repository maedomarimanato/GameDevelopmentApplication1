#pragma once

#include"DxLib.h"
#include "../../Utility/Vector2D.h"

class Bomb
{
public:
    Bomb(const Vector2D& position, const Vector2D& velocity);
  

    //�X�V����
    void Update();
    //�`�揈��
    void Draw() const;
    bool IsOffScreen() const;

private:
    Vector2D position;
    Vector2D velocity;
    int image;//�摜
    int soundHandle; // �ǉ��F�����̃n���h��


    // ��ʂ̕��ƍ���
    static constexpr int SCREEN_WIDTH = 800;
    static constexpr int SCREEN_HEIGHT = 600;
};


