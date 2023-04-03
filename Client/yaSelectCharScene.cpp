#include "yaSelectCharScene.h"
#include "yaSelectCharBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
namespace ya
{
	int SelectCharScene::mCharNumber = 1;

	SelectCharScene::SelectCharScene()
	{

	}
	SelectCharScene::~SelectCharScene()
	{

	}

	void SelectCharScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<SelectCharBackGround>(eLayerType::BG);
	}

	void SelectCharScene::Update()
	{
		//if (1번 쿠키 UI 버튼 누르면)
		//{
		//	mCharNumber = 1;
		//}

		//if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		//{
		//	SceneManager::LoadScene(eSceneType::SelectStage);
		//	//SelectCharBackGround::flag = true;
		//}

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

				if ((273.f <= mousPos.x && mousPos.x <= 392.f) && (130.f <= mousPos.y && mousPos.y <= 181.f))
				{
					SceneManager::LoadScene(eSceneType::SelectPet);
				}
			}
		}

		Scene::Update();
	}

	void SelectCharScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void SelectCharScene::Release()
	{
		Scene::Release();
	}

	void SelectCharScene::OnEnter()
	{
		
	}

	void SelectCharScene::OnExit()
	{
	}
}