#include "yaF_1.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_1::F_1()
	{

	}

	F_1::~F_1()
	{

	}

	void F_1::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		tr->SetScale(Vector2(0.6f, 0.6f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\1", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font1", true);

		GameObject::Initialize();
	}

	void F_1::Update()
	{
		GameObject::Update();
	}

	void F_1::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_1::Release()
	{
		GameObject::Release();
	}
	void F_1::OnCollisionEnter(Collider* other)
	{
	}
	void F_1::OnCollisionStay(Collider* other)
	{
	}
	void F_1::OnCollisionExit(Collider* other)
	{
	}
}