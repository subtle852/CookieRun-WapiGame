#include "yaInputEItem.h"
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
	InputEItem::InputEItem()
	{

	}

	InputEItem::~InputEItem()
	{

	}

	void InputEItem::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		tr->SetScale(Vector2(0.6f, 0.6f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\InputE", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"ItemInputE", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-65.0f, -140.0f));

		GameObject::Initialize();
	}

	void InputEItem::Update()
	{
		GameObject::Update();
	}

	void InputEItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void InputEItem::Release()
	{
		GameObject::Release();
	}

	void InputEItem::OnCollisionEnter(Collider* other)
	{

	}

	void InputEItem::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			object::Destory(this);
		}
	}

	void InputEItem::OnCollisionExit(Collider* other)
	{

	}
}