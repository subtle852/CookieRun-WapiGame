#include "yaCoin_SilverB.h"
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
	Coin_SilverB::Coin_SilverB()
	{

	}

	Coin_SilverB::~Coin_SilverB()
	{

	}

	void Coin_SilverB::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\CoinJelly\\SilverB", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"CoinJellySilverB", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void Coin_SilverB::Update()
	{
		GameObject::Update();
	}

	void Coin_SilverB::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Coin_SilverB::Release()
	{
		GameObject::Release();
	}

	void Coin_SilverB::OnCollisionEnter(Collider* other)
	{

	}

	void Coin_SilverB::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			object::Destory(this);
		}
	}

	void Coin_SilverB::OnCollisionExit(Collider* other)
	{

	}
}