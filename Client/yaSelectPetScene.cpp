#include "yaSelectPetScene.h"
#include "yaSelectPetBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
namespace ya
{
	int SelectPetScene::mPetNumber = 1;

	SelectPetScene::SelectPetScene()
	{

	}
	SelectPetScene::~SelectPetScene()
	{

	}

	void SelectPetScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<SelectPetBackGround>(eLayerType::BG);
	}

	void SelectPetScene::Update()
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

				if ((107.f <= mousPos.x && mousPos.x <= 233.f) && (128.f <= mousPos.y && mousPos.y <= 184.f))
				{
					SceneManager::LoadScene(eSceneType::SelectChar);
				}
			}
		}

		Scene::Update();
	}

	void SelectPetScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void SelectPetScene::Release()
	{
		Scene::Release();
	}

	void SelectPetScene::OnEnter()
	{

	}

	void SelectPetScene::OnExit()
	{

	}
}