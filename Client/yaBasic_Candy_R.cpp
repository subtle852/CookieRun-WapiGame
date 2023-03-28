#include "yaBasic_Candy_R.h"
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
	Basic_Candy_R::Basic_Candy_R()
	{

	}

	Basic_Candy_R::~Basic_Candy_R()
	{

	}

	void Basic_Candy_R::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BasicJelly\\Candy\\Red", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"CandyRed", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Basic_Candy_R::Update()
	{

		GameObject::Update();
	}

	void Basic_Candy_R::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Basic_Candy_R::Release()
	{
		GameObject::Release();
	}

	void Basic_Candy_R::OnCollisionEnter(Collider* other)
	{

	}

	void Basic_Candy_R::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Basic_Candy_R::OnCollisionExit(Collider* other)
	{

	}
}