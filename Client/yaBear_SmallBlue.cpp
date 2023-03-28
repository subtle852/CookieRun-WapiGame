#include "yaBear_SmallBlue.h"
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
	Bear_SmallBlue::Bear_SmallBlue()
	{

	}

	Bear_SmallBlue::~Bear_SmallBlue()
	{

	}

	void Bear_SmallBlue::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BearJelly\\SmallBlue", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"BearJellySmallBlue", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Bear_SmallBlue::Update()
	{

		GameObject::Update();
	}

	void Bear_SmallBlue::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Bear_SmallBlue::Release()
	{
		GameObject::Release();
	}

	void Bear_SmallBlue::OnCollisionEnter(Collider* other)
	{

	}

	void Bear_SmallBlue::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Bear_SmallBlue::OnCollisionExit(Collider* other)
	{

	}
}