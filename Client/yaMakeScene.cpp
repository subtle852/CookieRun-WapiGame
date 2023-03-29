#include "yaMakeScene.h"
#include "yaCharacter01.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"
#include "yaGround.h"
#include "yaUnderGround.h"
#include "yaOverGround.h"
#include "yaCamera.h"
#include <commdlg.h>
#include "yaToolScene.h"
#include "yaBasicToBear.h"
#include "yaTime.h"
#include "yaMagnetItem.h"
#include "yaBasic_Candy_Y.h"
#include "yaCoin_Silver.h"
#include "yaBear_FlyingPink.h"
#include "yaFlag.h"

#include "yaL1_JP01.h"
#include "yaL1_DP01.h"
#include "yaL1_SL04.h"

#include "yaL1_BG01.h"
#include "yaL1_BG02.h"
#include "yaL1_BG03.h"

#include "yaL1_GT01.h"
#include "yaL1_GT02.h"
#include "yaL1_GT03.h"

#include "yaApplication.h"
extern ya::Application application;

namespace ya
{
	Vector2 MakeScene::mChPos = Vector2::Zero;

	MakeScene::MakeScene()
	{
	}

	MakeScene::~MakeScene()
	{
	}

	void MakeScene::Initialize()
	{
		Scene::Initialize();

		//object::Instantiate<L1_BG01>(Vector2(500.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(500.0f, 370.0f), eLayerType::BG);
		object::Instantiate<L1_BG02>(Vector2(3238.0f, 370.0f), eLayerType::BG);
		//object::Instantiate<L1_BG03>(Vector2(500.0f, 370.0f), eLayerType::BG);

		object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground, Vector2(1000.0f, 50.0f));
		object::Instantiate<UnderGround>(Vector2(-100.0f, 790.0f), eLayerType::Ground);

		mCh = object::Instantiate<Character01>(Vector2(300.0f, 650.0f), eLayerType::Player);
		
	}

	void MakeScene::Update()
	{
		mCh->mCurHp = 100.0f;

		if (mCh->mMagnetState == true)
			// 1. 캐릭이 마그넷 아이템과 충돌하면 캐릭이 mMagnetState가 true가 됨
			// 2. 그럼 여기서 모든 겜오브젝트들의 mMagnet을 true로 전환시켜 그 내부 함수가 실행
			// 1번 구현은 캐릭 온콜리젼엔터 or 마그넷아이템 온콜리젼엔터 해야함
			// 2번 구현은 모든 겜오브젝트들 중에서 당겨지는 아이템들에 적용시켜야함(캐릭 쪽으로 이동하도록)
			// 3번 세이브랑 로드 할 때도 mVectorOb가 연동 되야함(아 로드할때만 해주면 되나?)
		{
			mMagnetTime += Time::DeltaTime();

			if (mMagnetTime > 1.0f)
			{
				mMagnetTime = 0.0f;
				mCh->mMagnetState = false;
			}

			std::unordered_map<UINT64, GameObject*>::iterator iter = mVectorOb.begin();
			for (; iter != mVectorOb.end(); iter++)
			{
				TilePos id;
				id.id = iter->first;

				Transform* tr = mCh->GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				MakeScene::mChPos = pos;

				if (pos.x < id.x && id.x < pos.x + 700.0f)
				{
					GameObject* temp = iter->second;
					temp->mMagnet = true;
				}
			}
		}

		if (mCh->mBtoB == true)
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
						ya::object::Destory(iter->second);
						mOb = object::Instantiate<Bear_FlyingPink>(Vector2(id.x, id.y), eLayerType::Item);

						mBearJelly.insert(std::make_pair(id.id, mOb));
					}

					if (iter == --mBasicJelly.end())
					{
						tempToclear = 1;
						mBtoBend2 = false;
						mBtoBend = true;
						//mCh->mBtoB = false;
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
							mOb = object::Instantiate<Basic_Candy_Y>(Vector2(id.x, id.y), eLayerType::Item);
							// 만약에 베이직 젤리를 여러 종류로 생성을 하고 싶다면
							// mTiles를 받아와서 그 id.id 찾아서 index 찾은 후 조건문으로 생성

							mBasicJelly.insert(std::make_pair(id.id, mOb));
						}

						if (iter == --mBearJelly.end())
						{
							mBtoBend = false;
							mBtoBend2 = true;// 얘들 다시 false로 돌려놔야함
							//mCh->mBtoB = false;
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

		if (GetFocus())
		{
			if (Input::GetKeyDown(eKeyCode::R))
			{
				Transform* tr = mCh->GetComponent<Transform>();
				tr->SetPos(Vector2(tr->GetPos().x, 100.0f));
			}

			if (Input::GetKeyDown(eKeyCode::T))
			{
				Transform* tr = mCh->GetComponent<Transform>();
				tr->SetPos(Vector2(300.0f, 650.0f));
			}

			if (Input::GetKeyDown(eKeyCode::Y))
			{
				for (auto i = mVectorOb.begin(); i != mVectorOb.end(); i++)
				{
					ya::object::Destory(i->second);
				}

				mTiles.clear();
				mVectorOb.clear();
			}
			
			if (Input::GetKeyDown(eKeyCode::E))
			{
				if (!mVectorOb.empty())
				{ 
				std::unordered_map<UINT64, GameObject*>::iterator iter1 = --mVectorOb.end() ;
				TilePos idt;
				idt.id = iter1->first;

				ya::object::Destory(iter1->second);

				mVectorOb.erase(idt.id);

				mTiles.erase(idt.id);
				}
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
					//#include "yaL1_JP01.h"
					//#include "yaL1_DP01.h"
					//#include "yaL1_SL01.h"
					//Obstacle
					//L1_GT01 OT말고 GT는 y좌표 고정하면 될듯(단, 타일마다 y위치 다른 경우 존재하니 맞춰서 타일그림 편집)
					mOb = object::Instantiate<L1_GT03>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;

					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mVectorOb.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.id2));
				}
				if (ToolScene::mIndex == 1)
				{
					//mOb = object::Instantiate<MagnetItem>(Vector2(pos.x, pos.y), eLayerType::Obstacle);
					mOb = object::Instantiate<BasicToBear>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mVectorOb.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.id2));
				}
				if (ToolScene::mIndex == 2)
				{
					DownPosX = pos.x;
					DownPosY = pos.y;
				}
				if (ToolScene::mIndex == 3)
				{
					DownPosX = pos.x;
					DownPosY = pos.y;
				}
			
				if (ToolScene::mIndex == 4)
				{
					mOb = object::Instantiate<Basic_Candy_Y>(Vector2(pos.x, pos.y), eLayerType::Item);

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					//TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mVectorOb.insert(std::make_pair(id.id, mOb));
					mBasicJelly.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.id2));
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

				UpPosX = pos.x;
				UpPosY = pos.y;

				float tempWidth = UpPosX - DownPosX;
				//float tempHeight = UpPosY - DownPosY;

				if (ToolScene::mIndex == 2)
				{
					mOb = object::Instantiate<OverGround>(Vector2(DownPosX, DownPosY), eLayerType::Ground, Vector2(tempWidth, 50.0f));

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					id2.width = (UINT32)tempWidth;
					//TilePos id;
					id.x = (UINT32)DownPosX;
					id.y = (UINT32)DownPosY;

					mVectorOb.insert(std::make_pair(id.id, mOb));
					mTiles.insert(std::make_pair(id.id, id2.id2));
				}

				if (ToolScene::mIndex == 3)
				{
					mOb = object::Instantiate<Ground>(Vector2(DownPosX, 700.0f), eLayerType::Ground, Vector2(tempWidth, 50.0f));

					int index = ToolScene::mIndex;
					id2.ind = (UINT32)index;
					id2.width = (UINT32)tempWidth;
					//TilePos id;
					id.x = (UINT32)DownPosX;
					id.y = (UINT32)700.0f;

					mVectorOb.insert(std::make_pair(id.id, mOb));
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
					mOb = object::Instantiate<Obstacle>(Vector2(id.x, id.y), eLayerType::Obstacle);
					mVectorOb.insert(std::make_pair(id.id, mOb));// Reason to insert mVectorOb : Magnet is activating at MakeScene Update with mVectorOb
				}
				if (id2.ind == 1)
				{
					mOb = object::Instantiate<MagnetItem>(Vector2(id.x, id.y), eLayerType::Obstacle);
					mVectorOb.insert(std::make_pair(id.id, mOb));
				}
				if (id2.ind == 2)
				{
					mOb = object::Instantiate<OverGround>(Vector2(id.x, id.y), eLayerType::Ground, Vector2((float)id2.width, 50.0f));
					mVectorOb.insert(std::make_pair(id.id, mOb));
				}
				if (id2.ind == 3)
				{
					mOb = object::Instantiate<Ground>(Vector2(id.x, id.y), eLayerType::Ground, Vector2((float)id2.width, 50.0f));
					mVectorOb.insert(std::make_pair(id.id, mOb));
				}
				if (id2.ind == 4)
				{
					mOb = object::Instantiate<BasicToBear>(Vector2(id.x, id.y), eLayerType::BG, Vector2((float)id2.width, 50.0f));
					mVectorOb.insert(std::make_pair(id.id, mOb));
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
			MoveToEx(hdc, TILE_SIZE_X * x + startPos.x, startPos.y, NULL);
			LineTo(hdc, TILE_SIZE_X * x + startPos.x, application.GetHeight());
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