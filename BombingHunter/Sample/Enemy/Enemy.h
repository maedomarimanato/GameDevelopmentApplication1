#pragma once
#include"../GameObjects.h"

class Player : public GameObjects
{
private:
	int animation[2]; //�A�j���[�V�����摜
	int animation_count;//�A�j���[�V��������
	int flip_flag; //���]�O���t


public:
	Player();
	~Player();

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