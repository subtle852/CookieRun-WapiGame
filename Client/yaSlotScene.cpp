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

						srand(time(NULL));
						tempValueF = rand() % 7 + 1;// 1~7

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
						int tempRand = rand() % 4;
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
	}

	void SlotScene::OnExit()
	{

	}
}