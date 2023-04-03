#include "yaStoreScene.h"
#include "yaStoreBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
namespace ya
{
	StoreScene::StoreScene()
	{

	}
	StoreScene::~StoreScene()
	{

	}

	void StoreScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<StoreBackGround>(eLayerType::BG);
	}

	void StoreScene::Update()
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

				if ((0.f <= mousPos.x && mousPos.x <= 96.f) && (0.f <= mousPos.y && mousPos.y <= 96.f))
				{
					SceneManager::LoadScene(eSceneType::Main);
				}
			}
		}

		Scene::Update();
	}

	void StoreScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void StoreScene::Release()
	{
		Scene::Release();
	}

	void StoreScene::OnEnter()
	{

	}

	void StoreScene::OnExit()
	{

	}
}