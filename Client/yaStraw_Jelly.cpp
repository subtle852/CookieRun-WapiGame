#include "yaStraw_Jelly.h"
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
	Straw_Jelly::Straw_Jelly()
	{

	}

	Straw_Jelly::~Straw_Jelly()
	{

	}

	void Straw_Jelly::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Item\\Strawberry", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"ItemStrawberry", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(80.0f, 80.0f));
		collider->SetCenter(Vector2(-40.0f, -80.0f));

		GameObject::Initialize();
	}

	void Straw_Jelly::Update()
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
			object::Destory(this);
		}

		GameObject::Update();
	}

	void Straw_Jelly::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Straw_Jelly::Release()
	{
		GameObject::Release();
	}

	void Straw_Jelly::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Sound* mSound = Resources::Load<Sound>(L"Basic", L"..\\Resources\\Sound\\Item\\general.wav");
			mSound->Play(false);

			PlayScene::mScore += 500;
			object::Destory(this);
		}
	}

	void Straw_Jelly::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			//Character01* ch = dynamic_cast<Character01*>(other->GetOwner());
			object::Destory(this);
		}
	}

	void Straw_Jelly::OnCollisionExit(Collider* other)
	{

	}
}