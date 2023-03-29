#include "yaL1_SL04.h"
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
	L1_SL04::L1_SL04()
	{

	}

	L1_SL04::~L1_SL04()
	{

	}

	void L1_SL04::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\Slide\\1_04", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Slide1_04", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 520.0f));
		collider->SetCenter(Vector2(-60.0f, -550.0f));

		GameObject::Initialize();
	}

	void L1_SL04::Update()
	{
		GameObject::Update();
	}

	void L1_SL04::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_SL04::Release()
	{
		GameObject::Release();
	}
	void L1_SL04::OnCollisionEnter(Collider* other)
	{
	}
	void L1_SL04::OnCollisionStay(Collider* other)
	{
	}
	void L1_SL04::OnCollisionExit(Collider* other)
	{
	}
}