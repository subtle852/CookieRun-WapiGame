#include "yaBlackOutMItem.h"
#include "yaJellyCoin.h"
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
	BlackOutMItem::BlackOutMItem()
	{

	}

	BlackOutMItem::~BlackOutMItem()
	{
			
	}

	void BlackOutMItem::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BlackOutM", Vector2::Zero, 0.1f, 0);
		mAnimator->Play(L"ItemBlackOutM", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void BlackOutMItem::Update()
	{
		GameObject::Update();
	}

	void BlackOutMItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void BlackOutMItem::Release()
	{
		GameObject::Release();
	}

	void BlackOutMItem::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			ok = true;
			//object::Destory(this);
			Transform* tr = this->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			tr->SetPos(Vector2(pos.x, pos.y + 500.0f));
		}
	}

	void BlackOutMItem::OnCollisionStay(Collider* other)
	{
	
	}

	void BlackOutMItem::OnCollisionExit(Collider* other)
	{

	}
}