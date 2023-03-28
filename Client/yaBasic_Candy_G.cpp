#include "yaBasic_Candy_G.h"
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
	Basic_Candy_G::Basic_Candy_G()
	{

	}

	Basic_Candy_G::~Basic_Candy_G()
	{

	}

	void Basic_Candy_G::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BasicJelly\\Candy\\Green", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"CandyGreen", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Basic_Candy_G::Update()
	{

		GameObject::Update();
	}

	void Basic_Candy_G::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Basic_Candy_G::Release()
	{
		GameObject::Release();
	}

	void Basic_Candy_G::OnCollisionEnter(Collider* other)
	{

	}

	void Basic_Candy_G::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Basic_Candy_G::OnCollisionExit(Collider* other)
	{

	}
}