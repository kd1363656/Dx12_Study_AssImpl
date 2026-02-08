#include "Scene.h"
#include "Engine.h"
#include "App.h"
#include <d3d12.h>
#include "ShaderStruct.h"
#include "VertexBuffer.h"

Scene* g_Scene;
VertexBuffer* vertexBuffer;

Scene::~Scene()
{
	if (vertexBuffer)
	{
		delete vertexBuffer;
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

	printf("\nシーンの初期化に成功\n");
	return true;
}

void Scene::Update()
{

}

void Scene::Draw()
{
}