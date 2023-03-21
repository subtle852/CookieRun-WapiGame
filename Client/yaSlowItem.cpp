#include "yaSlowItem.h"
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
	SlowItem::SlowItem()
	{

	}

	SlowItem::~SlowItem()
	{

	}

	void SlowItem::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\SlowItem", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"ItemSlowItem", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void SlowItem::Update()
	{
		GameObject::Update();
	}

	void SlowItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void SlowItem::Release()
	{
		GameObject::Release();
	}

	void SlowItem::OnCollisionEnter(Collider* other)
	{

	}

	void SlowItem::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			ch->mSlow = true;

			object::Destory(this);
		}
	}

	void SlowItem::OnCollisionExit(Collider* other)
	{

	}
}