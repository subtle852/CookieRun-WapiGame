#include "yaF_5.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_5::F_5()
	{

	}

	F_5::~F_5()
	{

	}

	void F_5::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		tr->SetScale(Vector2(0.6f, 0.6f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\5", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font5", true);

		GameObject::Initialize();
	}

	void F_5::Update()
	{
		GameObject::Update();
	}

	void F_5::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_5::Release()
	{
		GameObject::Release();
	}
	void F_5::OnCollisionEnter(Collider* other)
	{
	}
	void F_5::OnCollisionStay(Collider* other)
	{
	}
	void F_5::OnCollisionExit(Collider* other)
	{
	}
}