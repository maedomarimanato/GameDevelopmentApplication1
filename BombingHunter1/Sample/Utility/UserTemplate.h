#pragma once
#pragma once
#pragma once

//絶対値に変換
//引数の数字を絶対値に変換する関数
//引数：T　value 変換する値
//戻り値　:　T　変換後の値
template <typename T>
T Abs(T value)
{
	T result;
	if (value > 0)
	{
		//value正の値
		result = value;
	}
	else
	{
		//value負の値
		result = -value;
	}

	return result;
}
//最大値を返す関数
//引数で指定された２つの値の最大値を返す引数
//ta 計算用データ
//tb
//戻り値
//T 最大値

template <typename T>
T Max(T a, T b)
{
	T result;
	//値が大きいほうをresultに設定
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
//最小値を返す関数
//引数で指定された２つの値の最小値を返す引数
//ta 計算用データ
//tb
//戻り値
//T最小値

template <typename T>
T Min(T a, T b)
{
	T result;
	//値の小さいほうをresultに設定
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

