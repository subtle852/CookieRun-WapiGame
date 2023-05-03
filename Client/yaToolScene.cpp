#include "yaToolScene.h"
#include "yaApplication.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaTile.h"
#include "yaObject.h"
#include "yaInput.h"

extern ya::Application application;

namespace ya
{
	UINT ToolScene::mIndex = -1;
    ToolScene::ToolScene()
    {
    }

    ToolScene::~ToolScene()
    {
    }

    void ToolScene::Initialize()
    {
        Scene::Initialize();

        ya::Image* tile = ya::Resources::Find<ya::Image>(L"TileAtlas");
        Tile* test = object::Instantiate<Tile>(eLayerType::Tile);
        test->InitializeTile(tile, 0);

    }

    void ToolScene::Update()
    {
        Scene::Update();

        Vector2  temp = Input::GetMousePos();


        if (Input::GetKey(eKeyCode::LBUTTON))
        {

        }
    }

    void ToolScene::Render(HDC hdc)
    {
        HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
        HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

        int maxRow = application.GetHeight() / TILE_SIZE_Y + 1;
        for (size_t y = 0; y < maxRow; y++)
        {
            MoveToEx(hdc, 0, TILE_SIZE_Y * y, NULL);
            LineTo(hdc, application.GetWidth(), TILE_SIZE_Y * y);
        }
        int maxColumn = application.GetWidth() / TILE_SIZE_X + 1;
        for (size_t x = 0; x < maxColumn; x++)
        {
            MoveToEx(hdc, TILE_SIZE_X * x, 0, NULL);
            LineTo(hdc, TILE_SIZE_X * x, application.GetHeight());
        }
        (HPEN)SelectObject(hdc, oldPen);
        DeleteObject(redPen);

        Scene::Render(hdc);
    }

    void ToolScene::Release()
    {
        Scene::Release();
    }

    void ToolScene::OnEnter()
    {
    }

    void ToolScene::OnExit()
    {
    }
}

#include "Resource.h"
#include "windowsx.h"
#include <string>
#include "yaToolScene.h"

int x, y; WCHAR text[100]; int index = 0; int chapter = 0;

LRESULT CALLBACK AtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		//512 384
		//HMENU mMenubar = LoadMenu(nullptr, MAKEINTRESOURCE(IDC_CLIENT));
		//SetMenu(hWnd, mMenubar);
		ya::Image* tile = ya::Resources::Load<ya::Image>(L"Tile1", L"..\\Resources\\Tile_1_b.bmp");
		ya::Image* tile2 = ya::Resources::Load<ya::Image>(L"Tile2", L"..\\Resources\\Tile_2_b.bmp");
		ya::Image* tile3 = ya::Resources::Load<ya::Image>(L"Tile3", L"..\\Resources\\Tile3.bmp");
		RECT rect = { 0, 0, tile->GetWidth(), tile->GetHeight() };
		//RECT rect = { 0, 0, tile->GetWidth(), tile->GetHeight() };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// 윈도우 크기 변경및 출력 설정
		SetWindowPos(hWnd
			, nullptr, 1600, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(hWnd, true);
	}

	case WM_LBUTTONDOWN:
	{
		if (GetFocus())
		{
			x = GET_X_LPARAM(lParam);
			y = GET_Y_LPARAM(lParam);

			if (chapter == 0)
			{
				index = (x / 64) + (8 * (y / 64));

				if (index > 500 || index < 0)
				{
					index = 0;
				}
				ya::ToolScene::mIndex = index;
			}
				
			if (chapter == 1)
			{
				index = (x / 64) + (8 * (y / 64));
				index += 47;

				if (index > 500 || index < 0)
				{
					index = 0;
				}
				ya::ToolScene::mIndex = index;
			}
			
			if (chapter == 2)
			{
				index = (x / 64) + (8 * (y / 64));
				index += 94;

				if (index > 500 || index < 0)
				{
					index = 0;
				}
				ya::ToolScene::mIndex = index;
			}

			if (index == 47)
			{
				chapter = 1;
			}
			if (index == 94)
			{
				chapter = 0;//
			}
			if (index == 141)
			{
				chapter = 0;
			}

			wsprintf(text, L"i : %d chapter : %d", index, chapter);
			InvalidateRect(hWnd, NULL, TRUE);
		}
	}
	break;

	case WM_MOUSEMOVE:
	{
		if (GetFocus())
		{

			//if (ya::Input::GetKeyDown(ya::eKeyCode::LBUTTON))
			//{
			//	Vector2 mousPos = ya::Input::GetMousePos();
			////}

			//	int y, x;
			//	x = mousPos.x;
			//	y = mousPos.y;

			//	HDC hdc = GetDC(hWnd);

			//	std::wstring posx = std::to_wstring(x);
			//	std::wstring posy = std::to_wstring(y);

			//	TextOut(hdc, 0, 0, posx.c_str(), posx.size());
			//	TextOut(hdc, 0, 50, posy.c_str(), posy.size());

			//::POINT mousePos = {};
			//::GetCursorPos(&mousePos);
			//::ScreenToClient(hWnd, &mousePos);

			//x = mousePos.x;
			//y = mousePos.y;

			x = GET_X_LPARAM(lParam);
			y = GET_Y_LPARAM(lParam);

			wsprintf(text, L"i : %d chapter : %d", index, chapter);
			//InvalidateRect(hWnd, NULL, TRUE);

			/*int y, x;
			x = GET_X_LPARAM(lParam);
			y = GET_Y_LPARAM(lParam);

			HDC hdc = GetDC(hWnd);

			std::wstring posx = std::to_wstring(x);
			std::wstring posy = std::to_wstring(y);

			TextOut(hdc, 0, 0, posx.c_str(), posx.size());
			TextOut(hdc, 0, 50, posy.c_str(), posy.size());*/
		}
	}
	break;

	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
			//case IDM_ABOUT:
			//    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			//    break;
			//case IDM_EXIT:
			//    DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		if (chapter == 0)
		{
			ya::Image* tile = ya::Resources::Find<ya::Image>(L"Tile1");
			BitBlt(hdc, 0, 0, tile->GetWidth(), tile->GetHeight(), tile->GetHdc(), 0, 0, SRCCOPY);
		}

		if (chapter == 1)
		{
			ya::Image* tile2 = ya::Resources::Find<ya::Image>(L"Tile2");
			BitBlt(hdc, 0, 0, tile2->GetWidth(), tile2->GetHeight(), tile2->GetHdc(), 0, 0, SRCCOPY);
		}

		if (chapter == 2)
		{
			ya::Image* tile3 = ya::Resources::Find<ya::Image>(L"Tile3");
			BitBlt(hdc, 0, 0, tile3->GetWidth(), tile3->GetHeight(), tile3->GetHdc(), 0, 0, SRCCOPY);
		}
		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		//Ellipse(hdc, 0, 0, 100, 100);
		////RoundRect(hdc, 200, 200, 300, 300, 500, 500);
		//(HPEN)SelectObject(hdc, oldPen);
		//DeleteObject(redPen);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		
		
		TextOutW(hdc, 410, 0, text, lstrlen(text));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}