#pragma once

#include"../Utility/Vector2D.h"
//�v���C���[�p�N���X
class Player
{
private:
	Vector2D location;//�ʒu���W
	Vector2D direction;//����
	float radius;//���a

public:
	Player();
	Player(float x, float y);
	Player(Vector2D location);
	~Player();

	void Update();//�X�V����
	void Draw() const;//�`�揈��

	void SetLocation(float x, float y);//Location�Z�b�^�[
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;//Location�Q�b�^�[
	float GetRadius();//radius�̃Q�b�^�[

private:
	void Movement();//�ړ�����
};