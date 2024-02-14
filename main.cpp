#include <Novice.h>
#include"Quaternion.h"

const char kWindowTitle[] = "LE2B_ヨシダ_タケル";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3 vector, const char* label) {

	Novice::ScreenPrintf(x + kColumnWidth * 0, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth * 1, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%6.02f", vector.z);
	

	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}

void QuatrnionScreenPrintf(int x, int y, const Quaternion vector, const char* label) {

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

	Quatrnion* quatrmion = new Quatrnion;

	Quaternion rotation0 = quatrmion->MakeRotateAxisAngleQuaternion(Normalize(Vector3{ 0.71f, 0.71f, 0.0f }), 0.3f);

	Quaternion rotation1 = quatrmion->MakeRotateAxisAngleQuaternion(Normalize(Vector3{ 0.71f, 0.0f, 0.71f }), 3.141592f);

	Quaternion interpolate0 = quatrmion->Slerp(rotation0, rotation1, 0.0f);

	Quaternion interpolate1 = quatrmion->Slerp(rotation0, rotation1, 0.3f);

	Quaternion interpolate2 = quatrmion->Slerp(rotation0, rotation1, 0.5f);

	Quaternion interpolate3 = quatrmion->Slerp(rotation0, rotation1, 0.7f);

	Quaternion interpolate4 = quatrmion->Slerp(rotation0, rotation1, 1.0f);

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
		QuatrnionScreenPrintf(0, kRowHeight * 0, interpolate0, "interpolate0");
		QuatrnionScreenPrintf(0, kRowHeight * 1, interpolate1, "interpolate1");
		QuatrnionScreenPrintf(0, kRowHeight * 2, interpolate2, "interpolate2");
		QuatrnionScreenPrintf(0, kRowHeight * 3, interpolate3, "interpolate3");
		QuatrnionScreenPrintf(0, kRowHeight * 4, interpolate4, "interpolate4");
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
