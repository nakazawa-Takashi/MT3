﻿#include <Novice.h>
#include <math.h>
#include <assert.h>
#define _USE_MATH_DEFINES

const char kWindowTitle[] = "LE2C_21_ナカザワタカシ_MT3";

struct Vector3 {
	float x, y, z;
};

Vector3 v1{ 1.0f, 3.0f, -5.0f };
Vector3 v2{ 4.0f, -1.0f, 2.0f };
float k = { 4.0f };
static const int kRowHeight = 10;



Vector3 Add(const Vector3& v1, const Vector3& v2);

Vector3 Subtract(const Vector3& v1, const Vector3& v2);

Vector3 Multiply(float scalar, const Vector3& v);

float Dot(const Vector3& v1, const Vector3& v2);

float Length(const Vector3& v);

Vector3 Normalize(const Vector3& v);

Vector3 resultAdd = Add(v1, v2);
Vector3 resultSubtract = Subtract(v1, v2);
Vector3 resultMultiply = Multiply(k, v1);
float resultDot = Dot(v1, v2);
float resultLength = Length(v1);
Vector3 resultNormalize = Normalize(v2);

void VectorScreenPrintf(int x, int y, const Vector3& kvector, const char* label){
	VectorScreenPrintf(0, 0, resultAdd, " : Add");
	VectorScreenPrintf(0, kRowHeight, resultSubtract, " : Subtract");
	VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, " : Multiply");
	Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f : Dot", resultDot);
	Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f : Length", resultLength);
	VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, " : Normalize");
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
