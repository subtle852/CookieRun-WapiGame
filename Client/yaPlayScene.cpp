#include "yaPlayScene.h"
#include "yaCharacter01.h"
#include "yaPet01.h"
#include "yaPlayBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaJellyCoin.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"

#include "yaJumpButton.h"
#include "yaSlideButton.h"
#include "yaPauseButton.h"
#include "yaGuageCircle.h"
#include "yaGuageBar.h"
#include "yaGround.h"

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
		//mCh00 =
		//object::Instantiate<Character01>(eLayerType::Player);
		//Camera::SetTarget(mCh00);

		Scene::Initialize();

		// 여기다

		//object::Instantiate<PlayBackGround>(eLayerType::BG);

		object::Instantiate<Ground>(Vector2(-100.0f, 800.0f), eLayerType::Ground);

		object::Instantiate<Character01>(Vector2(200.0f, 800.0f), eLayerType::Player);
		object::Instantiate<Pet01>(Vector2(300.0f, 500.0f), eLayerType::Pet);
		object::Instantiate<Obstacle>(Vector2(1100.0f, 800.0f), eLayerType::Obstacle);
		object::Instantiate<Obstacle01>(Vector2(1700.0f, 250.0f), eLayerType::Obstacle);
		object::Instantiate<Obstacle>(Vector2(2300.0f, 800.0f), eLayerType::Obstacle);
		object::Instantiate<Obstacle01>(Vector2(2900.0f, 250.0f), eLayerType::Obstacle);
		object::Instantiate<JellyCoin>(Vector2(1400.0f, 800.0f), eLayerType::Obstacle);
		object::Instantiate<JellyCoin>(Vector2(2300.0f, 450.0f), eLayerType::Obstacle);

		object::Instantiate<GuageCircle>(Vector2(-10.0f, 50.0f), eLayerType::UI);
		object::Instantiate<GuageBar>(Vector2(59.0f, 62.0f), eLayerType::UIfirst);

		object::Instantiate<JumpButton>(Vector2(200.0f, 700.0f), eLayerType::UI);
		object::Instantiate<SlideButton>(Vector2(1200.0f, 700.0f), eLayerType::UI);
		object::Instantiate<PauseButton>(Vector2(1400.0f, 50.0f), eLayerType::UI);
		//object::Instantiate<GuageCircle>(Vector2(216.0f, 50.0f), eLayerType::UI);
		//object::Instantiate<GuageBar>(Vector2(285.0f, 62.0f), eLayerType::UIfirst);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
	}

	void PlayScene::Update()
	{
		//Transform* tr = mCh01->GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();

		//Transform* trr = mPet01->GetComponent<Transform>();
		//trr->SetPos(Vector2(pos.x + 100.0f, pos.y -100.0f));

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			//SceneManager::LoadScene(eSceneType::ResultS);
		}

		Scene::Update();

	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);
	}

	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
	}

	void PlayScene::OnExit()
	{
		//ya::object::Destory(mBG);
		//ya::object::Destory(mCh01);
		//ya::object::Destory(mPet01);
		//ya::object::Destory(mOb01);
		//ya::object::Destory(mOb02);
		//ya::object::Destory(mOb03);
		//ya::object::Destory(mOb04);
		//ya::object::Destory(mJcoin01);
		//ya::object::Destory(mJcoin02);
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f }); 씬넘길때 원상복귀 시키는것
	}
}