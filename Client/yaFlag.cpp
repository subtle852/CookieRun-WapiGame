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
#include "yaSelectCharScene.h"

#include "yaCharacter01.h"
#include "yaCharacter02.h"
#include "yaCharacter03.h"
#include "yaCharacter04.h"
#include "yaCharacter05.h"
#include "yaCharacter06.h"
#include "yaCharacter07.h"
#include "yaCharacter08.h"

#include "yaSound.h"
#include "yaResources.h"

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
			Sound* mSound = Resources::Load<Sound>(L"Flag", L"..\\Resources\\Sound\\Flag\\flag.wav");
			mSound->Play(false);

			mAnimator->Play(L"FlagIng", true);
		}
	}
	void Flag::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			if (SelectCharScene::GetCharNumber() == 1)
			{
				Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 2)
			{
				Character02* ch = dynamic_cast<Character02*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 3)
			{
				Character03* ch = dynamic_cast<Character03*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 4)
			{
				Character04* ch = dynamic_cast<Character04*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 5)
			{
				Character05* ch = dynamic_cast<Character05*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 6)
			{
				Character06* ch = dynamic_cast<Character06*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 7)
			{
				Character07* ch = dynamic_cast<Character07*>(other->GetOwner());
				ch->mInv = true;
			}
			else if (SelectCharScene::GetCharNumber() == 8)
			{
				Character08* ch = dynamic_cast<Character08*>(other->GetOwner());
				ch->mInv = true;
			}
		}
	}
	void Flag::OnCollisionExit(Collider* other)
	{
	}
	void Flag::IngCompleteEvent()
	{
		mAnimator->Play(L"FlagUp", true);
	}
}