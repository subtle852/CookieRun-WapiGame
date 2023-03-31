#include "yaCloudEffect.h"
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
	CloudEffect::CloudEffect()
	{

	}

	CloudEffect::~CloudEffect()
	{

	}

	void CloudEffect::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\Effect\\Cloud", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"EffectCloud", true);

		GameObject::Initialize();
	}

	void CloudEffect::Update()
	{
		GameObject::Update();
	}

	void CloudEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void CloudEffect::Release()
	{
		GameObject::Release();
	}
	void CloudEffect::OnCollisionEnter(Collider* other)
	{
	}
	void CloudEffect::OnCollisionStay(Collider* other)
	{

	}
	void CloudEffect::OnCollisionExit(Collider* other)
	{
	}
}