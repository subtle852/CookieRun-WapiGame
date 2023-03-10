#include "yaPet00.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	Pet00::Pet00()
	{

	}

	Pet00::~Pet00()
	{

	}

	void Pet00::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(300.0f, 400.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		Image* mImage = Resources::Load<Image>(L"Pet00", L"..\\Resources\\pet_idle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"idle", mImage, Vector2::Zero, 8, 5, 1, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Run", mImage, Vector2::Zero, 8, 5, 4, Vector2::Zero, 0.15);

		mAnimator->Play(L"Run", true);
		mState = ePet00State::Run;

		GameObject::Initialize();
	}

	void Pet00::Update()
	{
		GameObject::Update();

		Scene* scn = SceneManager::GetActiveScene();
		if (scn->GetName() == L"Play")
		{
			switch (mState)
			{
			case ya::Pet00::ePet00State::Run:
				run();
				break;
			case ya::Pet00::ePet00State::Jump:
				jump();
				break;
			case ya::Pet00::ePet00State::Slide:
				slide();
				break;
			case ya::Pet00::ePet00State::Idle:
				idle();
				break;
			}
		}
	}

	void Pet00::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Pet00::Release()
	{
		GameObject::Release();
	}

	void Pet00::run()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		if (Input::GetKeyDown(eKeyCode::W))
		{
			pos.y -= 5000.0f * Time::DeltaTime();
			mState = ePet00State::Jump;
			//mAnimator->Play(L"Jump", true);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
			mState = ePet00State::Slide;
			//mAnimator->Play(L"Slide", true);
		}

		//if (Input::GetKey(eKeyCode::A))
		//{
		//	pos.x -= 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKey(eKeyCode::D))
		//{
		//	pos.x += 100.0f * Time::DeltaTime();
		//}
		tr->SetPos(pos);
	}

	void Pet00::jump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyUp(eKeyCode::W))
		{
			pos.y += 5000.0f * Time::DeltaTime();
			mState = ePet00State::Run;
			//mAnimator->Play(L"Run", true);
		}

		tr->SetPos(pos);
	}

	void Pet00::slide()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyUp(eKeyCode::S))
		{
			pos.y -= 100.0f * Time::DeltaTime();
			mState = ePet00State::Run;
			//mAnimator->Play(L"Run", true);
		}

		tr->SetPos(pos);
	}

	void Pet00::idle()
	{

	}
}