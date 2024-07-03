#include"GameObject.h"
#include"DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	radian(0.0),
	image(NULL),
	sound(NULL),
	type(NULL)

{
}
//�f�X�g���N�^
GameObject::~GameObject()
{

}
//����������
void GameObject::Initialize()
{

	image = NULL;

	box_size = Vector2D(32.0f);

	location = box_size;
}
//�X�V����
void GameObject::Update()
{

	location = Vector2D(200.0f, 20.0f);

}
//�`�揈��
void GameObject::Draw() const
{


	//�����蔻��̉���
#ifdef D_PIVOT_CENTER
	Vector2D t1 = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#else
	Vector2D t1 = location;
	Vector2D br = location + box_size;

	DrawBoxAA(t1.x, t1.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif // D_PIVOT_CENTER
}
//�I������
void GameObject::Finalize()
{
}

//�����蔻��ʒm����
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}

//�ʒu���擾����
Vector2D GameObject::GetLocation() const
{
	return location;
}
//�ʒu���ݒ菈��
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}
//�����蔻��擾����
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}
