#include "yaFastItem.h"
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
	FastItem::FastItem()
	{

	}

	FastItem::~FastItem()
	{

	}

	void FastItem::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\FastItem", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"ItemFastItem", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void FastItem::Update()
	{
		GameObject::Update();
	}

	void FastItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void FastItem::Release()
	{
		GameObject::Release();
	}

	void FastItem::OnCollisionEnter(Collider* other)
	{

	}

	void FastItem::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			object::Destory(this);
		}
	}

	void FastItem::OnCollisionExit(Collider* other)
	{

	}
}