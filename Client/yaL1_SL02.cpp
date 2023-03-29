#include "yaL1_SL02.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaScene.h"
#include "yaCamera.h"

namespace ya
{
	L1_SL02::L1_SL02()
	{

	}

	L1_SL02::~L1_SL02()
	{

	}

	void L1_SL02::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\Slide\\1_02", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Slide1_02", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 520.0f));
		collider->SetCenter(Vector2(-60.0f, -550.0f));

		GameObject::Initialize();
	}

	void L1_SL02::Update()
	{
		GameObject::Update();
	}

	void L1_SL02::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_SL02::Release()
	{
		GameObject::Release();
	}
	void L1_SL02::OnCollisionEnter(Collider* other)
	{
	}
	void L1_SL02::OnCollisionStay(Collider* other)
	{
	}
	void L1_SL02::OnCollisionExit(Collider* other)
	{
	}
}