#include "yaL1_JP04.h"
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
	L1_JP04::L1_JP04()
	{

	}

	L1_JP04::~L1_JP04()
	{

	}

	void L1_JP04::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));

		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\Jump1\\1_04", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Jump11_04", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(45.0f, 50.0f));
		collider->SetCenter(Vector2(-25.0f, -50.0f));

		GameObject::Initialize();
	}

	void L1_JP04::Update()
	{
		GameObject::Update();
	}

	void L1_JP04::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_JP04::Release()
	{
		GameObject::Release();
	}
	void L1_JP04::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character08*>(PlayScene::mCh01)->mBig == true)
		{
			object::Destory(this);
		}
	}
	void L1_JP04::OnCollisionStay(Collider* other)
	{

	}
	void L1_JP04::OnCollisionExit(Collider* other)
	{
	}
}