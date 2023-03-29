#include "yaL1_OT03.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	L1_OT03::L1_OT03()
	{

	}

	L1_OT03::~L1_OT03()
	{

	}

	void L1_OT03::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\Tile\\1_OT03", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Tile1_OT03", true);

		GameObject::Initialize();
	}

	void L1_OT03::Update()
	{
		GameObject::Update();
	}

	void L1_OT03::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_OT03::Release()
	{
		GameObject::Release();
	}
	void L1_OT03::OnCollisionEnter(Collider* other)
	{
	}
	void L1_OT03::OnCollisionStay(Collider* other)
	{

	}
	void L1_OT03::OnCollisionExit(Collider* other)
	{
	}
}