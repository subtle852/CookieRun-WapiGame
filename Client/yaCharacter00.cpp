#include "yaCharacter00.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	Character00::Character00()
		: mTime(0.0f)
		, mIdx(0)
	{
	}
	Character00::~Character00()
	{
	}
	void Character00::Initialize()
	{
		mImage = Resources::Load<Image>(L"Char00", L"..\\Resources\\idle.bmp");

		GameObject::Initialize();
	}
	void Character00::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Up)
		//{
		//	mPos.x = 0.0f;
		//	mPos.y = 0.0f;
		//}
		// 이렇게 여러 상황들을 제어할 수 있음
		// ex. 아이템 클릭 후, 이동시 특정 위치가 아닐때는 다시 그 위치로 이동시키는 경우를 만들 수 있음

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPos(pos);
	}
	void Character00::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		mTime += Time::DeltaTime();

		if (mIdx >= 8)
		{
			mIdx = 0;
		}

		if (mTime > 0.1f)
		{
			mIdx++;
			mTime = 0.0f;
		}

		int a = 392;
		TransparentBlt(hdc, pos.x, pos.y, a, 392
			, mImage->GetHdc(), (a * mIdx),0, a, 392, RGB(170,0,0));

		//BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void Character00::Release()
	{
		GameObject::Release();
	}
}