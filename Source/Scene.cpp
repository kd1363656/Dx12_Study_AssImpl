#include "Scene.h"
#include "Engine.h"
#include "App.h"
#include <d3d12.h>
#include "ShaderStruct.h"
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "RootSignature.h"

Scene* g_Scene;
VertexBuffer* vertexBuffer;
ConstantBuffer* constantBuffer[Engine::FRAME_BUFFER_COUNT];
RootSignature* rootSignature;

Scene::~Scene()
{
	if (vertexBuffer)
	{
		delete vertexBuffer;
	}

	if (rootSignature)
	{
		delete rootSignature;
	}

	for (size_t i = 0; i < Engine::FRAME_BUFFER_COUNT; i++)
	{
		if (!constantBuffer[i]) { continue; }
		delete constantBuffer[i];
	}
}

bool Scene::Init()
{
	Vertex vertices[3] = {};
	vertices[0].Position = DirectX::XMFLOAT3(-1.0F, -1.0F, 0.0F);
	vertices[0].Color = DirectX::XMFLOAT4(0.0F, 0.0F, 1.0F, 1.0F);

	vertices[1].Position = DirectX::XMFLOAT3(1.0F, -1.0F, 0.0F);
	vertices[1].Color = DirectX::XMFLOAT4(0.0F, 1.0F, 0.0F, 1.0F);

	vertices[2].Position = DirectX::XMFLOAT3(0.0F, 1.0F, 0.0F);
	vertices[2].Color = DirectX::XMFLOAT4(1.0F, 0.0F, 0.0F, 1.0F);

	auto vertexSize = sizeof(Vertex) * std::size(vertices);
	auto vertexStride = sizeof(Vertex);
	vertexBuffer = new VertexBuffer(vertexSize, vertexStride, vertices);

	if (!vertexBuffer->IsValid())
	{
		assert(false && "頂点バッファーの作成に失敗");
		return false;
	}


	auto eyePos = DirectX::XMVectorSet(0.0F, 0.0F, 5.0F, 0.0F); // 視点の位置
	auto targetPos = DirectX::XMVectorZero(); // 視点を向ける座標
	auto upward = DirectX::XMVectorSet(0.0F, 1.0F, 0.0F, 0.0F); // 上方向を表すベクトル
	auto fov = DirectX::XMConvertToRadians(37.5F); // 視野角
	auto aspect = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(WINDOW_HEIGHT); // アスペクト比

	for(size_t i = 0; i < Engine::FRAME_BUFFER_COUNT; i++)
	{
		constantBuffer[i] = new ConstantBuffer(sizeof(Transform));
		if (!constantBuffer[i]->IsValid())
		{
			assert(false && "変換行列用定数バッファの生清に失敗\n");
			return false;
		}

		// 変換行列の登録
		auto ptr = constantBuffer[i]->GetPtr<Transform>();
		ptr->World = DirectX::XMMatrixIdentity();
		ptr->View = DirectX::XMMatrixLookAtRH(eyePos, targetPos, upward);
		ptr->Proj = DirectX::XMMatrixPerspectiveFovRH(fov, aspect, 0.3F, 1000.0F);
	}

	rootSignature = new RootSignature();
	if (!rootSignature->IsValid())
	{
		assert(false && "ルートシグネチャ生成失敗");
		return false;
	}

	printf("\nシーンの初期化に成功\n");
	return true;
}

void Scene::Update()
{

}

void Scene::Draw()
{
}