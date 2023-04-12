#include "yaObstacleToCoin.h"
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

namespace ya
{
	ObstacleToCoin::ObstacleToCoin()
	{

	}

	ObstacleToCoin::~ObstacleToCoin()
	{

	}

	void ObstacleToCoin::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\ObstacleToCoin", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"ItemObstacleToCoin", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -80.0f));

		GameObject::Initialize();
	}

	void ObstacleToCoin::Update()
	{
		Vector2 ChPos = MakeScene::mChPos;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (mMagnet == true)// �� �κ��� �ڼ�ȿ���� �� ����� �����۵����� �� �־������
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
			PlayScene::mCh01->mOtoC = true;
			object::Destory(this);
		}

		GameObject::Update();
	}

	void ObstacleToCoin::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ObstacleToCoin::Release()
	{
		GameObject::Release();
	}

	void ObstacleToCoin::OnCollisionEnter(Collider* other)
	{

	}

	void ObstacleToCoin::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			ch->mOtoC = true;
			object::Destory(this);
		}
	}

	void ObstacleToCoin::OnCollisionExit(Collider* other)
	{

	}
}