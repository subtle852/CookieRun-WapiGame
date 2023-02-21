#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);// 핸들만 받아와서 GetDc를 통해 HDC 받아올 수 있음

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
		//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		//{
		//	mPos.x -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		//{
		//	mPos.x += 0.01f;
		//}

		//if (GetAsyncKeyState(VK_UP) & 0x8000)
		//{
		//	mPos.y -= 0.01f;
		//}

		//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		//{
		//	mPos.y += 0.01f;
		//}
	}

	void Application::Render()
	{
		Time::Render(mHdc);
		Input::Render(mHdc);
		SceneManager::Render(mHdc);


		//// hdc자리에 변수 mHdc 넣었고
		//// 좌표나 크기도 Vector 구조체 변수로 넣음
		//// stock 오브젝트
		//HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush); // SelectObject는 바꾸기 직전의 상태를 뱉어준다
		////Rectangle(mHdc, -1, -1, 1601, 901);

		//HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		//HPEN oldPen = (HPEN)SelectObject(mHdc, pen);

		//Rectangle(mHdc, mPos.x, mPos.y, mPos.x + 100, mPos.y + 100);

		//SelectObject(mHdc, oldPen);
		//DeleteObject(pen);
		//SelectObject(mHdc, oldBrush);
		//DeleteObject(brush);
	}
}
