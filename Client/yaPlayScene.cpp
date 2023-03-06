#include "yaPlayScene.h"
#include "yaCharacter00.h"
#include "yaPlayBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObstacle.h"
#include "yaCollisionManager.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{

		mCharacter00 = new Character00();
		AddGameObject(mCharacter00, eLayerType::Player);
		Obstacle* obstacle = new Obstacle();
		AddGameObject(obstacle, eLayerType::Obstacle);


		PlayBackGround* bg = new PlayBackGround();
		////cuphead->SetPos(Vector2(0.0f, 0.0f));
		/*mSonic->SetName(L"Player");*/
		AddGameObject(bg, eLayerType::BG);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);

		Scene::Initialize();

	}

	void PlayScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

		Scene::Update();

	}


	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}


	void PlayScene::Release()
	{
		Scene::Release();
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//mSonic->SetPos(Vector2{ 0.0f, 0.0f }); (씬넘길때 원상복귀 시키는것(매스와 지금 문제가 이써안됨)

	}
}