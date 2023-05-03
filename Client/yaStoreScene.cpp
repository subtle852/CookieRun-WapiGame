#include "yaStoreScene.h"
#include "yaStoreBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaMainScene.h"

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
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SceneManager::LoadScene(eSceneType::Main);
				}

				if ((555.f <= mousPos.x && mousPos.x <= 833.f) && (91.f <= mousPos.y && mousPos.y <= 381.f))
				{
					MainScene::mDia += 400;
				}
				if ((860.f <= mousPos.x && mousPos.x <= 1136.f) && (91.f <= mousPos.y && mousPos.y <= 381.f))
				{
					MainScene::mDia += 4000;
				}
				if ((1165.f <= mousPos.x && mousPos.x <= 1441.f) && (91.f <= mousPos.y && mousPos.y <= 381.f))
				{
					MainScene::mDia += 20000;
				}
				if ((555.f <= mousPos.x && mousPos.x <= 833.f) && (498.f <= mousPos.y && mousPos.y <= 781.f))
				{
					MainScene::mDia -= 100;
					MainScene::mSilver += 70000;
				}
				if ((860.f <= mousPos.x && mousPos.x <= 1136.f) && (498.f <= mousPos.y && mousPos.y <= 781.f))
				{
					MainScene::mDia -= 500;
					MainScene::mSilver += 350000;
				}
				if ((555.f <= mousPos.x && mousPos.x <= 833.f) && (498.f <= mousPos.y && mousPos.y <= 781.f))
				{
					MainScene::mDia -= 1000;
					MainScene::mSilver += 700000;
				}
			}
		}

//		for (auto i = 0; i < 6; i++)
//		{
//			if (mObs[i] != nullptr)
//				object::Destory(mObs[i]);
//		}
//		for (auto i = 0; i < 6; i++)
//		{
//			mObs[i] = nullptr;
//		}
//
//		std::string temp = std::to_string(MainScene::mSilver);
//		int size = temp.size();
//		int totalSize = 5;
//
//		float tempPos = 1426.f + 22.0f * (totalSize - size + 1);
//
//		for (auto i = 0; i < size; i++)
//		{
//			char tempChar = temp[i];
//#pragma region 문자에 맞는 해당 이미지 생성
//			if (tempChar == '0')
//			{
//				mObs[i] = object::Instantiate<F_0>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '1')
//			{
//				mObs[i] = object::Instantiate<F_1>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '2')
//			{
//				mObs[i] = object::Instantiate<F_2>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '3')
//			{
//				mObs[i] = object::Instantiate<F_3>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '4')
//			{
//				mObs[i] = object::Instantiate<F_4>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '5')
//			{
//				mObs[i] = object::Instantiate<F_5>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '6')
//			{
//				mObs[i] = object::Instantiate<F_6>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '7')
//			{
//				mObs[i] = object::Instantiate<F_7>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '8')
//			{
//				mObs[i] = object::Instantiate<F_8>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '9')
//			{
//				mObs[i] = object::Instantiate<F_9>(Vector2(tempPos + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//#pragma endregion
//		}
//		//
//		for (auto i = 0; i < 6; i++)
//		{
//			if (mObs2[i] != nullptr)
//				object::Destory(mObs2[i]);
//		}
//		for (auto i = 0; i < 6; i++)
//		{
//			mObs2[i] = nullptr;
//		}
//
//		std::string temp2 = std::to_string(MainScene::mDia);
//		int size2 = temp2.size();
//		int totalSize2 = 5;
//
//		float tempPos2 = 1174.f + 22.0f * (totalSize2 - size2 + 1);
//
//		for (auto i = 0; i < size2; i++)
//		{
//			char tempChar = temp2[i];
//#pragma region 문자에 맞는 해당 이미지 생성
//			if (tempChar == '0')
//			{
//				mObs2[i] = object::Instantiate<F_0>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '1')
//			{
//				mObs2[i] = object::Instantiate<F_1>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '2')
//			{
//				mObs2[i] = object::Instantiate<F_2>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '3')
//			{
//				mObs2[i] = object::Instantiate<F_3>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '4')
//			{
//				mObs2[i] = object::Instantiate<F_4>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '5')
//			{
//				mObs2[i] = object::Instantiate<F_5>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '6')
//			{
//				mObs2[i] = object::Instantiate<F_6>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '7')
//			{
//				mObs2[i] = object::Instantiate<F_7>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '8')
//			{
//				mObs2[i] = object::Instantiate<F_8>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//			if (tempChar == '9')
//			{
//				mObs2[i] = object::Instantiate<F_9>(Vector2(tempPos2 + (i * 22.0f), 95.0f), eLayerType::UI);
//			}
//#pragma endregion
//		}

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

	void StoreScene::OnExit()
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