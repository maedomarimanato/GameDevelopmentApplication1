#pragma once

#include<vector>
#include<string>
#include"../Objects/GameObject.h"

class Scene
{
private:
	std::vector<GameObject*>objects;

public:
	Scene();
	~Scene();


	 //����������
	void Initialize();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw() const;
	//�I��������
	void Finalize();

	//�w�i�摜
	int background_image;
	//�w�i����
	int GameMainBGM;
	//�w�i�摜�T�C�Y
	Vector2D background_size;

	
	
private:
	//�����蔻��`�F�b�N����
	void HitCheckObject(GameObject* a, GameObject* b);


	//�I�u�W�F�N�g��������
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//�w�肵���N���X�𐶐�����
		T* new_instance = new T();
		//GameObject�N���X���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//�G���[�`�F�b�N
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");
		}
	

		//����������
		new_object->Initialize();
		//�ʒu���̐ݒ�
		new_object->SetLocation(location);

		//�I�u�W�F�N�g���X�g�ɒǉ�
		objects.push_back(new_object);

		//�C���X�^���X�̃|�C���^��ԋp
		return new_instance;

	}
};