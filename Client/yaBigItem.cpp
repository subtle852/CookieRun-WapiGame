#include "yaBigItem.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaScene.h"
#include "yaObject.h"
#include "yaCamera.h"
#include "yaCharacter01.h"
#include "yaMakeScene.h"

namespace ya
{
	BigItem::BigItem()
	{

	}

	BigItem::~BigItem()
	{

	}

	void BigItem::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BigItem", Vector2::Zero, 0.1f,0);

		mAnimator->Play(L"ItemBigItem", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -80.0f));

		GameObject::Initialize();
	}

	void BigItem::Update()
	{
		Vector2 ChPos = MakeScene::mChPos;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (mMagnet == true)// 이 부분은 자석효과일 때 따라올 아이템들한테 다 넣어줘야함
		{
			if (ChPos.y + 25.0f < pos.y)
			{
				Vector2 dir = Vector2(500.0f, 1000.0f);
				dir.Normalize();

				Vector2 pos = tr->GetPos();
				pos.x -= 500.0f * dir.x * Time::DeltaTime();
				pos.y -= 500.0f * dir.y * Time::DeltaTime();

				tr->SetPos(pos);
			}
			else if (ChPos.y - 25.0f < pos.y && pos.y < ChPos.y + 25.0f)
			{
				Vector2 pos = tr->GetPos();
				pos.x -= 500.0f * Time::DeltaTime();

				tr->SetPos(pos);
			}
			else
			{
				Vector2 dir = Vector2(500.0f, 1000.0f);
				dir.Normalize();

				Vector2 pos = tr->GetPos();
				pos.x -= 500.0f * dir.x * Time::DeltaTime();
				pos.y += 500.0f * dir.y * Time::DeltaTime();

				tr->SetPos(pos);
			}
		}

		GameObject::Update();
	}

	void BigItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void BigItem::Release()
	{
		GameObject::Release();
	}

	void BigItem::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			MakeScene::mEatEffectOn = true;
		}
	}

	void BigItem::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			ch->mBig = true;
			object::Destory(this);
		}
	}

	void BigItem::OnCollisionExit(Collider* other)
	{

	}
}