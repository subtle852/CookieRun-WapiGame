#include "yaBasic_Gummy_Y.h"
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
	Basic_Gummy_Y::Basic_Gummy_Y()
	{

	}

	Basic_Gummy_Y::~Basic_Gummy_Y()
	{

	}

	void Basic_Gummy_Y::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BasicJelly\\Gummy\\Yellow", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"GummyYellow", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Basic_Gummy_Y::Update()
	{

		GameObject::Update();
	}

	void Basic_Gummy_Y::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Basic_Gummy_Y::Release()
	{
		GameObject::Release();
	}

	void Basic_Gummy_Y::OnCollisionEnter(Collider* other)
	{

	}

	void Basic_Gummy_Y::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Basic_Gummy_Y::OnCollisionExit(Collider* other)
	{

	}
}