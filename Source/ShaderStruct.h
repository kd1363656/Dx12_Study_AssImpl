#pragma once
#include <d3dx12.h>
#include <DirectXMath.h>
#include "ComPtr.h"

struct Vertex
{
	DirectX::XMFLOAT3 Position; // 位置座標
	DirectX::XMFLOAT3 Normal; // 法線
	DirectX::XMFLOAT2 UV; // uv座標
	DirectX::XMFLOAT3 Tangent; // 接空間
	DirectX::XMFLOAT4 Color; // 頂点色
};