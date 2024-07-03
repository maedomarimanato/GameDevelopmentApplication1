#include"GameObject.h"
#include"DxLib.h"

//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	radian(0.0),
	image(NULL),
	sound(NULL),
	type(NULL)

{
}
//デストラクタ
GameObject::~GameObject()
{

}
//初期化処理
void GameObject::Initialize()
{

	image = NULL;

	box_size = Vector2D(32.0f);

	location = box_size;
}
//更新処理
void GameObject::Update()
{

	location = Vector2D(200.0f, 20.0f);

}
//描画処理
void GameObject::Draw() const
{


	//当たり判定の可視化
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
//終了処理
void GameObject::Finalize()
{
}

//当たり判定通知処理
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
}

//位置情報取得処理
Vector2D GameObject::GetLocation() const
{
	return location;
}
//位置情報設定処理
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}
//当たり判定取得処理
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}
