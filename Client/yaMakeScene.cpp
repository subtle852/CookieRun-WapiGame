#include "yaMakeScene.h"
#include <commdlg.h>

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

#include "yaApplication.h"
extern ya::Application application;

namespace ya
{
	Vector2 MakeScene::mChPos = Vector2::Zero;
	bool MakeScene::mEatEffectOn = false;
	bool MakeScene::mCloudEffectOn = false;

	MakeScene::MakeScene()
	{
	}

	MakeScene::~MakeScene()
	{
	}

	void MakeScene::Initialize()
	{
		Scene::Initialize();

		//object::Instantiate<L1_BG02>(Vector2(500.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG02>(Vector2(3238.0f, 370.0f), eLayerType::BG);

		object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground, Vector2(1000.0f, 50.0f));
		object::Instantiate<UnderGround>(Vector2(-100.0f, 790.0f), eLayerType::Ground);

		mCh = object::Instantiate<Character01>(Vector2(300.0f, 650.0f), eLayerType::Player);
	}

	void MakeScene::Update()
	{
		mCh->mCurHp = 100.0f;

		//if (MakeScene::mEatEffectOn == true)// 아이템 먹는 이펙트
		//{
		//	mEatEffectTime += Time::DeltaTime();

		//	if (mEatEffect == nullptr)
		//	{
		//		mEatEffect = object::Instantiate<EatEffect>(Vector2(300.0f, -500.0f), eLayerType::Effect);
		//	}

		//	Transform* tr = mCh->GetComponent<Transform>();
		//	Vector2 pos = tr->GetPos();

		//	Transform* tre = mEatEffect->GetComponent<Transform>();
		//	tre->SetPos(Vector2(pos.x + 85.0f, pos.y - 20.0f));

		//	if (mEatEffectTime > 1.0f)
		//	{
		//		object::Destory(mEatEffect);
		//		mEatEffect = nullptr;
		//		mEatEffectTime = 0.0f;
		//		MakeScene::mEatEffectOn = false;
		//	}
		//}

		if (MakeScene::mCloudEffectOn == true)// 구름 이펙트
		{
			mCloudEffectTime += Time::DeltaTime();

			if (mCloudEffect == nullptr)
			{
				mCloudEffect = object::Instantiate<CloudEffect>(Vector2(300.0f, -500.0f), eLayerType::Effect);
			}

			Transform* tr = mCh->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			Transform* tre = mCloudEffect->GetComponent<Transform>();
			tre->SetPos(Vector2(pos.x + 550.0f, pos.y - 200.0f));

			if (mCloudEffectTime > 2.0f)
			{
				object::Destory(mCloudEffect);
				mCloudEffect = nullptr;
				mCloudEffectTime = 0.0f;
				MakeScene::mCloudEffectOn = false;
			}
		}

		if (mCh->mMagnetState == true)// 자석 아이템
		{
			mMagnetTime += Time::DeltaTime(); // 모든 아이템들에 캐릭쪽으로 오는 논리 적용시켜야함

			if (mMagnetTime > 1.0f)
			{
				mMagnetTime = 0.0f;
				mCh->mMagnetState = false;
			}

			std::unordered_map<UINT64, GameObject*>::iterator iter = mObs.begin();
			for (; iter != mObs.end(); iter++)
			{
				TilePos id;
				id.id = iter->first;

				Transform* tr = mCh->GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				MakeScene::mChPos = pos;

				if (pos.x - 30.0f < id.x && id.x < pos.x + 700.0f)
				{
					GameObject* temp = iter->second;
					temp->mMagnet = true;
				}
			}
		}

		if (mCh->mBtoB == true)// Basic To Jelly 아이템
		{
			mBtoBTime += Time::DeltaTime();
			int tempToclear = 0;

			if (mBtoBend == false && mBtoBTime <= 1.0f)
			{
				std::unordered_map<UINT64, GameObject*>::iterator iter = mBasicJelly.begin();
				for (; iter != mBasicJelly.end(); iter++)
				{
					TilePos id;
					id.id = iter->first;

					GameObject* temp = iter->second;

					Transform* tr = mCh->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					if (pos.x < id.x)
					{
						std::unordered_map<UINT64, UINT64>::iterator temp = mTiles.find(id.id);
						UINT64 indexTemp = temp->second;

						ya::object::Destory(iter->second);
						mObs.erase(id.id);
						mTiles.erase(id.id);

						mOb = object::Instantiate<Bear_FlyingPink>(Vector2(id.x, id.y), eLayerType::Item);

						mObs.insert(std::make_pair(id.id, mOb));
						mTiles.insert(std::make_pair(id.id, indexTemp));
						mBearJelly.insert(std::make_pair(id.id, mOb));
					}

					if (iter == --mBasicJelly.end())
					{
						tempToclear = 1;
						mBtoBend2 = false;
						mBtoBend = true;
					}
				}

				if (tempToclear == 1)
				{
					mBasicJelly.clear();
				}
			}

			if (mBtoBTime > 1.0f)
			{
				if (mBtoBend2 == false)
				{
					std::unordered_map<UINT64, GameObject*>::iterator iter = mBearJelly.begin();
					for (; iter != mBearJelly.end(); iter++)
					{
						TilePos id;
						id.id = iter->first;

						GameObject* temp = iter->second;

						Transform* tr = mCh->GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						if (pos.x < id.x)
						{
							ya::object::Destory(iter->second);

							std::unordered_map<UINT64, UINT64>::iterator temp = mTiles.find(id.id);
							UINT64 indexTemp = temp->second;

							mObs.erase(id.id);
							mTiles.erase(id.id);

#pragma region 젤리 index에 따른 해당 젤리 생성
							// 만약에 베이직 젤리를 여러 종류로 생성을 하고 싶다면
							// mTiles를 받아와서 그 id.id 찾아서 index 찾은 후 조건문으로 생성

							if (indexTemp == 40)
							{
								mOb = object::Instantiate<Basic_Gummy_B>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mBasicJelly.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 41)
							{
								mOb = object::Instantiate<Basic_Gummy_G>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mBasicJelly.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 42)
							{
								mOb = object::Instantiate<Basic_Gummy_R>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mBasicJelly.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 43)
							{
								mOb = object::Instantiate<Basic_Gummy_Y>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mBasicJelly.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 44)
							{
								mOb = object::Instantiate<Basic_Gummy_M1>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mBasicJelly.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 45)
							{
								mOb = object::Instantiate<Basic_Gummy_M2>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mBasicJelly.insert(std::make_pair(id.id, mOb));
							}

#pragma endregion

						}

						if (iter == --mBearJelly.end())
						{
							mBtoBend = false;
							mBtoBend2 = true;// 얘들 다시 false로 돌려놔야함
						}
					}
				}

				if (mBtoBend2 == true)
				{
					mBearJelly.clear();
					mBtoBTime = 0.0f;
					mCh->mBtoB = false;
				}
			}
		}

		if (mCh->mOtoC == true)// Obstacle To Coin 아이템
		{
			mOtoCTime += Time::DeltaTime();
			int tempToclear = 0;

			if (mOtoCend == false && mOtoCTime <= 1.0f)
			{
				std::unordered_map<UINT64, GameObject*>::iterator iter = mObstacle.begin();
				for (; iter != mObstacle.end(); iter++)
				{
					TilePos id;
					id.id = iter->first;

					GameObject* temp = iter->second;

					Transform* tr = mCh->GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					if (pos.x < id.x)
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
						tempToclear = 1;
						mOtoCend2 = false;
						mOtoCend = true;
					}
				}

				if (tempToclear == 1)
				{
					mObstacle.clear();
				}
			}

			if (mOtoCTime > 1.0f)
			{
				if (mOtoCend2 == false)
				{
					std::unordered_map<UINT64, GameObject*>::iterator iter = mCoin.begin();
					for (; iter != mCoin.end(); iter++)
					{
						TilePos id;
						id.id = iter->first;

						GameObject* temp = iter->second;

						Transform* tr = mCh->GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						if (pos.x < id.x)
						{
							ya::object::Destory(iter->second);

							std::unordered_map<UINT64, UINT64>::iterator temp = mTiles.find(id.id);
							UINT64 indexTemp = temp->second;

							mObs.erase(id.id);
							mTiles.erase(id.id);

#pragma region 젤리 index에 따른 해당 젤리 생성
							// 만약에 베이직 젤리를 여러 종류로 생성을 하고 싶다면
							// mTiles를 받아와서 그 id.id 찾아서 index 찾은 후 조건문으로 생성

							if (indexTemp == 55)
							{
								mOb = object::Instantiate<L1_JP01>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 56)
							{
								mOb = object::Instantiate<L1_JP02>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 57)
							{
								mOb = object::Instantiate<L1_JP03>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 58)
							{
								mOb = object::Instantiate<L1_JP04>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 59)
							{
								mOb = object::Instantiate<L1_JP05>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 60)
							{
								mOb = object::Instantiate<L1_JP06>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							//
							if (indexTemp == 63)
							{
								mOb = object::Instantiate<L1_DP01>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 64)
							{
								mOb = object::Instantiate<L1_DP02>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 65)
							{
								mOb = object::Instantiate<L1_DP03>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 66)
							{
								mOb = object::Instantiate<L1_DP04>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 67)
							{
								mOb = object::Instantiate<L1_DP05>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 68)
							{
								mOb = object::Instantiate<L1_DP06>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							//
							if (indexTemp == 71)
							{
								mOb = object::Instantiate<L1_SL01>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 72)
							{
								mOb = object::Instantiate<L1_SL02>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 73)
							{
								mOb = object::Instantiate<L1_SL03>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 74)
							{
								mOb = object::Instantiate<L1_SL04>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 75)
							{
								mOb = object::Instantiate<L1_SL05>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}
							if (indexTemp == 76)
							{
								mOb = object::Instantiate<L1_SL06>(Vector2(id.x, id.y), eLayerType::Item);

								id2.ind = (UINT32)indexTemp;

								mObs.insert(std::make_pair(id.id, mOb));
								mTiles.insert(std::make_pair(id.id, id2.ind));
								mObstacle.insert(std::make_pair(id.id, mOb));
							}

#pragma endregion

						}

						if (iter == --mCoin.end())
						{
							mOtoCend = false;
							mOtoCend2 = true;// 얘들 다시 false로 돌려놔야함
						}
					}
				}

				if (mOtoCend2 == true)
				{
					mCoin.clear();
					mOtoCTime = 0.0f;
					mCh->mOtoC = false;
				}
			}
		}

		if (GetFocus())
		{
			if (Input::GetKeyDown(eKeyCode::R))// 오류시, 캐릭 원위치
			{
				Transform* tr = mCh->GetComponent<Transform>();
				tr->SetPos(Vector2(tr->GetPos().x, 100.0f));
			}

			if (Input::GetKeyDown(eKeyCode::T))// 캐릭 처음 시작 위치로
			{
				Transform* tr = mCh->GetComponent<Transform>();
				tr->SetPos(Vector2(300.0f, 650.0f));
			}

			if (Input::GetKeyDown(eKeyCode::Y))// 모든 오브젝트들 삭제
			{
				for (auto i = mObs.begin(); i != mObs.end(); i++)
				{
					ya::object::Destory(i->second);
				}

				mTiles.clear();
				mObs.clear();
				mBasicJelly.clear();
				mBearJelly.clear();
				mObstacle.clear();
				mCoin.clear();
				mOb = nullptr;
			}

			if (Input::GetKeyDown(eKeyCode::E))// 방금 설치한 오브젝트 삭제
			{
				//if (!mObs.empty())// 오류 있음 끝에서부터 사라지는게 아니라 중간게 먼저 삭제됨
				//{ 
				//std::unordered_map<UINT64, GameObject*>::iterator iter1 = --mObs.end() ;
				//TilePos idt;
				//idt.id = iter1->first;

				//ya::object::Destory(iter1->second);

				//mObs.erase(idt.id);

				//mTiles.erase(idt.id);
				//}

				ya::object::Destory(mOb);
				mObs.erase(id.id);
				mTiles.erase(id.id);
			}

			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				Vector2 mousPos = Input::GetMousePos();
				if (mousPos.x >= 1600.0f || mousPos.x <= 0.0f)
					return;
				if (mousPos.y >= 900.0f || mousPos.y <= 0.0f)
					return;

				Vector2 pos = Input::GetMousePos();
				pos -= Camera::CaluatePos(Vector2::Zero);

				if (ToolScene::mIndex == 0)
				{
					DownPosX = pos.x;
					DownPosY = pos.y;
				}
				if (ToolScene::mIndex == 1)
				{
					DownPosX = pos.x;
					DownPosY = pos.y;
				}
				if (ToolScene::mIndex == 2)
				{
					mOb = object::Instantiate<Flag>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));// width가 필요한 G, OG를 제외하고는 index를 넣는 걸로
				}

				/////////////////////////////////////////////////////////////////////////////////////////       Acvtive
				if (ToolScene::mIndex == 8)
				{
					mOb = object::Instantiate<FastItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 9)
				{
					mOb = object::Instantiate<BigItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 10)
				{
					mOb = object::Instantiate<SmItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 11)
				{
					mOb = object::Instantiate<BlackOutMItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 12)
				{
					mOb = object::Instantiate<HpItemI>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 13)
				{
					mOb = object::Instantiate<HpItemD>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 14)
				{
					mOb = object::Instantiate<InvincibleItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 15)
				{
					mOb = object::Instantiate<InputEItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 16)
				{
					mOb = object::Instantiate<BasicToBear>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 17)
				{
					mOb = object::Instantiate<ObstacleToCoin>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 18)
				{
					mOb = object::Instantiate<MagnetItem>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}

				////////////////////////////////////////////////////////////////////////////////////////////// Bear
				if (ToolScene::mIndex == 24)
				{
					mOb = object::Instantiate<Bear_Big>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 25)
				{
					mOb = object::Instantiate<Bear_FlyingPink>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 26)
				{
					mOb = object::Instantiate<Bear_FlyingYellow>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 27)
				{
					mOb = object::Instantiate<Bear_Rainbow>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 28)
				{
					mOb = object::Instantiate<Bear_SmallBlue>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 29)
				{
					mOb = object::Instantiate<Bear_SmallPink>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 30)
				{
					mOb = object::Instantiate<Bear_SmallYellow>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 32)
				{
					mOb = object::Instantiate<Bear_StarBlue>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 33)
				{
					mOb = object::Instantiate<Bear_StarYellow>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}

				////////////////////////////////////////////////////////////////////////////////////////////// Coin
				if (ToolScene::mIndex == 36)
				{
					mOb = object::Instantiate<Coin_Gold>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 37)
				{
					mOb = object::Instantiate<Coin_GoldB>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 38)
				{
					mOb = object::Instantiate<Coin_Silver>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 39)
				{
					mOb = object::Instantiate<Coin_SilverB>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

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
				if (ToolScene::mIndex == 40)
				{
					mOb = object::Instantiate<Basic_Gummy_B>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 41)
				{
					mOb = object::Instantiate<Basic_Gummy_G>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 42)
				{
					mOb = object::Instantiate<Basic_Gummy_R>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 43)
				{
					mOb = object::Instantiate<Basic_Gummy_Y>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 44)
				{
					mOb = object::Instantiate<Basic_Gummy_M1>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 45)
				{
					mOb = object::Instantiate<Basic_Gummy_M2>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
				}

				/////////////////////////////////////////////////////////////////////////////////////// Tile 47~
				if (ToolScene::mIndex == 47)
				{
					int temp = pos.x / 122;
					float tempX = 122 * temp + 61;
					mOb = object::Instantiate<L1_GT01>(Vector2(tempX, 839.0f), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)tempX;
					id.y = (UINT32)839.0f;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 48)
				{
					int temp = pos.x / 122;
					float tempX = 122 * temp + 61;
					mOb = object::Instantiate<L1_GT02>(Vector2(tempX, 839.0f), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)tempX;
					id.y = (UINT32)839.0f;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 49)
				{
					int temp = pos.x / 122;
					float tempX = 122 * temp + 61;
					mOb = object::Instantiate<L1_GT03>(Vector2(tempX, 839.0f), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)tempX;
					id.y = (UINT32)839.0f;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 50)
				{
					int temp = pos.x / 122;
					float tempX = 122 * temp + 61;
					temp = pos.y / 64;
					float tempY = 64 * temp + 32 + 15.0f;
					mOb = object::Instantiate<L1_OT01>(Vector2(tempX, tempY), eLayerType::Item);


					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)tempX;
					id.y = (UINT32)tempY;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 51)
				{
					int temp = pos.x / 122;
					float tempX = 122 * temp + 61;
					temp = pos.y / 64;
					float tempY = 64 * temp + 32 + 15.0f;
					mOb = object::Instantiate<L1_OT02>(Vector2(tempX, tempY), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)tempX;
					id.y = (UINT32)tempY;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}
				if (ToolScene::mIndex == 52)
				{
					int temp = pos.x / 122;
					float tempX = 122 * temp + 61;
					temp = pos.y / 64;
					float tempY = 64 * temp + 32 + 15.0f;
					mOb = object::Instantiate<L1_OT03>(Vector2(tempX, tempY), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)tempX;
					id.y = (UINT32)tempY;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
				}

				//////////////////////////////////////////////////////////////////////////// Obstacle 55~
				if (ToolScene::mIndex == 55)
				{
					mOb = object::Instantiate<L1_JP01>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 56)
				{
					mOb = object::Instantiate<L1_JP02>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 57)
				{
					mOb = object::Instantiate<L1_JP03>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 58)
				{
					mOb = object::Instantiate<L1_JP04>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 59)
				{
					mOb = object::Instantiate<L1_JP05>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 60)
				{
					mOb = object::Instantiate<L1_JP06>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 63)
				{
					mOb = object::Instantiate<L1_DP01>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 64)
				{
					mOb = object::Instantiate<L1_DP02>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 65)
				{
					mOb = object::Instantiate<L1_DP03>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 66)
				{
					mOb = object::Instantiate<L1_DP04>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 67)
				{
					mOb = object::Instantiate<L1_DP05>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 68)
				{
					mOb = object::Instantiate<L1_DP06>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 71)
				{
					mOb = object::Instantiate<L1_SL01>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 72)
				{
					mOb = object::Instantiate<L1_SL02>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 73)
				{
					mOb = object::Instantiate<L1_SL03>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 74)
				{
					mOb = object::Instantiate<L1_SL04>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 75)
				{
					mOb = object::Instantiate<L1_SL05>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}
				if (ToolScene::mIndex == 76)
				{
					mOb = object::Instantiate<L1_SL06>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.ind));
					mObstacle.insert(std::make_pair(id.id, mOb));
				}

			}

			if (Input::GetKeyUp(eKeyCode::LBUTTON))
			{
				Vector2 mousPos = Input::GetMousePos();
				if (mousPos.x >= 1600.0f || mousPos.x <= 0.0f)
					return;
				if (mousPos.y >= 900.0f || mousPos.y <= 0.0f)
					return;

				Vector2 pos = Input::GetMousePos();
				pos -= Camera::CaluatePos(Vector2::Zero);

				int temp = DownPosX / 122;
				float DtempX = 122 * temp;
				temp = DownPosY / 64;
				float DtempY = 64 * temp;

				temp = pos.x / 122;
				float UtempX = 122 * temp + 122;
				temp = pos.y / 64;
				float UtempY = 64 * temp + 32 + 15.0f;

				UpPosX = UtempX;
				UpPosY = UtempY;

				float tempWidth = UpPosX - DtempX;
				//float tempHeight = UpPosY - DownPosY;


				if (ToolScene::mIndex == 0)
				{
					mOb = object::Instantiate<Ground>(Vector2(DtempX, 700.0f), eLayerType::Ground, Vector2(tempWidth, 50.0f));

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					id2.width = (UINT32)tempWidth;
					//TilePos id;
					id.x = (UINT32)DtempX;
					id.y = (UINT32)700.0f;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.id2));
				}
				if (ToolScene::mIndex == 1)
				{
					mOb = object::Instantiate<OverGround>(Vector2(DtempX, DtempY), eLayerType::Ground, Vector2(tempWidth, 50.0f));

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					id2.width = (UINT32)tempWidth;
					//TilePos id;
					id.x = (UINT32)DtempX;
					id.y = (UINT32)DtempY;

					mObs.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.id2));
				}
			}
		}

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

		if (Input::GetKeyState(eKeyCode::K) == eKeyState::Down)
		{
			OPENFILENAME ofn = {};

			wchar_t szFilePath[256] = {};

			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = szFilePath;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = 256;
			ofn.lpstrFilter = L"Tile\0*.tile\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (false == GetSaveFileName(&ofn))
				return;

			// 파일 입출력
			FILE* file = nullptr;

			// 쓰기 모드로 열기
			_wfopen_s(&file, szFilePath, L"wb");

			if (nullptr == file)
				return;

			std::unordered_map<UINT64, UINT64>::iterator iter = mTiles.begin();
			for (; iter != mTiles.end(); iter++)
			{
				TileInd id2;
				id2.id2 = iter->second;
				fwrite(&id2.id2, sizeof(TileInd), 1, file);

				TilePos id;
				id.id = iter->first;
				fwrite(&id.id, sizeof(TilePos), 1, file);
			}

			fclose(file);
		}

		if (Input::GetKeyState(eKeyCode::L) == eKeyState::Down)
		{
			OPENFILENAME ofn = {};

			wchar_t szFilePath[256] = {};

			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = szFilePath;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = 256;
			ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (false == GetOpenFileName(&ofn))
				return;

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

				int a = 0;
			}

			fclose(file);
		}

		Scene::Update();
	}

	void MakeScene::Render(HDC hdc)
	{
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 247, 253));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);


		Vector2 startPos(0, 0);
		startPos = Camera::CaluatePos(startPos);

		int maxRow = application.GetHeight() * 5 / TILE_SIZE_Y + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, startPos.x, TILE_SIZE_Y * y + startPos.y, NULL);
			LineTo(hdc, application.GetWidth(), TILE_SIZE_Y * y + startPos.y);
		}
		int maxColumn = application.GetWidth() / TILE_SIZE_X + 1;

		for (size_t x = 0; x < maxColumn * 5; x++)
		{
			MoveToEx(hdc, 122 * x + startPos.x, startPos.y, NULL);
			LineTo(hdc, 122 * x + startPos.x, application.GetHeight());
		}
		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);

		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void MakeScene::Release()
	{
		Scene::Release();
	}
	void MakeScene::OnEnter()
	{
		Camera::SetTarget(mCh);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
	}
	void MakeScene::OnExit()
	{
		mOb = nullptr;
		Camera::Clear();
	}

	void MakeScene::Create()
	{
		//Monster* tile = object::Instantiate<Monster>(Vector2(200.f, 200.f), eLayerType::Player);
	}
}