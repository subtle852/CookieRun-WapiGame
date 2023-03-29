#include "yaFlag.h"
#include "yaCharacter01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaCamera.h"

namespace ya
{
	Flag::Flag()
	{
	}
	Flag::~Flag()
	{
	}
	void Flag::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\Flag\\Wait", Vector2::Zero, 0.1f, 0);
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\Flag\\Ing", Vector2::Zero, 0.1f, 0);
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\Flag\\Up", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"FlagWait", true);

		mAnimator->GetCompleteEvent(L"FlagIng") = std::bind(&Flag::IngCompleteEvent, this);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 800.0f));
		collider->SetCenter(Vector2(-230.0f, -800.0f));

		GameObject::Initialize();
	}
	void Flag::Update()
	{
		GameObject::Update();
	}
	void Flag::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Flag::Release()
	{
		GameObject::Release();
	}
	void Flag::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			mAnimator->Play(L"FlagIng", true);
		}
	}
	void Flag::OnCollisionStay(Collider* other)
	{
	}
	void Flag::OnCollisionExit(Collider* other)
	{
	}
	void Flag::IngCompleteEvent()
	{
		mAnimator->Play(L"FlagUp", true);
	}
}