#include "yaPlayScene.h"
#include "yaCharacter00.h"

ya::PlayScene::PlayScene()
{
}

ya::PlayScene::~PlayScene()
{
}

void ya::PlayScene::Initialize()
{
	Character00* character00 = new Character00();
	AddGameObject(character00, eLayerType::Player);

	Scene::Initialize();
}

void ya::PlayScene::Update()
{
	Scene::Update();
}

void ya::PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ya::PlayScene::Release()
{
	Scene::Release();
}
