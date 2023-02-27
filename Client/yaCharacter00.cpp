#include "yaCharacter00.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	Character00::Character00()
	{
	}
	Character00::~Character00()
	{
	}
	void Character00::Initialize()
	{
		Image* mImage = Resources::Load<Image>(L"Char00", L"..\\Resources\\idle.bmp");
		Animator* animator = AddComponent<Animator>();
		animator->CreateAnimation(L"Stop", mImage, Vector2::Zero, 11, 6, 1, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Roll", mImage, Vector2::Zero, 11, 6, 11, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Run", mImage, Vector2(0.0f, (290.0f * 1)), 11, 6, 8, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Jump", mImage, Vector2(0.0f, (290.0f * 5)), 11, 6, 5, Vector2::Zero, 0.1);

		animator->Play(L"Run", true);

		GameObject::Initialize();
	}
	void Character00::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		Animator* animator = GetComponent<Animator>();

		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
		{
			animator->Play(L"Jump", true);
		}
		
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Up)
		{
			animator->Play(L"Run", true);
		}

		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Up)
		//{
		//	mPos.x = 0.0f;
		//	mPos.y = 0.0f;
		//}
		// 이렇게 여러 상황들을 제어할 수 있음
		// ex. 아이템 클릭 후, 이동시 특정 위치가 아닐때는 다시 그 위치로 이동시키는 경우를 만들 수 있음


		tr->SetPos(pos);
	}
	void Character00::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Character00::Release()
	{
		GameObject::Release();
	}
}