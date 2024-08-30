#pragma once

#include<map>
#include<string>
#include<vector>
//���\�[�X�Ǘ�
class ResourceManager
{
private:
	//���N���X�̃|�C���^�i�A�h���X�̐�ɃC���X�^���X�𐶐�����j
	static ResourceManager* instance;

	//�摜�i�[�R���e�i
	std::map<std::string, std::vector<int>>image_container;


public:
	//�R���X�g���N�^��private�ɂ��邱�Ƃ�
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	ResourceManager() = default;

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	ResourceManager(ResourceManager& v) = delete;
	ResourceManager& operator=(const ResourceManager& v) = delete;
	//�`�R�s�[�K�[�h
public:
	~ResourceManager() = default;

public:
	//�C���X�^���X���擾���鏈��
	static ResourceManager* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void DeleteInstance();

public:
	///<summary>
	///�摜�擾����
	///</summary>
	///<param name="file_path">�摜�̃t�@�C���p�X</param>
	///<returns>�����摜�̔z��f�[�^</returns>
	const std::vector<int>& GetImages(std::string file_path);

	///<summary>
	///�摜�擾����
	///</summary>
	///<param name="file_path">�摜�̃t�@�C���p�X</param>
	///<returns>����������</returns>
	///<param name="x_num">�������̕�������</param>
	///<param name="y_num">�������̕�����</param>
	///<param name="x_num">	�c�����̕�����</param>
	///<param name="x_size">�����摜�P��������̃s�N�Z����(��)</param>
	///<param name="x_size">�����摜�P��������̃s�N�Z����(�c)</param>
	///<returns>�����摜�̔z��f�[�^</returns>
	const std::vector<int>& GetImages(std::string filp_path, int all_num, int
		x_num, int y_num, int x_size, int y_size);

	//�ǂݍ��񂾉摜�̉��
	void DeleteImages();
};