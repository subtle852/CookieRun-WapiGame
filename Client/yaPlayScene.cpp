#include "yaPlayScene.h"
#include "yaCharacter01.h"
#include "yaPet01.h"
#include "yaPlayBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"
#include "yaTime.h"

#include "yaCoin_Silver.h"
#include "yaBlackOutMItem.h"
#include "yaShakeItem.h"
#include "yaSmItem.h"
#include "yaBigItem.h"
#include "yaFastItem.h"
#include "yaSlowItem.h"
#include "yaHpItemI.h"
#include "yaHpItemD.h"
#include "yaObstacleToCoin.h"
#include "yaBasicToBear.h"
#include "yaMagnetItem.h"
#include "yaInputEItem.h"
#include "yaInvincibleItem.h"

#include "yaJumpButton.h"
#include "yaSlideButton.h"
#include "yaPauseButton.h"
#include "yaGaugeCircle.h"
#include "yaGaugeBar.h"
#include "yaGround.h"
#include "yaUnderGround.h"
#include "yaOverGround.h"

#include "yaSelectCharScene.h"
#include "yaMakeScene.h"
#include "yaMainScene.h"

//////////////////////////////////////////////////////////////
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaTime.h"
#include "yaToolScene.h"

#include "yaCharacter01.h"
#include "yaCharacter02.h"
#include "yaCharacter03.h"
#include "yaCharacter04.h"
#include "yaCharacter05.h"
#include "yaStraw_Jelly.h"
#include "yaCharacter06.h"
#include "yaCharacter07.h"
#include "yaDevil_Jelly.h"
#include "yaCharacter08.h"

//Common
#include "yaGround.h"
#include "yaOverGround.h"'
#include "yaFlag.h"
#include "yaUnderGround.h"

// Active Item
#include "yaBasicToBear.h"
#include "yaBigItem.h"
#include "yaBlackOutMItem.h"
#include "yaFastItem.h"
#include "yaHpItemI.h"
#include "yaHpItemD.h"
#include "yaInputEItem.h"
#include "yaInvincibleItem.h"
#include "yaMagnetItem.h"
#include "yaObstacleToCoin.h"
#include "yaSmItem.h"

// Bear Item
#include "yaBear_Big.h"
#include "yaBear_FlyingPink.h"
#include "yaBear_FlyingYellow.h"
#include "yaBear_Rainbow.h"
#include "yaBear_SmallBlue.h"
#include "yaBear_SmallPink.h"
#include "yaBear_SmallYellow.h"
#include "yaBear_StarBlue.h"
#include "yaBear_StarYellow.h"

// Coin Item
#include "yaCoin_Gold.h"
#include "yaCoin_GoldB.h"
#include "yaCoin_Silver.h"
#include "yaCoin_SilverB.h"

// Basic Item
#include "yaBasic_Candy_B.h"
#include "yaBasic_Candy_G.h"
#include "yaBasic_Candy_M1.h"
#include "yaBasic_Candy_M2.h"
#include "yaBasic_Candy_R.h"
#include "yaBasic_Candy_Y.h"

#include "yaBasic_Gummy_B.h"
#include "yaBasic_Gummy_G.h"
#include "yaBasic_Gummy_M1.h"
#include "yaBasic_Gummy_M2.h"
#include "yaBasic_Gummy_R.h"
#include "yaBasic_Gummy_Y.h" // 0 ~ 38

// Tile OT말고 GT는 y좌표 고정하면 될듯(단, 타일마다 y위치 다른 경우 존재하니 맞춰서 타일그림 편집)
#include "yaL1_GT01.h"
#include "yaL1_GT02.h"
#include "yaL1_GT03.h"

#include "yaL1_OT01.h"
#include "yaL1_OT02.h"
#include "yaL1_OT03.h"

// Obstacle 
#include "yaL1_JP01.h"
#include "yaL1_JP02.h"
#include "yaL1_JP03.h"
#include "yaL1_JP04.h"
#include "yaL1_JP05.h"
#include "yaL1_JP06.h"

#include "yaL1_DP01.h"
#include "yaL1_DP02.h"
#include "yaL1_DP03.h"
#include "yaL1_DP04.h"
#include "yaL1_DP05.h"
#include "yaL1_DP06.h"

#include "yaL1_SL01.h"
#include "yaL1_SL02.h"
#include "yaL1_SL03.h"
#include "yaL1_SL04.h"
#include "yaL1_SL05.h"
#include "yaL1_SL06.h"

#include "yaObstacle.h"
#include "yaObstacle01.h"

// Effect
#include "yaEatEffect.h"
#include "yaCloudEffect.h"

// BG
#include "yaL1_BG01.h"
#include "yaL1_BG02.h"

// BonusTime
#include "yaBonus_01_B.h"
#include "yaBonus_02_O.h"
#include "yaBonus_03_N.h"
#include "yaBonus_04_U.h"
#include "yaBonus_05_S.h"
#include "yaBonus_06_T.h"
#include "yaBonus_07_I.h"
#include "yaBonus_08_M.h"
#include "yaBonus_09_E.h"

#include "yaBonusUI.h"

#include "yaBonus_UI_01_B.h"
#include "yaBonus_UI_02_O.h"
#include "yaBonus_UI_03_N.h"
#include "yaBonus_UI_04_U.h"
#include "yaBonus_UI_05_S.h"
#include "yaBonus_UI_06_T.h"
#include "yaBonus_UI_07_I.h"
#include "yaBonus_UI_08_M.h"
#include "yaBonus_UI_09_E.h"

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

#include "yaPlay_Silver.h"
#include "yaPlay_Score.h"

#include "yaSound.h"
#include "yaResources.h"

#include "yaBonusBackGround.h"

namespace ya
{
	Character01* PlayScene::mCh01 = nullptr;
	bool PlayScene::mCloudEffectOnatPlay = false;
	bool PlayScene::mBonusState[9] = { 0,0,0,0,0,0,0,0,0 };

	int PlayScene::mSilver = 0;
	int PlayScene::mScore = 0;

	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		//mCh00 =
		//object::Instantiate<Character01>(eLayerType::Player);
		//Camera::SetTarget(mCh01);

		Scene::Initialize();

		// 여기다
		object::Instantiate<L1_BG01>(eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(500.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(3238.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(5976.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(8714.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(11452.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(14190.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(16928.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(19666.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(22404.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(25142.0f, 370.0f), eLayerType::BG);


		object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground, Vector2(1000.0f, 50.0f));
		object::Instantiate<UnderGround>(Vector2(-100.0f, 890.0f), eLayerType::Ground);


		// UI라서 직접 선언해야함
		object::Instantiate<GaugeCircle>(Vector2(-10.0f, 20.0f), eLayerType::UIAbove);
		object::Instantiate<GaugeBar>(Vector2(59.0f, 32.0f), eLayerType::UI);

		object::Instantiate<JumpButton>(Vector2(100.0f, 650.0f), eLayerType::UI);
		object::Instantiate<SlideButton>(Vector2(1200.0f, 650.0f), eLayerType::UI);
		object::Instantiate<PauseButton>(Vector2(1480.0f, 40.0f), eLayerType::UI);

	}

	void PlayScene::Update()
	{
		if (GetFocus())
		{
			if (Input::GetKeyDown(eKeyCode::SPACE))
			{
				mOnInv = true;
			}
		}
		if (mOnInv == true)
		{
			Character08::mCurHp = 100;
		}

		// 점수, 은화 UI
		for (auto i = 0; i < 6; i++)
		{
			if (mObs_[i] != nullptr)
				object::Destory(mObs_[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs_[i] = nullptr;
		}

		std::string temp = std::to_string(PlayScene::mSilver);
		int size = temp.size();
		int totalSize = 5;

		//float tempPos = 1355.f + 22.0f * (totalSize - size + 1);

		for (auto i = 0; i < size; i++)
		{
			Transform* tr = mCh01->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			//float tempPos = pos.x + 950.f + 22.0f * (totalSize - size + 1);
			float tempPos = pos.x + 950.f;

			char tempChar = temp[i];
#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs_[i] = object::Instantiate<F_0>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs_[i] = object::Instantiate<F_1>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs_[i] = object::Instantiate<F_2>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs_[i] = object::Instantiate<F_3>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs_[i] = object::Instantiate<F_4>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs_[i] = object::Instantiate<F_5>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs_[i] = object::Instantiate<F_6>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs_[i] = object::Instantiate<F_7>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs_[i] = object::Instantiate<F_8>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs_[i] = object::Instantiate<F_9>(Vector2(tempPos + (i * 22.0f), 100.0f), eLayerType::UI);
			}
#pragma endregion
		}
		//
		for (auto i = 0; i < 6; i++)
		{
			if (mObs2_[i] != nullptr)
				object::Destory(mObs2_[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs2_[i] = nullptr;
		}

		std::string temp2 = std::to_string(PlayScene::mScore);
		int size2 = temp2.size();
		int totalSize2 = 5;

		//float tempPos2 = 1110.f + 22.0f * (totalSize2 - size2 + 1);

		for (auto i = 0; i < size2; i++)
		{
			Transform* tr = mCh01->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			//float tempPos2 = pos.x + 950.f + 22.0f * (totalSize - size + 1);
			float tempPos2 = pos.x + 950.f;

			char tempChar = temp2[i];
#pragma region 문자에 맞는 해당 이미지 생성
			if (tempChar == '0')
			{
				mObs2_[i] = object::Instantiate<F_0>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '1')
			{
				mObs2_[i] = object::Instantiate<F_1>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '2')
			{
				mObs2_[i] = object::Instantiate<F_2>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '3')
			{
				mObs2_[i] = object::Instantiate<F_3>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '4')
			{
				mObs2_[i] = object::Instantiate<F_4>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '5')
			{
				mObs2_[i] = object::Instantiate<F_5>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '6')
			{
				mObs2_[i] = object::Instantiate<F_6>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '7')
			{
				mObs2_[i] = object::Instantiate<F_7>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '8')
			{
				mObs2_[i] = object::Instantiate<F_8>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
			if (tempChar == '9')
			{
				mObs2_[i] = object::Instantiate<F_9>(Vector2(tempPos2 + (i * 22.0f), 150.0f), eLayerType::UI);
			}
#pragma endregion
		}

		// bonus UI
		//for (auto i = 0; i < 9; i++)
		//{
		//	if (mBonusUIs[i] != nullptr)
		//		object::Destory(mBonusUIs[i]);
		//}
		//for (auto i = 0; i < 9; i++)
		//{
		//	mBonusUIs[i] = nullptr;
		//}

		if (mBonusState[0] == 1 && mBonusUIs[0] == nullptr)
		{
			mBonusUIs[0] = object::Instantiate<Bonus_UI_01_B>(Vector2(208.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[1] == 1 && mBonusUIs[1] == nullptr)
		{
			mBonusUIs[1] = object::Instantiate<Bonus_UI_02_O>(Vector2(255.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[2] == 1 && mBonusUIs[2] == nullptr)
		{
			mBonusUIs[2] = object::Instantiate<Bonus_UI_03_N>(Vector2(305.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[3] == 1 && mBonusUIs[3] == nullptr)
		{
			mBonusUIs[3] = object::Instantiate<Bonus_UI_04_U>(Vector2(355.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[4] == 1 && mBonusUIs[4] == nullptr)
		{
			mBonusUIs[4] = object::Instantiate<Bonus_UI_05_S>(Vector2(406.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[5] == 1 && mBonusUIs[5] == nullptr)
		{
			mBonusUIs[5] = object::Instantiate<Bonus_UI_06_T>(Vector2(456.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[6] == 1 && mBonusUIs[6] == nullptr)
		{
			mBonusUIs[6] = object::Instantiate<Bonus_UI_07_I>(Vector2(500.0f, 108.0f), eLayerType::UI);
		}
		if (mBonusState[7] == 1 && mBonusUIs[7] == nullptr)
		{
			mBonusUIs[7] = object::Instantiate<Bonus_UI_08_M>(Vector2(545.0f, 106.0f), eLayerType::UI);
		}
		if (mBonusState[8] == 1 && mBonusUIs[8] == nullptr)
		{
			mBonusUIs[8] = object::Instantiate<Bonus_UI_09_E>(Vector2(600.0f, 106.0f), eLayerType::UI);
		}

		//

		Transform* tr = mCh01->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		Transform* trr = mPet01->GetComponent<Transform>();
		trr->SetPos(Vector2(pos.x - 120.0f, pos.y - 0.0f));

		#pragma region 아이템 효과 적용
		if (PlayScene::mCloudEffectOnatPlay == true)// 구름 이펙트
		{
			mCloudEffectTime += Time::DeltaTime();

			if (mCloudEffect == nullptr)
			{
				mCloudEffect = object::Instantiate<CloudEffect>(Vector2(300.0f, -500.0f), eLayerType::Effect);
			}

			Transform* tr = mCh01->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			Transform* tre = mCloudEffect->GetComponent<Transform>();
			tre->SetPos(Vector2(pos.x + 550.0f, 650.0f - 200.0f));

			if (mCloudEffectTime > 2.0f)
			{
				object::Destory(mCloudEffect);
				mCloudEffect = nullptr;
				mCloudEffectTime = 0.0f;
				PlayScene::mCloudEffectOnatPlay = false;
			}
		}

		if (mCh01->mMagnetState == true)// 자석 아이템
		{
			mMagnetTime += Time::DeltaTime(); // 모든 아이템들에 캐릭쪽으로 오는 논리 적용시켜야함

			if (mMagnetTime > mMagnetFull)
			{
				mMagnetTime = 0.0f;
				mCh01->mMagnetState = false;
			}

			std::unordered_map<UINT64, GameObject*>::iterator iter = mObs.begin();
			for (; iter != mObs.end(); iter++)
			{
				TilePos id;
				id.id = iter->first;

				Transform* tr = mCh01->GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				MakeScene::mChPos = pos;

				if (pos.x < id.x && id.x < pos.x + 400.0f)
				{
					GameObject* temp = iter->second;
					temp->mMagnet = true;
				}
				if (pos.x - 300.f < id.x && id.x < pos.x + 50.f)
				{
					GameObject* temp = iter->second;
					temp->mMagnetError = true;
				}
			}
		}

		std::unordered_map<UINT64, GameObject*>::iterator iter = mObs.begin();
		for (; iter != mObs.end(); iter++)
		{
			TilePos id;
			id.id = iter->first;

			Transform* tr = mCh01->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			MakeScene::mChPos = pos;

			if (pos.x - 300.f < id.x && id.x < pos.x + 50.f)
			{
				GameObject* temp = iter->second;
				if (temp->mMagnet == true)
				{
					temp->mMagnetError = true;
				}
			}
		}

		if (mCh01->mBtoB == true && SelectCharScene::GetCharNumber() != 5)// Basic To Jelly 아이템
		{
			std::unordered_map<UINT64, GameObject*>::iterator iter = mBasicJelly.begin();
			for (; iter != mBasicJelly.end(); iter++)
			{
				if (iter == --mBasicJelly.end())
				{
					mCh01->mBtoB = false;
				}

				TilePos id;
				id.id = iter->first;

				GameObject* temp = iter->second;

				Transform* tr = mCh01->GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				if (pos.x + 50.f < id.x && id.x < pos.x + mBtoBFull)
				{
					std::unordered_map<UINT64, UINT64>::iterator temp = mTiles.find(id.id);
					UINT64 indexTemp = temp->second;

					ya::object::Destory(iter->second);
					mObs.erase(id.id);
					mTiles.erase(id.id);

					mOb = object::Instantiate<Bear_FlyingPink>(Vector2(id.x, id.y), eLayerType::Item);

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, indexTemp));
					//mBearJelly.insert(std::make_pair(id.id, mOb));// no need
				}
			}
		}

		if (mCh01->mOtoC == true)// Obstacle To Coin 아이템
		{
			//mOtoCTime += Time::DeltaTime();
			int tempToclear = 0;

			//if (mOtoCend == false && mOtoCTime <= 1.0f)
			{
				std::unordered_map<UINT64, GameObject*>::iterator iter = mObstacle.begin();
				for (; iter != mObstacle.end(); iter++)
				{
					TilePos id;
					id.id = iter->first;

					GameObject* temp = iter->second;

					Transform* tr = mCh01->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					if (pos.x < id.x && id.x < pos.x + 600.f)
					{
						std::unordered_map<UINT64, UINT64>::iterator temp = mTiles.find(id.id);
						UINT64 indexTemp = temp->second;

						ya::object::Destory(iter->second);
						mObs.erase(id.id);
						mTiles.erase(id.id);

						mOb = object::Instantiate<Coin_Silver>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, indexTemp));
						mCoin.insert(std::make_pair(id.id, mOb));
					}

					if (iter == --mObstacle.end())
					{
						//tempToclear = 1;
						mOtoCend2 = false;
						//mOtoCend = true;
						mCh01->mOtoC = false;
					}
				}

				//if (tempToclear == 1)
				//{
				//	mObstacle.clear();
				//}
			}
		}
		#pragma endregion

		//if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		//{
		//	//SceneManager::LoadScene(eSceneType::ResultS);
		//	SceneManager::LoadScene(eSceneType::Make);
		//}

		if (Input::GetKeyState(eKeyCode::V) == eKeyState::Down)
		{
			mBGM->Stop(true);
			SceneManager::LoadScene(eSceneType::ResultF);
		}
		if (Input::GetKeyState(eKeyCode::C) == eKeyState::Down)
		{
			mBGM->Stop(true);
			SceneManager::LoadScene(eSceneType::ResultS);
		}

		for (int i = 0; i < 9; i++)
		{
			if (PlayScene::mBonusState[i] == 1)
			{
				mBonusSum += 1;
			}

			if (i == 8)
			{
				if (mBonusSum == 9)
				{
					mToBonus = true;
					mBonusWait += Time::DeltaTime();

					if (mBonusWait > 0.05f)
					{	
						mNoReset = true;
						SceneManager::LoadScene(eSceneType::Bonus);
					}
				}
				else
				{
					mBonusSum = 0;
					break;
				}
			}
		}

		Scene::Update();

	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
		if (mNoReset == false)
		{
			mBGM = Resources::Load<Sound>(L"PlayTheme", L"..\\Resources\\Sound\\Play\\play_bgm.wav");
			mBGM->Play(true);
		}

		if (mFromBonus == false)
		{
			int temp = SelectCharScene::GetCharNumber();

			if (temp == 1)
			{
				mCh01 = object::Instantiate<Character01>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 2)
			{
				mCh01 = object::Instantiate<Character02>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 3)
			{
				mCh01 = object::Instantiate<Character03>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 4)
			{
				mCh01 = object::Instantiate<Character04>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 5)
			{
				mCh01 = object::Instantiate<Character05>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 6)
			{
				mCh01 = object::Instantiate<Character06>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 7)
			{
				mCh01 = object::Instantiate<Character07>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}
			else if (temp == 8)
			{
				mCh01 = object::Instantiate<Character08>(Vector2(300.0f, 650.0f), eLayerType::Player);
			}

			mPet01 = object::Instantiate<Pet01>(eLayerType::Pet);

			
			object::Instantiate<Bonus_01_B>(Vector2(1400.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_02_O>(Vector2(1500.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_03_N>(Vector2(1600.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_04_U>(Vector2(1700.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_05_S>(Vector2(1800.0f, 650.0f), eLayerType::Item);
			
			object::Instantiate<Bonus_06_T>(Vector2(5400.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_07_I>(Vector2(5500.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_08_M>(Vector2(5600.0f, 650.0f), eLayerType::Item);
			object::Instantiate<Bonus_09_E>(Vector2(5700.0f, 650.0f), eLayerType::Item);

#pragma region Load
			{
				wchar_t szFilePath[256] = L"..\\Resources\\Stage04";
				FILE* file = nullptr;
				_wfopen_s(&file, szFilePath, L"rb");

				if (file == nullptr)
					return;

				while (true)
				{
					TileInd id2;
					id2.ind = -1;
					//int index = -1;
					//TilePos id;

					if (fread(&id2.id2, sizeof(TileInd), 1, file) == NULL)
						break;

					if (fread(&id.id, sizeof(TilePos), 1, file) == NULL)
						break;


					if (id2.ind == 0)
					{
						mOb = object::Instantiate<Ground>(Vector2(id.x, id.y), eLayerType::Ground, Vector2((float)id2.width, 50.0f));
						mObs.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 1)
					{
						mOb = object::Instantiate<OverGround>(Vector2(id.x, id.y), eLayerType::Ground, Vector2((float)id2.width, 50.0f));
						mObs.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 2)
					{
						mOb = object::Instantiate<Flag>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					}
					if (id2.ind == 8)
					{
						mOb = object::Instantiate<FastItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 9)
					{
						mOb = object::Instantiate<BigItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 10)
					{
						mOb = object::Instantiate<SmItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 11)
					{
						mOb = object::Instantiate<BlackOutMItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 12)
					{
						mOb = object::Instantiate<HpItemI>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 13)
					{
						mOb = object::Instantiate<HpItemD>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 14)
					{
						mOb = object::Instantiate<InvincibleItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 15)
					{
						mOb = object::Instantiate<InputEItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 16)
					{
						mOb = object::Instantiate<BasicToBear>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 17)
					{
						mOb = object::Instantiate<ObstacleToCoin>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 18)
					{
						mOb = object::Instantiate<MagnetItem>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}

					////////////////////////////////////////////////////////////////////////////////////////////// Bear
					if (id2.ind == 24)
					{
						mOb = object::Instantiate<Bear_Big>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 25)
					{
						mOb = object::Instantiate<Bear_FlyingPink>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 26)
					{
						mOb = object::Instantiate<Bear_FlyingYellow>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 27)
					{
						mOb = object::Instantiate<Bear_Rainbow>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 28)
					{
						mOb = object::Instantiate<Bear_SmallBlue>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 29)
					{
						mOb = object::Instantiate<Bear_SmallPink>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 30)
					{
						mOb = object::Instantiate<Bear_SmallYellow>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 32)
					{
						mOb = object::Instantiate<Bear_StarBlue>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 33)
					{
						mOb = object::Instantiate<Bear_StarYellow>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}

					////////////////////////////////////////////////////////////////////////////////////////////// Coin
					if (id2.ind == 36)
					{
						mOb = object::Instantiate<Coin_Gold>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 37)
					{
						mOb = object::Instantiate<Coin_GoldB>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 38)
					{
						mOb = object::Instantiate<Coin_Silver>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 39)
					{
						mOb = object::Instantiate<Coin_SilverB>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}

					/////////////////////////////////////////////////////////////////////////////////////////////// Basic
					//if (ToolScene::mIndex == 32)
					//{
					//	mOb = object::Instantiate<Basic_Candy_B>(Vector2(pos.x, pos.y), eLayerType::Item);

					//	int index = ToolScene::mIndex;
					//	id2.ind = (UINT32)index;
					//	//TilePos id;
					//	id.x = (UINT32)pos.x;
					//	id.y = (UINT32)pos.y;

					//	mObs.insert(std::make_pair(id.id, mOb));
					//	mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					//	mBasicJelly.insert(std::make_pair(id.id, mOb));
					//}
					//if (ToolScene::mIndex == 33)
					//{
					//	mOb = object::Instantiate<Basic_Candy_G>(Vector2(pos.x, pos.y), eLayerType::Item);

					//	int index = ToolScene::mIndex;
					//	id2.ind = (UINT32)index;
					//	//TilePos id;
					//	id.x = (UINT32)pos.x;
					//	id.y = (UINT32)pos.y;

					//	mObs.insert(std::make_pair(id.id, mOb));
					//	mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					//	mBasicJelly.insert(std::make_pair(id.id, mOb));
					//}
					//if (ToolScene::mIndex == 34)
					//{
					//	mOb = object::Instantiate<Basic_Candy_R>(Vector2(pos.x, pos.y), eLayerType::Item);

					//	int index = ToolScene::mIndex;
					//	id2.ind = (UINT32)index;
					//	//TilePos id;
					//	id.x = (UINT32)pos.x;
					//	id.y = (UINT32)pos.y;

					//	mObs.insert(std::make_pair(id.id, mOb));
					//	mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					//	mBasicJelly.insert(std::make_pair(id.id, mOb));
					//}
					//if (ToolScene::mIndex == 35)
					//{
					//	mOb = object::Instantiate<Basic_Candy_Y>(Vector2(pos.x, pos.y), eLayerType::Item);

					//	int index = ToolScene::mIndex;
					//	id2.ind = (UINT32)index;
					//	//TilePos id;
					//	id.x = (UINT32)pos.x;
					//	id.y = (UINT32)pos.y;

					//	mObs.insert(std::make_pair(id.id, mOb));
					//	mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					//	mBasicJelly.insert(std::make_pair(id.id, mOb));
					//}
					//if (ToolScene::mIndex == 36)
					//{
					//	mOb = object::Instantiate<Basic_Candy_M1>(Vector2(pos.x, pos.y), eLayerType::Item);

					//	int index = ToolScene::mIndex;
					//	id2.ind = (UINT32)index;
					//	//TilePos id;
					//	id.x = (UINT32)pos.x;
					//	id.y = (UINT32)pos.y;

					//	mObs.insert(std::make_pair(id.id, mOb));
					//	mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					//	mBasicJelly.insert(std::make_pair(id.id, mOb));
					//}
					//if (ToolScene::mIndex == 37)
					//{
					//	mOb = object::Instantiate<Basic_Candy_M2>(Vector2(pos.x, pos.y), eLayerType::Item);

					//	int index = ToolScene::mIndex;
					//	id2.ind = (UINT32)index;
					//	//TilePos id;
					//	id.x = (UINT32)pos.x;
					//	id.y = (UINT32)pos.y;

					//	mObs.insert(std::make_pair(id.id, mOb));
					//	mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
					//	mBasicJelly.insert(std::make_pair(id.id, mOb));
					//}
					if (id2.ind == 40)
					{
						mOb = object::Instantiate<Basic_Gummy_B>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mBasicJelly.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 41)
					{
						mOb = object::Instantiate<Basic_Gummy_G>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mBasicJelly.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 42)
					{
						mOb = object::Instantiate<Basic_Gummy_R>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mBasicJelly.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 43)
					{
						mOb = object::Instantiate<Basic_Gummy_Y>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mBasicJelly.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 44)
					{
						mOb = object::Instantiate<Basic_Gummy_M1>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mBasicJelly.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 45)
					{
						mOb = object::Instantiate<Basic_Gummy_M2>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mBasicJelly.insert(std::make_pair(id.id, mOb));
					}

					/////////////////////////////////////////////////////////////////////////////////////// Tile 47~
					if (id2.ind == 47)
					{
						mOb = object::Instantiate<L1_GT01>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 48)
					{
						mOb = object::Instantiate<L1_GT02>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 49)
					{
						mOb = object::Instantiate<L1_GT03>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 50)
					{
						mOb = object::Instantiate<L1_OT01>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 51)
					{
						mOb = object::Instantiate<L1_OT02>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}
					if (id2.ind == 52)
					{
						mOb = object::Instantiate<L1_OT03>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
					}

					//////////////////////////////////////////////////////////////////////////// Obstacle 55~
					if (id2.ind == 55)
					{
						mOb = object::Instantiate<L1_JP01>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 56)
					{
						mOb = object::Instantiate<L1_JP02>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 57)
					{
						mOb = object::Instantiate<L1_JP03>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 58)
					{
						mOb = object::Instantiate<L1_JP04>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 59)
					{
						mOb = object::Instantiate<L1_JP05>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 60)
					{
						mOb = object::Instantiate<L1_JP06>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 63)
					{
						mOb = object::Instantiate<L1_DP01>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 64)
					{
						mOb = object::Instantiate<L1_DP02>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 65)
					{
						mOb = object::Instantiate<L1_DP03>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 66)
					{
						mOb = object::Instantiate<L1_DP04>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 67)
					{
						mOb = object::Instantiate<L1_DP05>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 68)
					{
						mOb = object::Instantiate<L1_DP06>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 71)
					{
						mOb = object::Instantiate<L1_SL01>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 72)
					{
						mOb = object::Instantiate<L1_SL02>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 73)
					{
						mOb = object::Instantiate<L1_SL03>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 74)
					{
						mOb = object::Instantiate<L1_SL04>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 75)
					{
						mOb = object::Instantiate<L1_SL05>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
					if (id2.ind == 76)
					{
						mOb = object::Instantiate<L1_SL06>(Vector2(id.x, id.y), eLayerType::Obstacle);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, id2.ind));
						mObstacle.insert(std::make_pair(id.id, mOb));
					}
				}
			}
#pragma endregion

			// mBasicJelly 싹다 지우고 그 위치에 딸기젤리로 생성 되야함
			if (SelectCharScene::GetCharNumber() == 5)
			{
				std::unordered_map<UINT64, GameObject*>::iterator iter = mBasicJelly.begin();
				for (; iter != mBasicJelly.end(); iter++)
				{
					TilePos id;
					id.id = iter->first;

					GameObject* temp = iter->second;

					Transform* tr = mCh01->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					if (0.0f < id.x)
					{
						std::unordered_map<UINT64, UINT64>::iterator temp = mTiles.find(id.id);
						UINT64 indexTemp = temp->second;

						ya::object::Destory(iter->second);
						mObs.erase(id.id);
						mTiles.erase(id.id);

						mOb = object::Instantiate<Straw_Jelly>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, indexTemp));
						//mBearJelly.insert(std::make_pair(id.id, mOb));// no need
					}

					if (iter == --mBasicJelly.end())
					{
						mBasicJelly.clear();
						break;
					}
				}
			}

			// 천사 무한 자력 적용
			if (SelectCharScene::GetCharNumber() == 6)
			{
				mCh01->mMagnetState = true;
				mMagnetFull = 99999999999.0f;
			}

			// 악마 원혼 맵에 젤리 랜덤으로 생성
			if (SelectCharScene::GetCharNumber() == 7)
			{
				for (int i = 1; i < 300; i++)
				{
					//srand(time(NULL));
					int temp = rand() % 3;
					if (temp == 1)
					{
						TilePos id;
						id.x = 500.f * i;
						id.y = 550.f;

						mOb = object::Instantiate<Devil_Jelly>(Vector2((500.f * i), 550.f), eLayerType::Item);
						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, 0));
					}

					if (i == 299) break;
				}
			}
		}

		/// <summary>
		/// /////////////////////////////////////////////////////////////////////////////////////////
		/// </summary>
		mToBonus = false;

		Camera::SetTarget(mCh01);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);

		if (SelectCharScene::GetCharNumber() == 3)
		{
			mMagnetFull = 2.0f + (2.0f * 0.35);
			mBtoBFull = 1500.f + (1500.f * 0.35);
		}

		for (size_t i = 0; i < 9; i++)
		{
			PlayScene::mBonusState[i] = 0;
		}

		//
		for (auto i = 0; i < 6; i++)
		{
			if (mObs_[i] != nullptr)
				object::Destory(mObs_[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs_[i] = nullptr;
		}

		for (auto i = 0; i < 6; i++)
		{
			if (mObs2_[i] != nullptr)
				object::Destory(mObs2_[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs2_[i] = nullptr;
		}
		for (auto i = 0; i < 9; i++)
		{
			PlayScene::mBonusState[i] = 0;
		}
		mBonusSum = 0;
		
		//
		mToBonus = false;
		mBonusWait = 0.f;

		mSilver_ = object::Instantiate<Play_Silver>(Vector2(1180.f, 25.0f), eLayerType::UI);
		mScore_ = object::Instantiate<Play_Score>(Vector2(1180.f, 70.0f), eLayerType::UI);
		mBonusUI = object::Instantiate<BonusUI>(Vector2(200.f, 100.0f), eLayerType::UI);
	}

	void PlayScene::OnExit()
	{
		Camera::Clear();
		//ya::object::Destory(mBG);
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f }); 씬넘길때 원상복귀 시키는것

		// 모든 오브젝트들 삭제
		// 캐릭터 위치, 캐릭터 동작상태, 캐릭터 hp 등 싹다 초기화 해야함!!!
		// 맵 오브젝트 Load하는 부분 여기에 있어야 함!!!
		// 딸기, 천사, 악마 능력 초기화 하는 부분도 해줘야 함!!!
		if (mToBonus == false)
		{
			mBasicJelly.clear();
			mObstacle.clear();

			std::unordered_map<UINT64, GameObject*>::iterator iter = mObs.begin();
			for (; iter != mObs.end(); iter++)
			{
				TilePos id;
				id.id = iter->first;

				GameObject* temp = iter->second;

				ya::object::Destory(iter->second);
				mObs.erase(id.id);
				mTiles.erase(id.id);

				iter = mObs.begin();

				if (iter == --mObs.end())
				{
					mObs.clear();
					break;
				}
			}

			for (auto i = 0; i < 6; i++)
			{
				if (mObs_[i] != nullptr)
					object::Destory(mObs_[i]);
			}
			for (auto i = 0; i < 6; i++)
			{
				mObs_[i] = nullptr;
			}

			for (auto i = 0; i < 6; i++)
			{
				if (mObs2_[i] != nullptr)
					object::Destory(mObs2_[i]);
			}
			for (auto i = 0; i < 6; i++)
			{
				mObs2_[i] = nullptr;
			}
			//

			for (auto i = 0; i < 9; i++)
			{
				if (mBonusUIs[i] != nullptr)
					object::Destory(mBonusUIs[i]);
			}
			for (auto i = 0; i < 9; i++)
			{
				mBonusUIs[i] = nullptr;
			}
			for (auto i = 0; i < 9; i++)
			{
				PlayScene::mBonusState[i] = 0;
			}

			object::Destory(mSilver_);
			object::Destory(mScore_);
			object::Destory(mBonusUI);

			MainScene::mSilver += PlayScene::mSilver;
		}
		else
		{
			mFromBonus = true;
		}

		//
		for (auto i = 0; i < 6; i++)
		{
			if (mObs_[i] != nullptr)
				object::Destory(mObs_[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs_[i] = nullptr;
		}

		for (auto i = 0; i < 6; i++)
		{
			if (mObs2_[i] != nullptr)
				object::Destory(mObs2_[i]);
		}
		for (auto i = 0; i < 6; i++)
		{
			mObs2_[i] = nullptr;
		}
		//

		for (auto i = 0; i < 9; i++)
		{
			if (mBonusUIs[i] != nullptr)
				object::Destory(mBonusUIs[i]);
		}
		for (auto i = 0; i < 9; i++)
		{
			mBonusUIs[i] = nullptr;
		}
		for (auto i = 0; i < 9; i++)
		{
			PlayScene::mBonusState[i] = 0;
		}

		object::Destory(mSilver_);
		object::Destory(mScore_);
		object::Destory(mBonusUI);
	}
}