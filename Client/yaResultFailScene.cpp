#include "yaResultFailScene.h"
#include "yaResultFailBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaPlayScene.h"

#include "yaF_0.h" 
#include "yaF_1.h" 
#include "yaF_2.h" 
#include "yaF_3.h" 
#include "yaF_4.h" 
#include "yaF_5.h"
#include "yaF_6.h" 
#include "yaF_7.h" 
#include "yaF_8.h" 
#include "yaF_9.h"

#include "yaSound.h"
#include "yaResources.h"

namespace ya
{
	ResultFailScene::ResultFailScene()
	{
	}

	ResultFailScene::~ResultFailScene()
	{
	}

	void ResultFailScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<ResultFailBackGround>(eLayerType::BG);
	}

	void ResultFailScene::Update()
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

				if ((627.f <= mousPos.x && mousPos.x <= 972.f) && (759.f <= mousPos.y && mousPos.y <= 875.f))
				{
					SceneManager::LoadScene(eSceneType::Main);
				}
			}
		}

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}
	}

	void ResultFailScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void ResultFailScene::Release()
	{
		Scene::Release();
	}

	void ResultFailScene::OnEnter()
	{
		std::string temp = std::to_string(PlayScene::mSilver);
		int size = temp.size();
		int totalSize = 5;

		float tempPos = 648.f + 50.0f * (totalSize - size + 1);

		for (auto i = 0; i < size; i++)
		{
			char tempChar = temp[i];
#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs[i] = object::Instantiate<F_0>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs[i] = object::Instantiate<F_1>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs[i] = object::Instantiate<F_2>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs[i] = object::Instantiate<F_3>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs[i] = object::Instantiate<F_4>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs[i] = object::Instantiate<F_5>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs[i] = object::Instantiate<F_6>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs[i] = object::Instantiate<F_7>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs[i] = object::Instantiate<F_8>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs[i] = object::Instantiate<F_9>(Vector2(tempPos + (i * 50.0f), 700.0f), eLayerType::UI);
			}
#pragma endregion
		}
		//

		std::string temp2 = std::to_string(PlayScene::mScore);
		int size2 = temp2.size();
		int totalSize2 = 5;

		float tempPos2 = 648.f + 50.0f * (totalSize2 - size2 + 1);

		for (auto i = 0; i < size2; i++)
		{
			char tempChar = temp2[i];
#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs2[i] = object::Instantiate<F_0>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs2[i] = object::Instantiate<F_1>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs2[i] = object::Instantiate<F_2>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs2[i] = object::Instantiate<F_3>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs2[i] = object::Instantiate<F_4>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs2[i] = object::Instantiate<F_5>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs2[i] = object::Instantiate<F_6>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs2[i] = object::Instantiate<F_7>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs2[i] = object::Instantiate<F_8>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs2[i] = object::Instantiate<F_9>(Vector2(tempPos2 + (i * 50.0f), 392.f), eLayerType::UI);
			}
#pragma endregion
		}
	}

	void ResultFailScene::OnExit()
	{
		for (auto i = 0; i < 6; i++)
		{
			if (mObs[i] != nullptr)
				object::Destory(mObs[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs[i] = nullptr;
		}

		for (auto i = 0; i < 6; i++)
		{
			if (mObs2[i] != nullptr)
				object::Destory(mObs2[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs2[i] = nullptr;
		}
	}
}