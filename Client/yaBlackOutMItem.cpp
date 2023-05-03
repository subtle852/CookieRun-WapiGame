#include "yaBlackOutMItem.h"
#include "yaCoin_Silver.h"
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


#include "yaSound.h"
#include "yaResources.h"

namespace ya
{
	BlackOutMItem::BlackOutMItem()
	{

	}

	BlackOutMItem::~BlackOutMItem()
	{
			
	}

	void BlackOutMItem::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BlackOutM", Vector2::Zero, 0.1f, 0);
		mAnimator->Play(L"ItemBlackOutM", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -60.0f));

		GameObject::Initialize();
	}

	void BlackOutMItem::Update()
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
			MakeScene::mEatEffectOn = true;
			MakeScene::mCloudEffectOn = true;
			PlayScene::mCloudEffectOnatPlay = true;
			object::Destory(this);
		}

		GameObject::Update();
	}

	void BlackOutMItem::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void BlackOutMItem::Release()
	{
		GameObject::Release();
	}

	void BlackOutMItem::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Sound* mSound = Resources::Load<Sound>(L"Black", L"..\\Resources\\Sound\\Item\\ability1.wav");
			mSound->Play(false);
		}
	}

	void BlackOutMItem::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			MakeScene::mCloudEffectOn = true;
			PlayScene::mCloudEffectOnatPlay = true;
			object::Destory(this);
		}
	}

	void BlackOutMItem::OnCollisionExit(Collider* other)
	{

	}
}