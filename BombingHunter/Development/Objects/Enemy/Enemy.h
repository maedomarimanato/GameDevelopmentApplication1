#pragma once



#include"../GameObject.h"

class Enemy : public GameObject
{
private:
	int animation[3]; //�A�j���[�V�����摜
	int animation_count;//�A�j���[�V��������
	int flip_flag; //���]�O���t
	int radian;//���a
	Vector2D direction;//�i�s����


public:
	Enemy();
	~Enemy();

	void Initialize(const Vector2D& player_position);

	virtual void Initialize() override; //����������
	virtual void Update() override; //�X�V����
	virtual void Draw() const override;//�`�揈��
	virtual void Finalize() override; //�I��������



	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* Hit_object) override;

private:

	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimationControl();
};