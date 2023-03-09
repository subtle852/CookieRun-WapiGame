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
		//mCh00 = object::Instantiate<Character00>(eLayerType::Player);
		//mPet00 = object::Instantiate<Pet00>(Vector2(300.0f, 400.0f), eLayerType::Pet);

		//Scene::Initialize();

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
		//mSonic->SetPos(Vector2{ 0.0f, 0.0f }); (씬넘길때 원상복귀 시키는것(매스와 지금 문제가 이써안됨)

	}
}