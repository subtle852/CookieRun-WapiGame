#include "yaEatEffect.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"
#include "yaMakeScene.h"

namespace ya
{
	EatEffect::EatEffect()
	{

	}

	EatEffect::~EatEffect()
	{

	}

	void EatEffect::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector2(1.3f, 1.3f));

		Image* mImage = Resources::Load<Image>(L"Effect", L"..\\Resources\\Item\\Effect\\effectp.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"EffectA", mImage, Vector2((290.0f * 0), (290.0f * 0)), 10, 1, 10, Vector2::Zero, 0.13, 0);

		mAnimator->Play(L"EffectA", true);

		GameObject::Initialize();
	}

	void EatEffect::Update()
	{
		GameObject::Update();
	}

	void EatEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void EatEffect::Release()
	{
		GameObject::Release();
	}
	void EatEffect::OnCollisionEnter(Collider* other)
	{
	}
	void EatEffect::OnCollisionStay(Collider* other)
	{

	}
	void EatEffect::OnCollisionExit(Collider* other)
	{
	}
}