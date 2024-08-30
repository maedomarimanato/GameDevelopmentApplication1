#pragma once
//�Q�����x�N�g���p�N���X
class Vector2D
{
public:
	float x;//x���W
	float y;//�����W

public:
	//�R���X�g���N�^
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);
	~Vector2D();

public:
	//����@���Z�q�I�[�o�[���[�h
	Vector2D& operator = (const Vector2D& location);

	const Vector2D operator+(const Vector2D& location) const;
	Vector2D& operator+=(const Vector2D& location);

	const Vector2D operator-(const Vector2D& location) const;
	Vector2D& operator-=(const Vector2D& location);

	const Vector2D operator*(const float& location) const;
	const Vector2D operator*(const Vector2D& location) const;
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);

	const Vector2D operator/(const float& scalar) const;
	const Vector2D operator/(const Vector2D& location) const;
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);
	//���Z�q�I�[�o�[���[�h�����܂�

	/*
	*�����^de-tanihennkann 
	����
	���Ƃ������𐮐��^�ɕϊ����A�Ή���������ɑ������
	*����
	*�@������*���@���������󂯎��ϐ�
�@�@*������*���@���������󂯎��ϐ�
  */ 
	void ToInt(int* x, int* y)const;
};

