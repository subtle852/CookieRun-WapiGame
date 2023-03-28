#include "yaBear_SmallPink.h"
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
	Bear_SmallPink::Bear_SmallPink()
	{

	}

	Bear_SmallPink::~Bear_SmallPink()
	{

	}

	void Bear_SmallPink::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BearJelly\\SmallPink", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"BearJellySmallPink", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Bear_SmallPink::Update()
	{

		GameObject::Update();
	}

	void Bear_SmallPink::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Bear_SmallPink::Release()
	{
		GameObject::Release();
	}

	void Bear_SmallPink::OnCollisionEnter(Collider* other)
	{

	}

	void Bear_SmallPink::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Bear_SmallPink::OnCollisionExit(Collider* other)
	{

	}
}