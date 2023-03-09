#include "yaMainScene.h"
#include "yaCharacter00.h"
#include "yaPet00.h"
#include "yaMainBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"


namespace ya
{
	MainScene::MainScene()
	{

	}

	MainScene::~MainScene()
	{

	}

	void MainScene::Initialize()
	{
		Scene::Initialize();

		mCh00 = object::Instantiate<Character00>(Vector2(800.0f, 620.0f), eLayerType::Player);
		mPet00 = object::Instantiate<Pet00>(Vector2(900.0f, 520.0f), eLayerType::Pet);
		object::Instantiate<MainBackGround>(eLayerType::BG);
	}

	void MainScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::SelectChar);
		}

		Scene::Update();

	}

	void MainScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void MainScene::Release()
	{
		Scene::Release();
	}

	void MainScene::OnEnter()
	{
		object::Instantiate<MainBackGround>(eLayerType::BG);
	}

	void MainScene::OnExit()
	{

	}
}