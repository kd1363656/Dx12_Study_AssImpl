#pragma once
#include "ComPtr.h"

struct ID3D12RootSignature;

class RootSignature
{
public:
	RootSignature(); // コンストラクタでルートシグネチャを生成
	~RootSignature();

	bool IsValid();  // ルートシグネチャの生成に成功したかどうかを返す

	ID3D12RootSignature* Get(); // ルートシグネチゃを返す

private:

	bool m_IsValid = false; // ルートシグネチャの生成に成功したかどうか
	ComPtr<ID3D12RootSignature> m_pRootSignature = nullptr; // ルートシグネチャ
};