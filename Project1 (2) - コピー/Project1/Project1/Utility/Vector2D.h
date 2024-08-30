#pragma once
//２次元ベクトル用クラス
class Vector2D
{
public:
	float x;//x座標
	float y;//ｙ座標

public:
	//コンストラクタ
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);
	~Vector2D();

public:
	//代入　演算子オーバーロード
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
	//演算子オーバーロードここまで

	/*
	*整数型de-tanihennkann 
	説明
	ｘとｙ成分を整数型に変換し、対応する引数に代入する
	*引数
	*　ｉｎｔ*ｙ　ｘ成分を受け取る変数
　　*ｉｎｔ*ｙ　ｙ成分を受け取る変数
  */ 
	void ToInt(int* x, int* y)const;
};

