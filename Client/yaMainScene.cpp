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

namespace ya
{
	int MainScene::mSilver = 500000;
	int MainScene::mDia = 100000;

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

		//object::Instantiate<GachaUI>(Vector2(150.0f, 100.0f), eLayerType::UI);
		//object::Instantiate<StoreUI>(Vector2(150.0f, 300.0f), eLayerType::UI);
	}

	void MainScene::Update()
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

		std::string temp = std::to_string(MainScene::mSilver);
		int size = temp.size();
		int totalSize = 5;

		float tempPos = 1355.f + 22.0f *(totalSize - size + 1);

		for (auto i = 0; i < size; i++)
		{
			char tempChar = temp[i];
			#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs[i] = object::Instantiate<F_0>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs[i] = object::Instantiate<F_1>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs[i] = object::Instantiate<F_2>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs[i] = object::Instantiate<F_3>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs[i] = object::Instantiate<F_4>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs[i] = object::Instantiate<F_5>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs[i] = object::Instantiate<F_6>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs[i] = object::Instantiate<F_7>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs[i] = object::Instantiate<F_8>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs[i] = object::Instantiate<F_9>(Vector2(tempPos + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			#pragma endregion
		}
		//
		for (auto i = 0; i < 6; i++)
		{
			if (mObs2[i] != nullptr)
				object::Destory(mObs2[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs2[i] = nullptr;
		}

		std::string temp2 = std::to_string(MainScene::mDia);
		int size2 = temp2.size();
		int totalSize2 = 5;

		float tempPos2 = 1110.f + 22.0f * (totalSize2 - size2 + 1);

		for (auto i = 0; i < size2; i++)
		{
			char tempChar = temp2[i];
			#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs2[i] = object::Instantiate<F_0>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs2[i] = object::Instantiate<F_1>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs2[i] = object::Instantiate<F_2>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs2[i] = object::Instantiate<F_3>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs2[i] = object::Instantiate<F_4>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs2[i] = object::Instantiate<F_5>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs2[i] = object::Instantiate<F_6>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs2[i] = object::Instantiate<F_7>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs2[i] = object::Instantiate<F_8>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs2[i] = object::Instantiate<F_9>(Vector2(tempPos2 + (i * 22.0f), 139.0f), eLayerType::UI);
			}
#pragma endregion
		}



		if (GetFocus())
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				Vector2 mousPos = Input::GetMousePos();
				if (mousPos.x >= 1600.0f || mousPos.x <= 0.0f)
					return;
				if (mousPos.y >= 900.0f || mousPos.y <= 0.0f)
					return;

				if ((276.f <= mousPos.x && mousPos.x <= 360.f) && (163.f <= mousPos.y && mousPos.y <= 218.f))
				{
					SceneManager::LoadScene(eSceneType::Lottery);
				}
				if ((276.f <= mousPos.x && mousPos.x <= 360.f) && (286.f <= mousPos.y && mousPos.y <= 342.f))
				{
					SceneManager::LoadScene(eSceneType::Store);
				}
				if ((276.f <= mousPos.x && mousPos.x <= 360.f) && (415.f <= mousPos.y && mousPos.y <= 474.f))
				{
					SceneManager::LoadScene(eSceneType::Slot);
				}
				if ((276.f <= mousPos.x && mousPos.x <= 360.f) && (540.f <= mousPos.y && mousPos.y <= 595.f))
				{
					SceneManager::LoadScene(eSceneType::Racing);
				}
				if ((276.f <= mousPos.x && mousPos.x <= 360.f) && (617.f <= mousPos.y && mousPos.y <= 656.f))
				{
					SceneManager::LoadScene(eSceneType::Baccarat);
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

	void MainScene::OnExit()
	{
		ya::object::Destory(mCh00);
		ya::object::Destory(mPet00);

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