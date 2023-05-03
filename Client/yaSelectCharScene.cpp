#include "yaSelectCharScene.h"
#include "yaSelectCharBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"

#include "yaSound.h"
#include "yaResources.h"


#include "yaSound.h"
#include "yaResources.h"

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
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SceneManager::LoadScene(eSceneType::Main);
				}

				if ((273.f <= mousPos.x && mousPos.x <= 392.f) && (130.f <= mousPos.y && mousPos.y <= 181.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SceneManager::LoadScene(eSceneType::SelectPet);
				}


				if ((59.f <= mousPos.x && mousPos.x <= 372.f) && (258.f <= mousPos.y && mousPos.y <= 545.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 1;
				}
				if ((443.f <= mousPos.x && mousPos.x <= 762.f) && (258.f <= mousPos.y && mousPos.y <= 545.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 2;
				}
				if ((837.f <= mousPos.x && mousPos.x <= 1152.f) && (258.f <= mousPos.y && mousPos.y <= 545.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 3;
				}
				if ((1221.f <= mousPos.x && mousPos.x <= 1541.f) && (258.f <= mousPos.y && mousPos.y <= 545.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 4;
				}

				if ((57.f <= mousPos.x && mousPos.x <= 373.f) && (577.f <= mousPos.y && mousPos.y <= 872.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 5;
				}
				if ((443.f <= mousPos.x && mousPos.x <= 762.f) && (577.f <= mousPos.y && mousPos.y <= 872.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 6;
				}
				if ((837.f <= mousPos.x && mousPos.x <= 1152.f) && (577.f <= mousPos.y && mousPos.y <= 872.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 7;
				}
				if ((1221.f <= mousPos.x && mousPos.x <= 1541.f) && (577.f <= mousPos.y && mousPos.y <= 872.f))
				{
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SelectCharScene::mCharNumber = 8;
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