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
	JellyCoin::JellyCoin()
	{

	}

	JellyCoin::~JellyCoin()
	{

	}

	void JellyCoin::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\CoinJelly\\Silver", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"CoinJellySilver", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void JellyCoin::Update()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//pos.x -= 700.0f * Time::DeltaTime();

		//tr->SetPos(pos);

		GameObject::Update();
	}

	void JellyCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void JellyCoin::Release()
	{
		GameObject::Release();
	}

	void JellyCoin::OnCollisionEnter(Collider* other)
	{

	}

	void JellyCoin::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			object::Destory(this);
		}
	}

	void JellyCoin::OnCollisionExit(Collider* other)
	{

	}
}