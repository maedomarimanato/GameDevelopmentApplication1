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


	 //初期化処理
	void Initialize();
	//更新処理
	void Update();
	//描画処理
	void Draw() const;
	//終了時処理
	void Finalize();

	//背景画像
	int background_image;
	//背景音声
	int GameMainBGM;
	//背景画像サイズ
	Vector2D background_size;

	
	
private:
	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);


	//オブジェクト生成処理
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("ゲームオブジェクトが生成できませんでした");
		}
	

		//初期化処理
		new_object->Initialize();
		//位置情報の設定
		new_object->SetLocation(location);

		//オブジェクトリストに追加
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;

	}
};