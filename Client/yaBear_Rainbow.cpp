#include "yaBear_Rainbow.h"
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
#include "yaPlayScene.h"


#include "yaSound.h"
#include "yaResources.h"

namespace ya
{
	Bear_Rainbow::Bear_Rainbow()
	{

	}

	Bear_Rainbow::~Bear_Rainbow()
	{

	}

	void Bear_Rainbow::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\BearJelly\\Rainbow", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"BearJellyRainbow", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(100.0f, 100.0f));
		collider->SetCenter(Vector2(-50.0f, -110.0f));

		GameObject::Initialize();
	}

	void Bear_Rainbow::Update()
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
			object::Destory(this);
		}

		GameObject::Update();
	}

	void Bear_Rainbow::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Bear_Rainbow::Release()
	{
		GameObject::Release();
	}

	void Bear_Rainbow::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Sound* mSound = Resources::Load<Sound>(L"Basic", L"..\\Resources\\Sound\\Item\\general.wav");
			mSound->Play(false);

			PlayScene::mScore += 2000;
			object::Destory(this);
		}
	}

	void Bear_Rainbow::OnCollisionStay(Collider* other)
	{
		
	}

	void Bear_Rainbow::OnCollisionExit(Collider* other)
	{

	}
}