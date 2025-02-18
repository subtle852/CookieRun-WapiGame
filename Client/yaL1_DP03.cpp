#include "yaL1_DP03.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaScene.h"
#include "yaCharacter01.h"
#include "yaPlayScene.h"
#include "yaObject.h"
#include "yaCharacter08.h"

namespace ya
{
	L1_DP03::L1_DP03()
	{

	}

	L1_DP03::~L1_DP03()
	{

	}

	void L1_DP03::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\Jump2\\1_03", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Jump21_03", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 180.0f));
		collider->SetCenter(Vector2(-50.0f, -180.0f));

		GameObject::Initialize();
	}

	void L1_DP03::Update()
	{
		GameObject::Update();
	}

	void L1_DP03::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_DP03::Release()
	{
		GameObject::Release();
	}
	void L1_DP03::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character08*>(PlayScene::mCh01)->mBig == true)
		{
			object::Destory(this);
		}
	}
	void L1_DP03::OnCollisionStay(Collider* other)
	{

	}
	void L1_DP03::OnCollisionExit(Collider* other)
	{
	}
}