#include "Player.h"
#include <cassert>


void Player::Initialize(Model* model) {

	// NULLポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();

	input_ = Input::GetInstance();
}

void Player::Update() {

	const float speed = 0.3f;
	Vector3 move = {0.0f, 0.0f, 0.0f};
	if (input_->PushKey(DIK_RIGHT)) {
		move.x = 1.0f;
	}
	if (input_->PushKey(DIK_LEFT)) {
		move.x = -1.0f;
	}
	if (input_->PushKey(DIK_UP)) {
		move.z = 1.0f;
	}
	if (input_->PushKey(DIK_DOWN)) {
		move.z = -1.0f;
	}

	move = Normalize(move) * speed;

	worldTransform_.translation_ += move;


	// 行列を更新
	worldTransform_.UpdateMatrix();
}

void Player::Draw(ViewProjection& viewProjection) {
	// 3Dモデル描画
	model_->Draw(worldTransform_, viewProjection);
}
