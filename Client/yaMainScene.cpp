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

		mCh00 = object::Instantiate<Character01>(Vector2(800.0f, 620.0f), eLayerType::Player);
		mPet00 = object::Instantiate<Pet01>(Vector2(900.0f, 520.0f), eLayerType::Pet);

		object::Instantiate<PlayButton>(Vector2(1100.0f, 700.0f), eLayerType::UI);
		object::Instantiate<DiaUI>(Vector2(1000.0f, 50.0f), eLayerType::UI);
		object::Instantiate<SilverUI>(Vector2(1300.0f, 50.0f), eLayerType::UI);

		object::Instantiate<CookiesUI>(Vector2(150.0f, 700.0f), eLayerType::UI);
		object::Instantiate<GachaUI>(Vector2(150.0f, 100.0f), eLayerType::UI);
		object::Instantiate<StoreUI>(Vector2(150.0f, 300.0f), eLayerType::UI);
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

		Scene::SceneText(hdc);
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