#pragma once
#pragma once
#pragma once

//��Βl�ɕϊ�
//�����̐������Βl�ɕϊ�����֐�
//�����FT�@value �ϊ�����l
//�߂�l�@:�@T�@�ϊ���̒l
template <typename T>
T Abs(T value)
{
	T result;
	if (value > 0)
	{
		//value���̒l
		result = value;
	}
	else
	{
		//value���̒l
		result = -value;
	}

	return result;
}
//�ő�l��Ԃ��֐�
//�����Ŏw�肳�ꂽ�Q�̒l�̍ő�l��Ԃ�����
//ta �v�Z�p�f�[�^
//tb
//�߂�l
//T �ő�l

template <typename T>
T Max(T a, T b)
{
	T result;
	//�l���傫���ق���result�ɐݒ�
	if (a < b)
	{
		result = b;
	}
	else
	{
		result = a;
	}
	return result;
}
//�ŏ��l��Ԃ��֐�
//�����Ŏw�肳�ꂽ�Q�̒l�̍ŏ��l��Ԃ�����
//ta �v�Z�p�f�[�^
//tb
//�߂�l
//T�ŏ��l

template <typename T>
T Min(T a, T b)
{
	T result;
	//�l�̏������ق���result�ɐݒ�
	if (a > b)
	{
		result = b;
	}
	else
	{
		result = a;
	}

	return result;
}

