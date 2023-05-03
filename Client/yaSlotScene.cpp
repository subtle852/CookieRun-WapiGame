#include "yaSlotScene.h"
#include "yaSlotBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaTime.h"

#include "yaSlot01.h"
#include "yaSlotB01.h"
#include "yaSlotB02.h"
#include "yaSlotB03.h"
#include "yaSlotBs.h"

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

namespace ya
{
	SlotScene::SlotScene()
	{

	}
	SlotScene::~SlotScene()
	{

	}

	void SlotScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<SlotBackGround>(eLayerType::BG);
		mSlot01 = object::Instantiate<Slot01>(Vector2(561.f, 656.99f), eLayerType::UI);
		mSlot01->mState = eSlot01State::L1;

		mSlot02 = object::Instantiate<Slot01>(Vector2(667.f, 656.99f), eLayerType::UI);
		mSlot02->mState = eSlot01State::L1;

		mSlot03 = object::Instantiate<Slot01>(Vector2(774.f, 656.99f), eLayerType::UI);
		mSlot03->mState = eSlot01State::L1;

	}

	void SlotScene::Update()
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

		float tempPos = 1408.f + 22.0f * (totalSize - size + 1);

		for (auto i = 0; i < size; i++)
		{
			char tempChar = temp[i];
#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs[i] = object::Instantiate<F_0>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs[i] = object::Instantiate<F_1>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs[i] = object::Instantiate<F_2>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs[i] = object::Instantiate<F_3>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs[i] = object::Instantiate<F_4>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs[i] = object::Instantiate<F_5>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs[i] = object::Instantiate<F_6>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs[i] = object::Instantiate<F_7>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs[i] = object::Instantiate<F_8>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs[i] = object::Instantiate<F_9>(Vector2(tempPos + (i * 22.0f), 122.0f), eLayerType::UI);
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

		float tempPos2 = 1158.f + 22.0f * (totalSize2 - size2 + 1);

		for (auto i = 0; i < size2; i++)
		{
			char tempChar = temp2[i];
#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs2[i] = object::Instantiate<F_0>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs2[i] = object::Instantiate<F_1>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs2[i] = object::Instantiate<F_2>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs2[i] = object::Instantiate<F_3>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs2[i] = object::Instantiate<F_4>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs2[i] = object::Instantiate<F_5>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs2[i] = object::Instantiate<F_6>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs2[i] = object::Instantiate<F_7>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs2[i] = object::Instantiate<F_8>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs2[i] = object::Instantiate<F_9>(Vector2(tempPos2 + (i * 22.0f), 122.0f), eLayerType::UI);
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

				if ((0.f <= mousPos.x && mousPos.x <= 96.f) && (0.f <= mousPos.y && mousPos.y <= 96.f))
				{
					SceneManager::LoadScene(eSceneType::Main);
				}


				if (mSlot01->mState == eSlot01State::L1)
				{
					if ((530.f <= mousPos.x && mousPos.x <= 591.f) && (784.f <= mousPos.y && mousPos.y <= 812.f))
					{
						mSlotB01 = object::Instantiate<SlotB01>(Vector2(558.f, 817.f), eLayerType::UI);

						MainScene::mSilver -= 1000;

						srand(time(NULL));
						tempValueF = rand() % 7 + 1;// 1~7

						mSlotResult[0] = tempValueF;

						if (tempValueF == 1)
						{
							mSlot01->mState = eSlot01State::R1;
						}
						else if (tempValueF == 2)
						{
							mSlot01->mState = eSlot01State::R2;
						}
						else if (tempValueF == 3)
						{
							mSlot01->mState = eSlot01State::R3;
						}
						else if (tempValueF == 4)
						{
							mSlot01->mState = eSlot01State::R4;
						}
						else if (tempValueF == 5)
						{
							mSlot01->mState = eSlot01State::R5;
						}
						else if (tempValueF == 6)
						{
							mSlot01->mState = eSlot01State::R6;
						}
						else if (tempValueF == 7)
						{
							mSlot01->mState = eSlot01State::R7;
						}

					}
				}

				if (mSlot02->mState == eSlot01State::L1)
				{
					if ((638.f <= mousPos.x && mousPos.x <= 707.f) && (786.f <= mousPos.y && mousPos.y <= 812.f))
					{
						mSlotB02 = object::Instantiate<SlotB02>(Vector2(670.f, 817.f), eLayerType::UI);

						srand(time(NULL)); //int tempValue = 1;
						int tempValue = rand() % 7 + 1;// 1~7

						int tempArray[2];
						tempArray[0] = tempValueF;
						tempArray[1] = tempValue;

						int tempHalf = rand() % 2;
						if (tempHalf == 0)
						{
							tempValue = tempArray[0];
						}
						else if (tempHalf == 1)
						{
							tempValue = tempArray[1];
						}

						tempValueS = tempValue;

						mSlotResult[1] = tempValueS;

						if (tempValue == 1)
						{
							mSlot02->mState = eSlot01State::R1;
						}
						else if (tempValue == 2)
						{
							mSlot02->mState = eSlot01State::R2;
						}
						else if (tempValue == 3)
						{
							mSlot02->mState = eSlot01State::R3;
						}
						else if (tempValue == 4)
						{
							mSlot02->mState = eSlot01State::R4;
						}
						else if (tempValue == 5)
						{
							mSlot02->mState = eSlot01State::R5;
						}
						else if (tempValue == 6)
						{
							mSlot02->mState = eSlot01State::R6;
						}
						else if (tempValue == 7)
						{
							mSlot02->mState = eSlot01State::R7;
						}
					}
				}

				if (mSlot03->mState == eSlot01State::L1)
				{
					if ((755.f <= mousPos.x && mousPos.x <= 814.f) && (784.f <= mousPos.y && mousPos.y <= 808.f))
					{
						mSlotB03 = object::Instantiate<SlotB03>(Vector2(785.f, 817.f), eLayerType::UI);

						//srand(time(NULL)); //int tempValue = 1;
						int tempValue = rand() % 7 + 1;// 1~7

						int tempArray[2];
						tempArray[0] = tempValueS;
						tempArray[1] = tempValue;

						//srand(time(NULL));
						int tempRand = rand() % 4 + 1;
						if (tempRand == 0)
						{
							tempValue = tempArray[1];
						}
						else if (tempRand == 1)
						{
							tempValue = tempArray[1];
						}
						else if (tempRand == 2)
						{
							tempValue = tempArray[1];
						}
						else if (tempRand == 3)
						{
							tempValue = tempArray[1];
						}
						else if (tempRand == 4)
						{
							tempValue = tempArray[0];
						}

						mSlotResult[2] = tempValue;

						if (tempValue == 1)
						{
							mSlot03->mState = eSlot01State::R1;
						}
						else if (tempValue == 2)
						{
							mSlot03->mState = eSlot01State::R2;
						}
						else if (tempValue == 3)
						{
							mSlot03->mState = eSlot01State::R3;
						}
						else if (tempValue == 4)
						{
							mSlot03->mState = eSlot01State::R4;
						}
						else if (tempValue == 5)
						{
							mSlot03->mState = eSlot01State::R5;
						}
						else if (tempValue == 6)
						{
							mSlot03->mState = eSlot01State::R6;
						}
						else if (tempValue == 7)
						{
							mSlot03->mState = eSlot01State::R7;
						}

					}
				}
			}

			if (mSlotResult[0] == mSlotResult[1] && mSlotResult[1] == mSlotResult[2])
			{
				if (mSlotResult[0] != -1)
				{
					if (mSlotResult[1] != -1)
					{
						if (mSlotResult[2] != -1)
						{
							mFinalTime += Time::DeltaTime();

							if (mFinalTime > 1.0f)
							{
								MainScene::mSilver += 10000;
								mFinalTime = 0.0f;

								mSlotResult[0] = -1;
								mSlotResult[1] = -1;
								mSlotResult[2] = -1;
							}
						}
					}
				}
			}

			if (Input::GetKeyUp(eKeyCode::LBUTTON))
			{
				if (mSlotB01 != nullptr)
				{
					object::Destory(mSlotB01);
				}
				if (mSlotB02 != nullptr)
				{
					object::Destory(mSlotB02);
				}
				if (mSlotB03 != nullptr)
				{
					object::Destory(mSlotB03);
				}
				if (mSlotBs != nullptr)
				{
					object::Destory(mSlotBs);
				}
			}

			if (mSlot01->mState != eSlot01State::L1 && mSlot02->mState != eSlot01State::L1 && mSlot03->mState != eSlot01State::L1)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					Vector2 mousPos2 = Input::GetMousePos();
					if ((1007.f <= mousPos2.x && mousPos2.x <= 1066.f) && (782.f <= mousPos2.y && mousPos2.y <= 806.f))
					{
						mSlotBs = object::Instantiate<SlotBs>(Vector2(1043.f, 817.f), eLayerType::UI);
						mSlot01->mState = eSlot01State::L1;
						mSlot02->mState = eSlot01State::L1;
						mSlot03->mState = eSlot01State::L1;
					}
				}
			}
		}

		Scene::Update();
	}

	void SlotScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void SlotScene::Release()
	{
		Scene::Release();
	}

	void SlotScene::OnEnter()
	{
		mSlot01->mState = eSlot01State::L1;
		mSlot02->mState = eSlot01State::L1;
		mSlot03->mState = eSlot01State::L1;

		//
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

	void SlotScene::OnExit()
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