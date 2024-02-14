#include <Novice.h>
#include"Function.h"

const char kWindowTitle[] = "LE2B_ヨシダ_タケル";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Quaternion vector, const char* label) {

	Novice::ScreenPrintf(x + kColumnWidth * 0, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth * 1, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%6.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%6.02f", vector.w);

	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}


void MatrixScreenPrintf(int x, int y, Matrix4x4 matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]);
		}
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Quaternion q1 ={2.0f,3.0f,4.0f,1.0f};
	Quaternion q2 = { 1.0f,3.0f,5.0f,2.0f };
	Quaternion identity = IdentiyQuaternion();

	Quaternion inv = Inverse(q1);

	Quaternion nomrmal = Normalize(q1);


	Quaternion mul1 = Multiply(q1, q2);
	Quaternion mul2 = Multiply(q2, q1);

	Quaternion conj = Conjugate(q1);


	
	float norm = Norm(q1);

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
		VectorScreenPrintf(0, 0, mul1,"Multiply(q1, q2)");

		VectorScreenPrintf(0, 20, mul2, "Multiply(q2, q1)");

		VectorScreenPrintf(0, 40, identity, "IdentiyQuaternion()");

		VectorScreenPrintf(0, 60, conj ," Conjugate(q1)");

		Novice::ScreenPrintf(0, 80, "%fNorm", norm);

		VectorScreenPrintf(0, 100, nomrmal, " Normalize(q1);");


		VectorScreenPrintf(0, 120, inv ,"Inverse(q1)");
		
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
