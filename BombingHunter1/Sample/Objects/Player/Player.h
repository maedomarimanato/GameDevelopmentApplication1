#pragma once

#include"../GameObject.h"

class Player : public GameObject
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
	int background_image;
	// �摜�T�C�Y�̃����o�ϐ�
	Vector2D background_size;
	Vector2D player_size;

	// ��ʂ̕��ƍ���
	static constexpr int SCREEN_WIDTH = 800;
	static constexpr int SCREEN_HEIGHT = 600;


};