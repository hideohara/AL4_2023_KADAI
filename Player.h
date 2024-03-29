﻿#pragma once

#include "Model.h"
#include "WorldTransform.h"
#include "Input.h"
#include "MathUtilityForText.h"

class Player {

public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	void Initialize(Model* model);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

    /// <summary>
	/// 描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション（参照渡し）</param>
	void Draw(ViewProjection& viewProjection);


	const WorldTransform& GetWorldTransform() { return worldTransform_; }

	
  private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	//uint32_t textureHandle_ = 0u;

	Input* input_ = nullptr;
};
