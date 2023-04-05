#include "yaF_2.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_2::F_2()
	{

	}

	F_2::~F_2()
	{

	}

	void F_2::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		tr->SetScale(Vector2(0.6f, 0.6f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\2", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font2", true);

		GameObject::Initialize();
	}

	void F_2::Update()
	{
		GameObject::Update();
	}

	void F_2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_2::Release()
	{
		GameObject::Release();
	}
	void F_2::OnCollisionEnter(Collider* other)
	{
	}
	void F_2::OnCollisionStay(Collider* other)
	{
	}
	void F_2::OnCollisionExit(Collider* other)
	{
	}
}