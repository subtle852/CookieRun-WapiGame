#include "yaRacingScene.h"
#include "yaRacingBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaCharacter01.h"
#include "yaTransform.h"
#include "yaTime.h"

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
#include "yaRacingB01.h"

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
	RacingScene::RacingScene()
	{

	}
	RacingScene::~RacingScene()
	{

	}

	void RacingScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<RacingBackGround>(eLayerType::BG);

	}

	void RacingScene::Update()
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

				if ((910.f <= mousPos.x && mousPos.x <= 980.f) && (799.f <= mousPos.y && mousPos.y <= 837.f))
				{
					if (mWinner != -1)
					{
						mB01 = object::Instantiate<RacingB01>(Vector2(954.f, 860.f), eLayerType::UI);

						ya::object::Destory(mCh01);
						ya::object::Destory(mCh02);
						ya::object::Destory(mCh03);
						ya::object::Destory(mCh04);
						ya::object::Destory(mCh05);

						ya::object::Destory(mCh01F);
						ya::object::Destory(mCh02F);
						ya::object::Destory(mCh03F);
						ya::object::Destory(mCh04F);
						ya::object::Destory(mCh05F);

						if (mNumOb != nullptr)
						{
							ya::object::Destory(mNumOb);
						}
						if (mWinOb != nullptr)
						{
							ya::object::Destory(mWinOb);
						}

						mTime = 0.0f;
						mNumber = -1; mNumOb = nullptr;
						mWinner = -1; mWinOb = nullptr;

						mBenefit1 = 0.f;
						mBenefit2 = 0.f;
						mBenefit3 = 0.f;
						mBenefit4 = 0.f;
						mBenefit5 = 0.f;

						mCh01 = object::Instantiate<Character01>(Vector2(650.0f, 680.0f), eLayerType::Player);
						mCh02 = object::Instantiate<Character01>(Vector2(650.0f, 730.0f), eLayerType::Player);
						mCh03 = object::Instantiate<Character01>(Vector2(650.0f, 780.0f), eLayerType::Player);
						mCh04 = object::Instantiate<Character01>(Vector2(650.0f, 830.0f), eLayerType::Player);
						mCh05 = object::Instantiate<Character01>(Vector2(650.0f, 880.0f), eLayerType::Player);

						Transform* tr1 = mCh01->GetComponent<Transform>();	tr1->SetScale(Vector2(0.5f, 0.5f));
						Transform* tr2 = mCh02->GetComponent<Transform>();	tr2->SetScale(Vector2(0.5f, 0.5f));
						Transform* tr3 = mCh03->GetComponent<Transform>();	tr3->SetScale(Vector2(0.5f, 0.5f));
						Transform* tr4 = mCh04->GetComponent<Transform>();	tr4->SetScale(Vector2(0.5f, 0.5f));
						Transform* tr5 = mCh05->GetComponent<Transform>();	tr5->SetScale(Vector2(0.5f, 0.5f));

						mCh01F = object::Instantiate<F_1>(Vector2(650.0f, 540.0f), eLayerType::UI);
						mCh02F = object::Instantiate<F_2>(Vector2(650.0f, 590.0f), eLayerType::UI);
						mCh03F = object::Instantiate<F_3>(Vector2(650.0f, 640.0f), eLayerType::UI);
						mCh04F = object::Instantiate<F_4>(Vector2(650.0f, 690.0f), eLayerType::UI);
						mCh05F = object::Instantiate<F_5>(Vector2(650.0f, 740.0f), eLayerType::UI);
					}
				}

				if (mNumber == -1)
				{
					if ((543.f <= mousPos.x && mousPos.x <= 611.f) && (463.f <= mousPos.y && mousPos.y <= 513.f))
					{
						mNumber = 1; mBenefit1 = 3.f; MainScene::mSilver -= 1000;
					}
					if ((543.f <= mousPos.x && mousPos.x <= 611.f) && (520.f <= mousPos.y && mousPos.y <= 560.f))
					{
						mNumber = 2; mBenefit2 = 3.f; MainScene::mSilver -= 1000;
					}
					if ((543.f <= mousPos.x && mousPos.x <= 611.f) && (568.f <= mousPos.y && mousPos.y <= 609.f))
					{
						mNumber = 3; mBenefit3 = 3.f; MainScene::mSilver -= 1000;
					}
					if ((543.f <= mousPos.x && mousPos.x <= 611.f) && (619.f <= mousPos.y && mousPos.y <= 660.f))
					{
						mNumber = 4; mBenefit4 = 3.f; MainScene::mSilver -= 1000;
					}
					if ((543.f <= mousPos.x && mousPos.x <= 611.f) && (670.f <= mousPos.y && mousPos.y <= 721.f))
					{
						mNumber = 5; mBenefit5 = 3.f; MainScene::mSilver -= 1000;
					}
				}
			}

			if (mNumber != -1 && mNumOb == nullptr)
			{
				if (mNumOb != nullptr)
					object::Destory(mNumOb);

				//mNumOb = nullptr;

				std::string tempChar = std::to_string(mNumber);
#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar[0] == '0')
				{
					mNumOb = object::Instantiate<F_0>(Vector2(660.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '1')
				{
					mNumOb = object::Instantiate<F_1>(Vector2(660.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '2')
				{
					mNumOb = object::Instantiate<F_2>(Vector2(660.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '3')
				{
					mNumOb = object::Instantiate<F_3>(Vector2(660.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '4')
				{
					mNumOb = object::Instantiate<F_4>(Vector2(660.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '5')
				{
					mNumOb = object::Instantiate<F_5>(Vector2(660.f, 225.0f), eLayerType::UI);
				}

				Transform* tr = mNumOb->GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));
#pragma endregion
			}

			if (mWinner != -1 && mWinOb == nullptr)
			{
				if (mWinOb != nullptr)
					object::Destory(mWinOb);

				//mNumOb = nullptr;

				std::string tempChar = std::to_string(mWinner);
#pragma region 문자에 맞는 해당 이미지 생성
				if (tempChar[0] == '0')
				{
					mWinOb = object::Instantiate<F_0>(Vector2(926.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '1')
				{
					mWinOb = object::Instantiate<F_1>(Vector2(926.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '2')
				{
					mWinOb = object::Instantiate<F_2>(Vector2(926.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '3')
				{
					mWinOb = object::Instantiate<F_3>(Vector2(926.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '4')
				{
					mWinOb = object::Instantiate<F_4>(Vector2(926.f, 225.0f), eLayerType::UI);
				}
				if (tempChar[0] == '5')
				{
					mWinOb = object::Instantiate<F_5>(Vector2(926.f, 225.0f), eLayerType::UI);
				}

				Transform* tr = mWinOb->GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));
#pragma endregion
			}


			if (mNumber != -1)
			{
				mTime += Time::DeltaTime();
			}

			Transform* tr = mCh01->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			if (pos.x > 1070.f)
			{
				mWinner = 1;
				mTime = 0.0f;

				if (mNumber == 1)
				{
					MainScene::mSilver += 5000;
					mNumber = -1;
				}
			}

			tr = mCh02->GetComponent<Transform>();
			pos = tr->GetPos();
			if (pos.x > 1070.f)
			{
				mWinner = 2;
				mTime = 0.0f;

				if (mNumber == 2)
				{
					MainScene::mSilver += 5000;
					mNumber = -1;
				}
			}

			tr = mCh03->GetComponent<Transform>();
			pos = tr->GetPos();
			if (pos.x > 1070.f)
			{
				mWinner = 3;
				mTime = 0.0f;

				if (mNumber == 3)
				{
					MainScene::mSilver += 5000;
					mNumber = -1;
				}
			}

			tr = mCh04->GetComponent<Transform>();
			pos = tr->GetPos();
			if (pos.x > 1070.f)
			{
				mWinner = 4;
				mTime = 0.0f;

				if (mNumber == 4)
				{
					MainScene::mSilver += 5000;
					mNumber = -1;
				}
			}

			tr = mCh05->GetComponent<Transform>();
			pos = tr->GetPos();
			if (pos.x > 1070.f)
			{
				mWinner = 5;
				mTime = 0.0f;

				if (mNumber == 5)
				{
					MainScene::mSilver += 5000;
					mNumber = -1;
				}
			}

			if (mTime > 2.0f)
			{
				srand(time(NULL));
				int tempValue = rand() % 3 + 1;// 1~3
				if (tempValue == 1)
				{
					Transform* tr = mCh01->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (10.0f + mBenefit1) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 2)
				{
					Transform* tr = mCh01->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (30.0f + mBenefit1) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 3)
				{
					Transform* tr = mCh01->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (50.0f + mBenefit1) * Time::DeltaTime();
					tr->SetPos(pos);
				}

				Transform* tr = mCh01->GetComponent<Transform>();
				Vector2 pos = tr->GetPos(); pos.y = 540.0f;

				Transform* trr = mCh01F->GetComponent<Transform>();
				trr->SetPos(pos);
			}

			if (mTime > 2.0f)
			{
				//srand(time(NULL));
				int tempValue = rand() % 3 + 1;// 1~3
				if (tempValue == 1)
				{
					Transform* tr = mCh02->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (10.0f + mBenefit2) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 2)
				{
					Transform* tr = mCh02->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (30.0f + mBenefit2) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 3)
				{
					Transform* tr = mCh02->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (50.0f + mBenefit2) * Time::DeltaTime();
					tr->SetPos(pos);
				}

				Transform* tr = mCh02->GetComponent<Transform>();
				Vector2 pos = tr->GetPos(); pos.y = 590.0f;

				Transform* trr = mCh02F->GetComponent<Transform>();
				trr->SetPos(pos);
			}

			if (mTime > 2.0f)
			{
				//srand(time(NULL));
				int tempValue = rand() % 3 + 1;// 1~3
				if (tempValue == 1)
				{
					Transform* tr = mCh03->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (10.0f + mBenefit3) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 2)
				{
					Transform* tr = mCh03->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (30.0f + mBenefit3) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 3)
				{
					Transform* tr = mCh03->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (50.0f + mBenefit3) * Time::DeltaTime();
					tr->SetPos(pos);
				}

				Transform* tr = mCh03->GetComponent<Transform>();
				Vector2 pos = tr->GetPos(); pos.y = 640.0f;

				Transform* trr = mCh03F->GetComponent<Transform>();
				trr->SetPos(pos);
			}

			if (mTime > 2.0f)
			{
				//srand(time(NULL));
				int tempValue = rand() % 3 + 1;// 1~3
				if (tempValue == 1)
				{
					Transform* tr = mCh04->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (10.0f + mBenefit4) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 2)
				{
					Transform* tr = mCh04->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (30.0f + mBenefit4) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 3)
				{
					Transform* tr = mCh04->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (50.0f + mBenefit4) * Time::DeltaTime();
					tr->SetPos(pos);
				}

				Transform* tr = mCh04->GetComponent<Transform>();
				Vector2 pos = tr->GetPos(); pos.y = 690.0f;

				Transform* trr = mCh04F->GetComponent<Transform>();
				trr->SetPos(pos);
			}

			if (mTime > 2.0f)
			{
				//srand(time(NULL));
				int tempValue = rand() % 3 + 1;// 1~3
				if (tempValue == 1)
				{
					Transform* tr = mCh05->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (10.0f + mBenefit5) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 2)
				{
					Transform* tr = mCh05->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (30.0f + mBenefit5) * Time::DeltaTime();
					tr->SetPos(pos);
				}
				else if (tempValue == 3)
				{
					Transform* tr = mCh05->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += (50.0f + mBenefit5) * Time::DeltaTime();
					tr->SetPos(pos);
				}

				Transform* tr = mCh05->GetComponent<Transform>();
				Vector2 pos = tr->GetPos(); pos.y = 740.0f;

				Transform* trr = mCh05F->GetComponent<Transform>();
				trr->SetPos(pos);
			}
		}

		if (Input::GetKeyUp(eKeyCode::LBUTTON))
		{
			if (mB01 != nullptr)
			{
				object::Destory(mB01);
			}
		}

		Scene::Update();
	}

	void RacingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void RacingScene::Release()
	{
		Scene::Release();
	}

	void RacingScene::OnEnter()
	{
		mTime = 0.0f;
		mNumber = -1; mNumOb = nullptr;
		mWinner = -1; mWinOb = nullptr;

		mBenefit1 = 0.f;
		mBenefit2 = 0.f;
		mBenefit3 = 0.f;
		mBenefit4 = 0.f;
		mBenefit5 = 0.f;
	
		mCh01 = object::Instantiate<Character01>(Vector2(650.0f, 680.0f), eLayerType::Player);
		mCh02 = object::Instantiate<Character01>(Vector2(650.0f, 730.0f), eLayerType::Player);
		mCh03 = object::Instantiate<Character01>(Vector2(650.0f, 780.0f), eLayerType::Player);
		mCh04 = object::Instantiate<Character01>(Vector2(650.0f, 830.0f), eLayerType::Player);
		mCh05 = object::Instantiate<Character01>(Vector2(650.0f, 880.0f), eLayerType::Player);

		Transform* tr1 = mCh01->GetComponent<Transform>();	tr1->SetScale(Vector2(0.5f, 0.5f));
		Transform* tr2 = mCh02->GetComponent<Transform>();	tr2->SetScale(Vector2(0.5f, 0.5f));
		Transform* tr3 = mCh03->GetComponent<Transform>();	tr3->SetScale(Vector2(0.5f, 0.5f));
		Transform* tr4 = mCh04->GetComponent<Transform>();	tr4->SetScale(Vector2(0.5f, 0.5f));
		Transform* tr5 = mCh05->GetComponent<Transform>();	tr5->SetScale(Vector2(0.5f, 0.5f));

		mCh01F = object::Instantiate<F_1>(Vector2(650.0f, 540.0f), eLayerType::UI);
		mCh02F = object::Instantiate<F_2>(Vector2(650.0f, 590.0f), eLayerType::UI);
		mCh03F = object::Instantiate<F_3>(Vector2(650.0f, 640.0f), eLayerType::UI);
		mCh04F = object::Instantiate<F_4>(Vector2(650.0f, 690.0f), eLayerType::UI);
		mCh05F = object::Instantiate<F_5>(Vector2(650.0f, 740.0f), eLayerType::UI);

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

	void RacingScene::OnExit()
	{
		ya::object::Destory(mCh01);
		ya::object::Destory(mCh02);
		ya::object::Destory(mCh03);
		ya::object::Destory(mCh04);
		ya::object::Destory(mCh05);

		ya::object::Destory(mCh01F);
		ya::object::Destory(mCh02F);
		ya::object::Destory(mCh03F);
		ya::object::Destory(mCh04F);
		ya::object::Destory(mCh05F);

		if (mNumOb != nullptr)
		{
			ya::object::Destory(mNumOb);
		}
		if (mWinOb != nullptr)
		{
			ya::object::Destory(mWinOb);
		}

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