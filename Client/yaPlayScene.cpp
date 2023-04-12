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
#include "yaL1_BG02.h"

namespace ya
{
	Character01* PlayScene::mCh01 = nullptr;
	bool PlayScene::mCloudEffectOnatPlay = false;

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
		object::Instantiate<L1_BG02>(Vector2(500.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(3238.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(5976.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(8714.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(11452.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(14190.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(16928.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(19666.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(22404.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(25142.0f, 370.0f), eLayerType::BG);


		object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground, Vector2(1000.0f, 50.0f));
		object::Instantiate<UnderGround>(Vector2(-100.0f, 890.0f), eLayerType::Ground);

		int temp = SelectCharScene::GetCharNumber();
		if (int temp = SelectCharScene::GetCharNumber() == 1)
		{
			mCh01 = object::Instantiate<Character01>(Vector2(300.0f, 650.0f), eLayerType::Player);
		}

		mPet01 = object::Instantiate<Pet01>(eLayerType::Pet);

		#pragma region Load
		{
			wchar_t szFilePath[256] = L"..\\Resources\\temp";
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

		// UI라서 직접 선언해야함
		object::Instantiate<GaugeCircle>(Vector2(-10.0f, 20.0f), eLayerType::UIAbove);
		object::Instantiate<GaugeBar>(Vector2(59.0f, 32.0f), eLayerType::UI);

		object::Instantiate<JumpButton>(Vector2(100.0f, 650.0f), eLayerType::UI);
		object::Instantiate<SlideButton>(Vector2(1200.0f, 650.0f), eLayerType::UI);
		object::Instantiate<PauseButton>(Vector2(1480.0f, 40.0f), eLayerType::UI);

	}

	void PlayScene::Update()
	{
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

			if (mMagnetTime > 2.0f)
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

				if (pos.x < id.x && id.x < pos.x + 500.0f)
				{
					GameObject* temp = iter->second;
					temp->mMagnet = true;
				}
				//if (pos.x >= id.x)
				//{
				//	GameObject* temp = iter->second;
				//	temp->mMagnet = false;
				//}
				if (pos.x - 500.f < id.x && id.x < pos.x)
				{
					GameObject* temp = iter->second;
					temp->mMagnetError = true;
				}
			}
		}

		if (mCh01->mBtoB == true)// Basic To Jelly 아이템
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

					Transform* tr = mCh01->GetComponent<Transform>();
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

						Transform* tr = mCh01->GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						if (pos.x + 50.f < id.x)
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
					mCh01->mBtoB = false;
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

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			//SceneManager::LoadScene(eSceneType::ResultS);
			SceneManager::LoadScene(eSceneType::Make);
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
		Camera::SetTarget(mCh01);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
	}

	void PlayScene::OnExit()
	{
		Camera::Clear();
		//ya::object::Destory(mBG);
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f }); 씬넘길때 원상복귀 시키는것
	}
}