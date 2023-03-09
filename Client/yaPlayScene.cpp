#include "yaPlayScene.h"
#include "yaCharacter00.h"
#include "yaPet00.h"
#include "yaPlayBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"

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
		//object::Instantiate<Character00>(eLayerType::Player);
		//Camera::SetTarget(mCh00);

		Scene::Initialize();

		//mBG = object::Instantiate<PlayBackGround>(eLayerType::BG);
		//mCh00 = object::Instantiate<Character00>(Vector2(200.0f, 500.0f), eLayerType::Player);
		//mPet00 = object::Instantiate<Pet00>(Vector2(300.0f, 400.0f), eLayerType::Pet);
		//mOb00 = object::Instantiate<Obstacle>(Vector2(1200.0f, 500.0f), eLayerType::Obstacle);
		//mOb01 = object::Instantiate<Obstacle>(Vector2(1800.0f, 500.0f), eLayerType::Obstacle);
		//mOb02 = object::Instantiate<Obstacle01>(Vector2(2400.0f, -50.0f), eLayerType::Obstacle);
	}

	void PlayScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::ResultS);
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
		mBG = object::Instantiate<PlayBackGround>(eLayerType::BG);
		mCh00 = object::Instantiate<Character00>(Vector2(200.0f, 500.0f), eLayerType::Player);
		mPet00 = object::Instantiate<Pet00>(Vector2(300.0f, 400.0f), eLayerType::Pet);
		mOb00 = object::Instantiate<Obstacle>(Vector2(1200.0f, 500.0f), eLayerType::Obstacle);
		mOb01 = object::Instantiate<Obstacle>(Vector2(1800.0f, 500.0f), eLayerType::Obstacle);
		mOb02 = object::Instantiate<Obstacle01>(Vector2(2400.0f, -50.0f), eLayerType::Obstacle);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
	}

	void PlayScene::OnExit()
	{
		ya::object::Destory(mBG);
		ya::object::Destory(mCh00);
		ya::object::Destory(mPet00);
		ya::object::Destory(mOb00);
		ya::object::Destory(mOb01);
		ya::object::Destory(mOb02);
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f }); 씬넘길때 원상복귀 시키는것
	}
}