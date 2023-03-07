#include "yaCharacter00.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"

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
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(500.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		Image* mImage = Resources::Load<Image>(L"Char00", L"..\\Resources\\idle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"idle", mImage, Vector2::Zero, 11, 6, 1, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Roll", mImage, Vector2::Zero, 11, 6, 6, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Run", mImage, Vector2(0.0f, (290.0f * 1)), 11, 6, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Jump", mImage, Vector2((290.0f * 0), (290.0f * 0)), 11, 6, 8, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Slide", mImage, Vector2((290.0f * 8), (290.0f * 0)), 11, 6, 3, Vector2::Zero, 0.15);
		//mAnimator->CreateAnimations(L"..\\Resorces\\Chalise\\Idle", Vector2::Zero, 0.1f);


		mAnimator->GetStartEvent(L"Run") = std::bind(&Character00::idleCompleteEvent, this);

		mAnimator->Play(L"Run", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -100.0f));

		mState = eChar00State::Run;

		GameObject::Initialize();
	}
	void Character00::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case ya::Character00::eChar00State::Run:
			run();
			break;
		case ya::Character00::eChar00State::Jump:
			jump();
			break;
		case ya::Character00::eChar00State::Slide:
			slide();
			break;
		case ya::Character00::eChar00State::Death:
			death();
			break;
		case ya::Character00::eChar00State::Idle:
			idle();
			break;
		}

		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();

		//Animator* animator = GetComponent<Animator>();

		//if (Input::GetKeyState(eKeyCode::A) == eKeyState::Down)
		//{
		//	pos.x -= 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Down)
		//{
		//	pos.x += 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
		//{
		//	pos.y -= 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::S) == eKeyState::Down)
		//{
		//	pos.y += 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Up)
		//{
		//	mPos.x = 0.0f;
		//	mPos.y = 0.0f;
		//}
		// 이렇게 여러 상황들을 제어할 수 있음
		// ex. 아이템 클릭 후, 이동시 특정 위치가 아닐때는 다시 그 위치로 이동시키는 경우를 만들 수 있음


		//tr->SetPos(pos);
	}
	void Character00::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Character00::Release()
	{
		GameObject::Release();
	}

	void Character00::run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		if (Input::GetKeyDown(eKeyCode::W))
		{
			pos.y -= 100.0f; //* Time::DeltaTime();
			mState = eChar00State::Jump;
			mAnimator->Play(L"Jump", true);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			mState = eChar00State::Slide;
			mAnimator->Play(L"Slide", true);
		}

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Character00::jump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyUp(eKeyCode::W))
		{
			pos.y += 100.0f; //* Time::DeltaTime();
			mState = eChar00State::Run;
			mAnimator->Play(L"Run", true);
		}

		tr->SetPos(pos);
	}
	void Character00::slide()
	{
		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = eChar00State::Run;
			mAnimator->Play(L"Run", true);
		}
		//mState = eChar00State::Idle;
		//mAnimator->Play(L"Idle", true);
	}
	void Character00::death()
	{
	}
	void Character00::idle()
	{
		
	}
	void Character00::idleCompleteEvent(/*const Cuphead* this*/)
	{
		int a = 0;
	}
}