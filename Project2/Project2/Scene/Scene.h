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

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	//オブジェクト生成処理
	tmeplate<class T>
		T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObje
	}
};