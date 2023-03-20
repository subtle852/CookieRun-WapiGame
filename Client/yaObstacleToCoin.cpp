#include "yaObstacleToCoin.h"
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
	ObstacleToCoin::ObstacleToCoin()
	{

	}

	ObstacleToCoin::~ObstacleToCoin()
	{

	}

	void ObstacleToCoin::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\ObstacleToCoin", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"ItemObstacleToCoin", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void ObstacleToCoin::Update()
	{
		GameObject::Update();
	}

	void ObstacleToCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ObstacleToCoin::Release()
	{
		GameObject::Release();
	}

	void ObstacleToCoin::OnCollisionEnter(Collider* other)
	{

	}

	void ObstacleToCoin::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			object::Destory(this);
		}
	}

	void ObstacleToCoin::OnCollisionExit(Collider* other)
	{

	}
}