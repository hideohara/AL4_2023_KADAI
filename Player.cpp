#include "Player.h"
#include <cassert>

void Player::Initialize(Model* model) {

	// NULLポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Player::Update() {

	//worldTransform_.translation_.x += 0.1f;

	// 行列を更新
	worldTransform_.UpdateMatrix();
}

void Player::Draw(ViewProjection& viewProjection) {
	// 3Dモデル描画
	model_->Draw(worldTransform_, viewProjection);
}
