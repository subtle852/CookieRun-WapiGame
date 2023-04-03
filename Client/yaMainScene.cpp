#include "yaMainScene.h"
#include "yaCharacter01.h"
#include "yaPet01.h"
#include "yaMainBackGround.h"
#include "yaPlayButton.h"
#include "yaDiaUI.h"
#include "yaSilverUI.h"
#include "yaCookiesUI.h"
#include "yaGachaUI.h"
#include "yaStoreUI.h"

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

		object::Instantiate<MainBackGround>(eLayerType::BG);

		//mCh00 = object::Instantiate<Character01>(Vector2(780.0f, 580.0f), eLayerType::Player);
		//mPet00 = object::Instantiate<Pet01>(Vector2(880.0f, 480.0f), eLayerType::Pet);

		//object::Instantiate<PlayButton>(Vector2(1100.0f, 700.0f), eLayerType::UI);
		//object::Instantiate<DiaUI>(Vector2(1000.0f, 50.0f), eLayerType::UI);
		//object::Instantiate<SilverUI>(Vector2(1300.0f, 50.0f), eLayerType::UI);

		//object::Instantiate<CookiesUI>(Vector2(150.0f, 700.0f), eLayerType::UI);
		//object::Instantiate<GachaUI>(Vector2(150.0f, 100.0f), eLayerType::UI);
		//object::Instantiate<StoreUI>(Vector2(150.0f, 300.0f), eLayerType::UI);
	}

	void MainScene::Update()
	{
		if (GetFocus())
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				Vector2 mousPos = Input::GetMousePos();
				if (mousPos.x >= 1600.0f || mousPos.x <= 0.0f)
					return;
				if (mousPos.y >= 900.0f || mousPos.y <= 0.0f)
					return;

				if ((266.f <= mousPos.x && mousPos.x <= 352.f) && (226.f <= mousPos.y && mousPos.y <= 276.f))
				{
					SceneManager::LoadScene(eSceneType::Lottery);
				}
				if ((266.f <= mousPos.x && mousPos.x <= 350.f) && (364.f <= mousPos.y && mousPos.y <= 411.f))
				{
					SceneManager::LoadScene(eSceneType::Store);
				}
				if ((196.f <= mousPos.x && mousPos.x <= 424.f) && (685.f <= mousPos.y && mousPos.y <= 784.f))
				{
					SceneManager::LoadScene(eSceneType::SelectChar);
				}
				if ((1084.f <= mousPos.x && mousPos.x <= 1457.f) && (686.f <= mousPos.y && mousPos.y <= 787.f))
				{
					SceneManager::LoadScene(eSceneType::Play);
				}
			}
		}


		Scene::Update();

	}

	void MainScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void MainScene::Release()
	{
		Scene::Release();
	}

	void MainScene::OnEnter()
	{
		mCh00 = object::Instantiate<Character01>(Vector2(780.0f, 580.0f), eLayerType::Player);
		mPet00 = object::Instantiate<Pet01>(Vector2(880.0f, 480.0f), eLayerType::Pet);

		//object::Instantiate<PlayButton>(Vector2(1100.0f, 700.0f), eLayerType::UI);
		//object::Instantiate<DiaUI>(Vector2(1000.0f, 50.0f), eLayerType::UI);
		//object::Instantiate<SilverUI>(Vector2(1300.0f, 50.0f), eLayerType::UI);

		//object::Instantiate<CookiesUI>(Vector2(150.0f, 700.0f), eLayerType::UI);
		//object::Instantiate<GachaUI>(Vector2(150.0f, 100.0f), eLayerType::UI);
		//object::Instantiate<StoreUI>(Vector2(150.0f, 300.0f), eLayerType::UI);
	}

	void MainScene::OnExit()
	{
		ya::object::Destory(mCh00);
		ya::object::Destory(mPet00);
	}
}