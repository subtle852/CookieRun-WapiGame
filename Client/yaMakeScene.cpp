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
#include "yaCamera.h"
#include <commdlg.h>
#include "yaToolScene.h"

#include "yaApplication.h"
extern ya::Application application;

namespace ya
{
	MakeScene::MakeScene()
	{
	}

	MakeScene::~MakeScene()
	{
	}

	void MakeScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground);
		object::Instantiate<UnderGround>(Vector2(-100.0f, 790.0f), eLayerType::Ground);

		mCh = object::Instantiate<Character01>(Vector2(300.0f, 650.0f), eLayerType::Player);
		
	}

	void MakeScene::Update()
	{
		mCh->mCurHp = 100.0f;

		if (GetFocus())
		{

			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				Vector2 mousPos = Input::GetMousePos();
				if (mousPos.x >= 1600.0f || mousPos.x <= 0.0f)
					return;
				if (mousPos.y >= 900.0f || mousPos.y <= 0.0f)
					return;

				Vector2 pos = Input::GetMousePos();
				pos -= Camera::CaluatePos(Vector2::Zero);

				if (ToolScene::mIndex == 0)// class가 Monster일때
				{
					object::Instantiate<Obstacle>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;

					TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mTiles.insert(std::make_pair(id.id, index));
				}
				if (ToolScene::mIndex == 1)// class가 Monster일때
				{
					object::Instantiate<Obstacle01>(Vector2(pos.x, pos.y), eLayerType::Obstacle);

					int index = ToolScene::mIndex;

					TilePos id;
					id.x = (UINT32)pos.x;
					id.y = (UINT32)pos.y;

					mTiles.insert(std::make_pair(id.id, index));
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

			std::unordered_map<UINT64, int>::iterator iter = mTiles.begin();
			for (; iter != mTiles.end(); iter++)
			{
				int index = iter->second;
				fwrite(&index, sizeof(int), 1, file);

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
				int index = -1;
				TilePos id;

				if (fread(&index, sizeof(int), 1, file) == NULL)
					break;

				if (fread(&id.id, sizeof(TilePos), 1, file) == NULL)
					break;


				if (index == 0)
				{
					object::Instantiate<Obstacle>(Vector2(id.x, id.y), eLayerType::Obstacle);
				}
				if (index == 1)
				{
					object::Instantiate<Obstacle01>(Vector2(id.x, id.y), eLayerType::Obstacle);
				}

				int a = 0;
			}

			fclose(file);
		}

		Scene::Update();
	}

	void MakeScene::Render(HDC hdc)
	{
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);


		Vector2 startPos(0, 0);
		startPos = Camera::CaluatePos(startPos);

		int maxRow = application.GetHeight() / TILE_SIZE_Y + 1;
		for (size_t y = 0; y < maxRow; y++)
		{
			MoveToEx(hdc, startPos.x, TILE_SIZE_Y * y + startPos.y, NULL);
			LineTo(hdc, application.GetWidth(), TILE_SIZE_Y * y + startPos.y);
		}
		int maxColumn = application.GetWidth() / TILE_SIZE_X + 1;

		for (size_t x = 0; x < maxColumn*3; x++)
		{
			MoveToEx(hdc, TILE_SIZE_X * x + startPos.x, startPos.y, NULL);
			LineTo(hdc, TILE_SIZE_X * x + startPos.x, application.GetHeight());
		}
		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);

		Scene::Render(hdc);

		Scene::SceneText(hdc);
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
	}
	void MakeScene::OnExit()
	{
		Camera::Clear();
	}

	void MakeScene::Create()
	{
		//Monster* tile = object::Instantiate<Monster>(Vector2(200.f, 200.f), eLayerType::Player);
	}
}