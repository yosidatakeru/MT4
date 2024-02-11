#include <Novice.h>
#include"Function.h"

const char kWindowTitle[] = "LE2B_ヨシダ_タケル";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3 vector, const char* label) {

	Novice::ScreenPrintf(x + kColumnWidth * 0, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth * 1, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%6.02f", vector.z);

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

	Vector3 from0 = Normalize(Vector3{1.0f, 0.7f, 0.5f});
	Vector3 to0 = Normalize(Vector3{ -1.0f, -0.7f, -0.5f });

	Vector3 from1 = Normalize(Vector3{ -0.6f, 0.9f, 0.2f });
	Vector3 to1 = Normalize(Vector3{ 0.4f, 0.7f, -0.5f });
	Matrix4x4 rotateMatrix0 = DirectionToDirection(Normalize(Vector3{1.0f, 0.0f, 0.0f}), Normalize(Vector3{-1.0f, 0.0f,0.0f}));
	Matrix4x4 rotateMatrix1 = DirectionToDirection(from0,to0);
	Matrix4x4 rotateMatrix2 = DirectionToDirection(from1, to1);
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
		MatrixScreenPrintf(0, 0, rotateMatrix0);
		MatrixScreenPrintf(0, kRowHeight *5, rotateMatrix1);
		MatrixScreenPrintf(0, kRowHeight * 10, rotateMatrix2);
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
