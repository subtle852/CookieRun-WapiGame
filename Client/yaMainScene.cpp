#include "yaMainScene.h"
#include "yaCharacter00.h"
#include "yaMainBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"



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

		mCharacter00 = new Character00();
		MainBackGround* bg = new MainBackGround();
		////cuphead->SetPos(Vector2(0.0f, 0.0f));
		/*mSonic->SetName(L"Player");*/
		AddGameObject(mCharacter00, eLayerType::Player);
		AddGameObject(bg, eLayerType::BG);

		Scene::Initialize();

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
	}
	void MainScene::OnExit()
	{
		//mSonic->SetPos(Vector2{ 0.0f, 0.0f }); (씬넘길때 원상복귀 시키는것(매스와 지금 문제가 이써안됨)

	}
}