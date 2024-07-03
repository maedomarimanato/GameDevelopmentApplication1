#pragma once

#include"../GameObject.h"

class Gold : public GameObject
{
private:
	int flip_flag;//���]�O���t
	int animation[5]; //�A�j���[�V�����摜
	int animation_count;//�A�j���[�V��������
	Vector2D direction;//�i�s����


public:
	Gold();
	~Gold();

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