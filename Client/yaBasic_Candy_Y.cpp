#include "yaBasic_Candy_Y.h"
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
	Basic_Candy_Y::Basic_Candy_Y()
	{

	}

	Basic_Candy_Y::~Basic_Candy_Y()
	{

	}

	void Basic_Candy_Y::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BasicJelly\\Candy\\Yellow", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"CandyYellow", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Basic_Candy_Y::Update()
	{

		GameObject::Update();
	}

	void Basic_Candy_Y::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Basic_Candy_Y::Release()
	{
		GameObject::Release();
	}

	void Basic_Candy_Y::OnCollisionEnter(Collider* other)
	{

	}

	void Basic_Candy_Y::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Basic_Candy_Y::OnCollisionExit(Collider* other)
	{

	}
}