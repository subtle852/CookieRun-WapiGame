#include "yaL1_JP01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaScene.h"
#include "yaCharacter01.h"
#include "yaCharacter08.h"
#include "yaPlayScene.h"
#include "yaObject.h"

namespace ya
{
	L1_JP01::L1_JP01()
	{

	}

	L1_JP01::~L1_JP01()
	{

	}

	void L1_JP01::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\Jump1\\1_01", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Jump11_01", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(45.0f, 50.0f));
		collider->SetCenter(Vector2(-25.0f, -50.0f));

		GameObject::Initialize();
	}

	void L1_JP01::Update()
	{
		GameObject::Update();
	}

	void L1_JP01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_JP01::Release()
	{
		GameObject::Release();
	}
	void L1_JP01::OnCollisionEnter(Collider* other)
	{
		if(dynamic_cast<Character08*>(PlayScene::mCh01)->mBig == true)
		{
			object::Destory(this);
		}
	}
	void L1_JP01::OnCollisionStay(Collider* other)
	{

	}
	void L1_JP01::OnCollisionExit(Collider* other)
	{
	}
}