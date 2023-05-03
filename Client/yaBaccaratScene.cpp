#include "yaBaccaratScene.h"
#include "yaBaccaratBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaTime.h"
#include "yaTransform.h"

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

#include "yaCard01_00.h"
#include "yaCard01_01.h"
#include "yaCard01_02.h"
#include "yaCard01_03.h"
#include "yaCard01_04.h"
#include "yaCard01_05.h"
#include "yaCard01_06.h"
#include "yaCard01_07.h"
#include "yaCard01_08.h"
#include "yaCard01_09.h"
#include "yaCard01_10.h"
#include "yaCard01_11.h"
#include "yaCard01_12.h"
#include "yaCard01_13.h"

#include "yaSelect_Player.h"
#include "yaSelect_Banker.h"
#include "yaSelect_Tie.h"

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
	BaccaratScene::BaccaratScene()
	{

	}
	BaccaratScene::~BaccaratScene()
	{

	}

	void BaccaratScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<BaccaratBackGround>(eLayerType::BG);
	}

	void BaccaratScene::Update()
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
					Sound* mClick = Resources::Load<Sound>(L"Click", L"..\\Resources\\Sound\\click.wav");
					mClick->Play(false);

					SceneManager::LoadScene(eSceneType::Main);
				}

				//
				if ((910.f <= mousPos.x && mousPos.x <= 980.f) && (799.f <= mousPos.y && mousPos.y <= 837.f))
				{
					for (auto i = 0; i < 6; i++)
					{
						if (mCards[i] != nullptr)
						{
							object::Destory(mCards[i]);
						}
						mCards[i] = nullptr;
					}


					mBetMoney = 0;

					for (auto i = 0; i < 6; i++)
					{
						if (mBetMoneyOb[i] != nullptr)
						{
							object::Destory(mBetMoneyOb[i]);
						}
						mBetMoneyOb[i] = nullptr;
					}

					mSelect = -1;
					if (mSelectOb != nullptr) object::Destory(mSelectOb);
					mSelectOb = nullptr;

					mTime = 0.0f;

					if (mC00_01 != nullptr) object::Destory(mC00_01);
					if (mC00_02 != nullptr) object::Destory(mC00_02);
					if (mC00_03 != nullptr) object::Destory(mC00_03);
					if (mC00_04 != nullptr) object::Destory(mC00_04);
					if (mC00_05 != nullptr) object::Destory(mC00_05);
					if (mC00_06 != nullptr) object::Destory(mC00_06);
					mC00_01 = nullptr;
					mC00_02 = nullptr;
					mC00_03 = nullptr;
					mC00_04 = nullptr;

					mC00_05 = nullptr;
					mC00_06 = nullptr;

					if (mPlayerSumOb != nullptr) object::Destory(mPlayerSumOb);
					if (mBankerSumOb != nullptr) object::Destory(mBankerSumOb);
					mPlayerSum = 0;
					mPlayerSumOb = nullptr;
					mBankerSum = 0;
					mBankerSumOb = nullptr;

					for (auto i = 0; i < 2; i++)
					{
						mPlayerArray[i] = -1;
						mBankerArray[i] = -1;
					}

					if (mResultOb != nullptr) object::Destory(mResultOb);
					mResultOb = nullptr;

					mResult = -1;
				}

				if ((513.f <= mousPos.x && mousPos.x <= 555.f) && (806.f <= mousPos.y && mousPos.y <= 834.f))
				{
					mBetMoney += 500;
				}
				if ((615.f <= mousPos.x && mousPos.x <= 656.f) && (812.f <= mousPos.y && mousPos.y <= 834.f))
				{
					mBetMoney += 1000;
				}
				if ((711.f <= mousPos.x && mousPos.x <= 753.f) && (806.f <= mousPos.y && mousPos.y <= 834.f))
				{
					mBetMoney += 2000;
				}
				if ((817.f <= mousPos.x && mousPos.x <= 861.f) && (806.f <= mousPos.y && mousPos.y <= 834.f))
				{
					mBetMoney = 0;
					for (auto i = 0; i < 6; i++)
					{
						if (mBetMoneyOb[i] != nullptr)
						{
							object::Destory(mBetMoneyOb[i]);
						}
						mBetMoneyOb[i] = nullptr;
					}
				}

				//
				if (mBetMoney >= 500 && mSelectOb == nullptr)
				{
					if ((675.f <= mousPos.x && mousPos.x <= 921.f) && (616.f <= mousPos.y && mousPos.y <= 651.f))
					{
						mSelect = 1;
						mSelectOb = object::Instantiate<Select_Tie>(Vector2(667.f, 204.f), eLayerType::UI);
					}
					if ((670.f <= mousPos.x && mousPos.x <= 929.f) && (660.f <= mousPos.y && mousPos.y <= 689.f))
					{
						mSelect = 2;
						mSelectOb = object::Instantiate<Select_Banker>(Vector2(667.f, 204.f), eLayerType::UI);
					}
					if ((661.f <= mousPos.x && mousPos.x <= 940.f) && (700.f <= mousPos.y && mousPos.y <= 747.f))
					{
						mSelect = 3;
						mSelectOb = object::Instantiate<Select_Player>(Vector2(667.f, 204.f), eLayerType::UI);
					}

					MainScene::mSilver -= mBetMoney;
				}
			}
		}

		if (mSelect != -1)
		{
			// 게임 시작
			mTime += Time::DeltaTime();
			if (mTime > 1.0f)
			{
				if (mC00_01 == nullptr)
				{
					mC00_01 = object::Instantiate<Card01_00>(Vector2(657.f, 562.f), eLayerType::UI);
				}
			}
			if (mTime > 2.0f)
			{
				if (mC00_03 == nullptr)
				{
					mC00_03 = object::Instantiate<Card01_00>(Vector2(847.f, 562.f), eLayerType::UI);
				}
			}
			if (mTime > 3.0f)
			{
				if (mC00_02 == nullptr)
				{
					mC00_02 = object::Instantiate<Card01_00>(Vector2(745.f, 562.f), eLayerType::UI);
				}
			}
			if (mTime > 4.0f)
			{
				if (mC00_04 == nullptr)
				{
					mC00_04 = object::Instantiate<Card01_00>(Vector2(935.f, 562.f), eLayerType::UI);
				}
			}
			//if (mC00_05 == nullptr)
			//{
			//	mC00_05 = object::Instantiate<Card01_00>(eLayerType::UI);
			//}
			//if (mC00_06 == nullptr)
			//{
			//	mC00_06 = object::Instantiate<Card01_00>(eLayerType::UI);
			//}

			if (mTime > 5.0f)
			{
				for (auto i = 0; i < 4; i++)
				{
					if (mCards[i] == nullptr)
					{
						if ((i == 0 && mTime > 5.0f) || (i == 1 && mTime > 6.0f) || (i == 2 && mTime > 8.0f) || (i == 3 && mTime > 9.0f))
						{
							//srand(time(NULL));
							int tempValue = rand() % 13 + 1;// 1~13
							
							if (i == 0 || i == 1)
							{
								if (mPlayerArray[i] == -1)
								{
									if (tempValue >= 11)
									{
										mPlayerArray[i] = 0;
									}
									else
									{
										mPlayerArray[i] = tempValue;
									}
								}
							}

							if (i == 2 || i == 3)
							{
								if (mBankerArray[i-2] == -1)
								{
									if (tempValue >= 11)
									{
										mBankerArray[i - 2] = 0;
									}
									else
									{
										mBankerArray[i - 2] = tempValue;
									}
								}
							}

							float tempPos;
							if (i == 0) tempPos = 657.f;
							else if (i == 1) tempPos = 745.f;
							else if (i == 2) tempPos = 847.f;
							else if (i == 3) tempPos = 935.f;

							if (tempValue == 1)
							{
								mCards[i] = object::Instantiate<Card01_01>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 2)
							{
								mCards[i] = object::Instantiate<Card01_02>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 3)
							{
								mCards[i] = object::Instantiate<Card01_03>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 4)
							{
								mCards[i] = object::Instantiate<Card01_04>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 5)
							{
								mCards[i] = object::Instantiate<Card01_05>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 6)
							{
								mCards[i] = object::Instantiate<Card01_06>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 7)
							{
								mCards[i] = object::Instantiate<Card01_07>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 8)
							{
								mCards[i] = object::Instantiate<Card01_08>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 9)
							{
								mCards[i] = object::Instantiate<Card01_09>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 10)
							{
								mCards[i] = object::Instantiate<Card01_10>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 11)
							{
								mCards[i] = object::Instantiate<Card01_11>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 12)
							{
								mCards[i] = object::Instantiate<Card01_12>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
							else if (tempValue == 13)
							{
								mCards[i] = object::Instantiate<Card01_13>(Vector2(tempPos, 562.f), eLayerType::UI);
							}
						}
					}
				}
			}
		}

		if (mTime > 7.0f && mPlayerSumOb == nullptr)
		{
			if (mPlayerSumOb != nullptr)
				object::Destory(mPlayerSumOb);

			mPlayerSum = mPlayerArray[0] + mPlayerArray[1];

			if (mPlayerSum >= 10)
			{
				mPlayerSum -= 10;
			}
			if (mPlayerSum >= 20)
			{
				mPlayerSum -= 20;
			}

			std::string tempChar = std::to_string(mPlayerSum);
			
			if (tempChar.size() == 1)
			{
				#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar[0] == '0')
				{
					mPlayerSumOb = object::Instantiate<F_0>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '1')
				{
					mPlayerSumOb = object::Instantiate<F_1>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '2')
				{
					mPlayerSumOb = object::Instantiate<F_2>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '3')
				{
					mPlayerSumOb = object::Instantiate<F_3>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '4')
				{
					mPlayerSumOb = object::Instantiate<F_4>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '5')
				{
					mPlayerSumOb = object::Instantiate<F_5>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '6')
				{
					mPlayerSumOb = object::Instantiate<F_6>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '7')
				{
					mPlayerSumOb = object::Instantiate<F_7>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '8')
				{
					mPlayerSumOb = object::Instantiate<F_8>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '9')
				{
					mPlayerSumOb = object::Instantiate<F_9>(Vector2(684.f, 442.0f), eLayerType::UI);
				}

				Transform* tr = mPlayerSumOb->GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));
				#pragma endregion
			}
			else
			{
				#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar[1] == '0')
				{
					mPlayerSumOb = object::Instantiate<F_0>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '1')
				{
					mPlayerSumOb = object::Instantiate<F_1>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '2')
				{
					mPlayerSumOb = object::Instantiate<F_2>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '3')
				{
					mPlayerSumOb = object::Instantiate<F_3>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '4')
				{
					mPlayerSumOb = object::Instantiate<F_4>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '5')
				{
					mPlayerSumOb = object::Instantiate<F_5>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '6')
				{
					mPlayerSumOb = object::Instantiate<F_6>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '7')
				{
					mPlayerSumOb = object::Instantiate<F_7>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '8')
				{
					mPlayerSumOb = object::Instantiate<F_8>(Vector2(684.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '9')
				{
					mPlayerSumOb = object::Instantiate<F_9>(Vector2(684.f, 442.0f), eLayerType::UI);
				}

				Transform* tr = mPlayerSumOb->GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));
				#pragma endregion
			}
		}

		if (mTime > 10.0f && mBankerSumOb == nullptr)
		{
			if (mBankerSumOb != nullptr)
				object::Destory(mBankerSumOb);

			mBankerSum = mBankerArray[0] + mBankerArray[1];

			if (mBankerSum >= 10)
			{
				mBankerSum -= 10;
			}
			if (mBankerSum >= 20)
			{
				mBankerSum -= 20;
			}

			std::string tempChar = std::to_string(mBankerSum);

			if (tempChar.size() == 1)
			{
#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar[0] == '0')
				{
					mBankerSumOb = object::Instantiate<F_0>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '1')
				{
					mBankerSumOb = object::Instantiate<F_1>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '2')
				{
					mBankerSumOb = object::Instantiate<F_2>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '3')
				{
					mBankerSumOb = object::Instantiate<F_3>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '4')
				{
					mBankerSumOb = object::Instantiate<F_4>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '5')
				{
					mBankerSumOb = object::Instantiate<F_5>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '6')
				{
					mBankerSumOb = object::Instantiate<F_6>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '7')
				{
					mBankerSumOb = object::Instantiate<F_7>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '8')
				{
					mBankerSumOb = object::Instantiate<F_8>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[0] == '9')
				{
					mBankerSumOb = object::Instantiate<F_9>(Vector2(892.f, 442.0f), eLayerType::UI);
				}

				Transform* tr = mBankerSumOb->GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));
#pragma endregion
			}
			else
			{
#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar[1] == '0')
				{
					mBankerSumOb = object::Instantiate<F_0>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '1')
				{
					mBankerSumOb = object::Instantiate<F_1>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '2')
				{
					mBankerSumOb = object::Instantiate<F_2>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '3')
				{
					mBankerSumOb = object::Instantiate<F_3>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '4')
				{
					mBankerSumOb = object::Instantiate<F_4>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '5')
				{
					mBankerSumOb = object::Instantiate<F_5>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '6')
				{
					mBankerSumOb = object::Instantiate<F_6>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '7')
				{
					mBankerSumOb = object::Instantiate<F_7>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '8')
				{
					mBankerSumOb = object::Instantiate<F_8>(Vector2(892.f, 442.0f), eLayerType::UI);
				}
				if (tempChar[1] == '9')
				{
					mBankerSumOb = object::Instantiate<F_9>(Vector2(892.f, 442.0f), eLayerType::UI);
				}

				Transform* tr = mBankerSumOb->GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));
#pragma endregion
			}
		}

		if (mTime > 11.f && mResultOb == nullptr)
		{
			if (mBankerSum > mPlayerSum)
			{
				mResult = 2;
				if (mResult == mSelect)
				{
					MainScene::mSilver += mBetMoney * 2;
				}
				mResultOb = object::Instantiate<Select_Banker>(Vector2(930.f, 204.f), eLayerType::UI);
			}
			else if (mBankerSum < mPlayerSum)
			{
				mResult = 3;
				if (mResult == mSelect)
				{
					MainScene::mSilver += mBetMoney * 2;
				}
				mResultOb = object::Instantiate<Select_Player>(Vector2(930.f, 204.f), eLayerType::UI);
			}
			else if (mBankerSum == mPlayerSum)
			{
				mResult = 1; 
				if (mResult == mSelect)
				{
					MainScene::mSilver += mBetMoney * 8;
				}
				mResultOb = object::Instantiate<Select_Tie>(Vector2(930.f, 204.f), eLayerType::UI);
			}
		}

		//mResult == mSelect
		// get Money
		// player *2
		// banker *1.95
		// tie *8


		if (mBetMoney >= 500)
		{
			for (auto i = 0; i < 6; i++)
			{
				if (mBetMoneyOb[i] != nullptr)
				{
					object::Destory(mBetMoneyOb[i]);
				}
				mBetMoneyOb[i] = nullptr;
			}

			std::string temp = std::to_string(mBetMoney);
			int size = temp.size();
			int totalSize = 5;

			float tempPos = 760.f + 22.0f * (totalSize - size + 1);

			for (auto i = 0; i < size; i++)
			{
				char tempChar = temp[i];
				#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar == '0')
				{
					mBetMoneyOb[i] = object::Instantiate<F_0>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '1')
				{
					mBetMoneyOb[i] = object::Instantiate<F_1>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '2')
				{
					mBetMoneyOb[i] = object::Instantiate<F_2>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '3')
				{
					mBetMoneyOb[i] = object::Instantiate<F_3>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '4')
				{
					mBetMoneyOb[i] = object::Instantiate<F_4>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '5')
				{
					mBetMoneyOb[i] = object::Instantiate<F_5>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '6')
				{
					mBetMoneyOb[i] = object::Instantiate<F_6>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '7')
				{
					mBetMoneyOb[i] = object::Instantiate<F_7>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '8')
				{
					mBetMoneyOb[i] = object::Instantiate<F_8>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
				if (tempChar == '9')
				{
					mBetMoneyOb[i] = object::Instantiate<F_9>(Vector2(tempPos + (i * 22.0f), 342.0f), eLayerType::UI);
				}
#pragma endregion
			}
		}

		Scene::Update();
	}

	void BaccaratScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void BaccaratScene::Release()
	{
		Scene::Release();
	}

	void BaccaratScene::OnEnter()
	{
		mBetMoney = 0;

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

	void BaccaratScene::OnExit()
	{
		for (auto i = 0; i < 6; i++)
		{
			if (mCards[i] != nullptr)
			{
				object::Destory(mCards[i]);
			}
			mCards[i] = nullptr;
		}
		
		mBetMoney = 0;
		for (auto i = 0; i < 6; i++)
		{
			if (mBetMoneyOb[i] != nullptr)
			{
				object::Destory(mBetMoneyOb[i]);
			}
			mBetMoneyOb[i] = nullptr;
		}


		mSelect = -1;
		if(mSelectOb != nullptr) object::Destory(mSelectOb);
		mSelectOb = nullptr;

		mTime = 0.0f;

		if (mC00_01 != nullptr) object::Destory(mC00_01);
		if (mC00_02 != nullptr) object::Destory(mC00_02);
		if (mC00_03 != nullptr) object::Destory(mC00_03);
		if (mC00_04 != nullptr) object::Destory(mC00_04);
		if (mC00_05 != nullptr) object::Destory(mC00_05);
		if (mC00_06 != nullptr) object::Destory(mC00_06);
		mC00_01 = nullptr;
		mC00_02 = nullptr;
		mC00_03 = nullptr;
		mC00_04 = nullptr;

		mC00_05 = nullptr;
		mC00_06 = nullptr;

		if (mPlayerSumOb != nullptr) object::Destory(mPlayerSumOb);
		if (mBankerSumOb != nullptr) object::Destory(mBankerSumOb);
		mPlayerSum = 0;
		mPlayerSumOb = nullptr;
		mBankerSum = 0;
		mBankerSumOb = nullptr;

		for (auto i = 0; i < 2; i++)
		{
			mPlayerArray[i] = -1;
			mBankerArray[i] = -1;
		}

		if (mResultOb != nullptr) object::Destory(mResultOb);
		mResultOb = nullptr;

		mResult = -1;

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
}