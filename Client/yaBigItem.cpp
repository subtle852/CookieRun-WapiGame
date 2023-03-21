#include "yaBigItem.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaScene.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaCharacter01.h"

namespace ya
{
	BigItem::BigItem()
	{

	}

	BigItem::~BigItem()
	{

	}

	void BigItem::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BigItem", Vector2::Zero, 0.1f,0);

		mAnimator->Play(L"ItemBigItem", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void BigItem::Update()
	{
		GameObject::Update();
	}

	void BigItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void BigItem::Release()
	{
		GameObject::Release();
	}

	void BigItem::OnCollisionEnter(Collider* other)
	{

	}

	void BigItem::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			ch->mState = eChar01State::BigJump;
			object::Destory(this);
		}
	}

	void BigItem::OnCollisionExit(Collider* other)
	{

	}
}