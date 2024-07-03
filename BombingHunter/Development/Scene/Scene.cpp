#include"Scene.h"
#include"../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"
#include "../Objects/Enemy/Harpy.h"
#include "../Objects/Enemy/WingEnemy.h"
#include "../Objects/Enemy/GoldEnemy.h"


//�R���X�g���N�^
Scene::Scene() : objects(), background_image(NULL)
{
	background_size = Vector2D(800.0f, 600.0f); // �w�i�摜�̃T�C�Y
}
//�f�X�g���N�^
Scene::~Scene()
{//BGM�̍폜
	DeleteSoundMem(GameMainBGM);
	StopSoundMem(GameMainBGM);
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	// �w�i�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/Images/BackGround.png");

	// �G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("�w�i�摜������܂���\n");
	
	}
	//�����ǂݍ���
	((GameMainBGM = LoadSoundMem("Resource/sounds/Evaluation/BGM_arrows.wav")) == -1);
	
	//�v���C���[����ʒ���������ɂ�`�悷��
	CreateObject<Player>(Vector2D(300.0f,300.0f));
}

//�X�V����
void Scene::Update()
{

	//BGM�̍Đ�
	if (CheckSoundMem(GameMainBGM) == 0)
	{
		PlaySoundMem(GameMainBGM, DX_PLAYTYPE_LOOP, TRUE);
	}
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	//�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//�����蔻��`�F�b�N����
			HitCheckObject(objects[i], objects[j]);
		}
	}

	//Z�L�[����������B�G�𐶐�����
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
	}
	//X�L�[����������B�G�𐶐�����
	if (InputControl::GetKeyUp(KEY_INPUT_X))
	{
		CreateObject<Harpy>(Vector2D(100.0f, 330.0f));
	}
	//C�L�[����������B�G�𐶐�����
	if (InputControl::GetKeyUp(KEY_INPUT_C))
	{
		CreateObject<WingEnemy>(Vector2D(100.0f, 260.0f));
	}
	//V�L�[����������B�G�𐶐�����
	if (InputControl::GetKeyUp(KEY_INPUT_V))
	{
		CreateObject<Gold>(Vector2D(100.0f, 180.0f));
	}
}



//�`�揈��
void Scene::Draw() const
{

	// �w�i�摜�̕`��
	DrawExtendGraph(0, 0, (int)background_size.x, (int)background_size.y, background_image, FALSE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}
//�I��������
void Scene::Finalize()
{
	if (background_image != NULL) DeleteGraph(background_image);
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//���I�z��̊J��
	objects.clear();
}
#ifdef D_PIVOT_CENTER

//�����蔻��`�F�b�N����(��`�̒��S�œ����蔻������)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�Q�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a-> GetLocation() - b -> GetLocation();

	//�Q�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a-> OnHitCollision(b);
		b-> OnHitCollision(a);

	}
}
#else

//�����蔻��`�F�b�N����(���㒸�_�̍��W���瓖���蔻��v�Z���s��)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�����_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//��`A�Ƌ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		 (a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVOT_CNETER