#include "yaBasicToBear.h"
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
#include "yaCharacter02.h"
#include "yaCharacter03.h"
#include "yaCharacter04.h"
#include "yaCharacter05.h"
#include "yaCharacter06.h"
#include "yaCharacter07.h"
#include "yaCharacter08.h"

#include "yaMakeScene.h"
#include "yaPlayScene.h"
#include "yaSelectCharScene.h"

namespace ya
{
	BasicToBear::BasicToBear()
	{

	}

	BasicToBear::~BasicToBear()
	{

	}

	void BasicToBear::Initialize()
	{
		//mImage = Resources::Load<Image>(L"pt", L"..\\Resources\\stage00.bmp");

		mAnimator = AddComponent<Animator>();

		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(600.0f, 700.0f));
		//tr->SetScale(Vector2(2.4f,2.4f));

		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BasicToBear", Vector2::Zero, 0.1f, 0);
		mAnimator->Play(L"ItemBasicToBear", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -80.0f));

		GameObject::Initialize();
	}

	void BasicToBear::Update()
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
				pos.x -= 700.0f * dir.x * Time::DeltaTime();
				pos.y -= 700.0f * dir.y * Time::DeltaTime();

				tr->SetPos(pos);
			}
			else if (ChPos.y - 25.0f < pos.y && pos.y < ChPos.y + 25.0f)
			{
				Vector2 pos = tr->GetPos();
				pos.x -= 700.0f * Time::DeltaTime();

				tr->SetPos(pos);
			}
			else
			{
				Vector2 dir = Vector2(500.0f, 1000.0f);
				dir.Normalize();

				Vector2 pos = tr->GetPos();
				pos.x -= 700.0f * dir.x * Time::DeltaTime();
				pos.y += 700.0f * dir.y * Time::DeltaTime();

				tr->SetPos(pos);
			}
		}

		if (mMagnetError == true)
		{
			PlayScene::mCh01->mBtoB = true;
			object::Destory(this);
		}

		GameObject::Update();
	}

	void BasicToBear::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void BasicToBear::Release()
	{
		GameObject::Release();
	}

	void BasicToBear::OnCollisionEnter(Collider* other)
	{

	}

	void BasicToBear::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			if (SelectCharScene::GetCharNumber() == 1)
			{
				Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 2)
			{
				Character01* ch = dynamic_cast<Character02*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 3)
			{
				Character01* ch = dynamic_cast<Character03*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 4)
			{
				Character01* ch = dynamic_cast<Character04*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 5)
			{
				Character01* ch = dynamic_cast<Character05*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 6)
			{
				Character01* ch = dynamic_cast<Character06*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 7)
			{
				Character01* ch = dynamic_cast<Character07*>(other->GetOwner());
				ch->mBtoB = true;
			}
			else if (SelectCharScene::GetCharNumber() == 8)
			{
				Character01* ch = dynamic_cast<Character08*>(other->GetOwner());
				ch->mBtoB = true;
			}

			object::Destory(this);
		}
	}

	void BasicToBear::OnCollisionExit(Collider* other)
	{

	}
}