#include "yaF_4.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_4::F_4()
	{

	}

	F_4::~F_4()
	{

	}

	void F_4::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		tr->SetScale(Vector2(0.6f, 0.6f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\4", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font4", true);

		GameObject::Initialize();
	}

	void F_4::Update()
	{
		GameObject::Update();
	}

	void F_4::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_4::Release()
	{
		GameObject::Release();
	}
	void F_4::OnCollisionEnter(Collider* other)
	{
	}
	void F_4::OnCollisionStay(Collider* other)
	{
	}
	void F_4::OnCollisionExit(Collider* other)
	{
	}
}