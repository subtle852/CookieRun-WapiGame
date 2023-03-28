#include "yaUnderGround.h"
#include "yaCollider.h"
#include "yaCharacter01.h"
#include "yaRigidbody.h"
#include "yaTransform.h"

namespace ya
{
	UnderGround::UnderGround()
	{
	}

	UnderGround::~UnderGround()
	{
	}

	void UnderGround::Initialize()
	{
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(50000.0f, 50.0f));
		GameObject::Initialize();
	}

	void UnderGround::Update()
	{
		GameObject::Update();
	}

	void UnderGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void UnderGround::Release()
	{
	}

	void UnderGround::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
			if (cuphead->mState == eChar01State::BigRun)// 커질 때 콜라이더가 언더그라운드와 충돌하기에 예외처리 1
			{

			}
			else if (cuphead->mBig == true)// 커질 때 콜라이더가 언더그라운드와 충돌하기에 예외처리 2
			{

			}
			else
			{
				cuphead->mCurHp = 0.0f;

				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				Collider* cupheadCol = cuphead->GetComponent<Collider>();
				Vector2 cupheadPos = cupheadCol->GetPos();

				Collider* groundCol = this->GetComponent<Collider>();
				Vector2 groundPos = groundCol->GetPos();

				float fLen = fabs(cupheadPos.y - groundPos.y);
				float fSize = (cupheadCol->GetSize().y / 2.0f) + (groundCol->GetSize().y / 2.0f);

				if (fLen < fSize)
				{
					Transform* cupTr = cuphead->GetComponent<Transform>();
					Transform* grTr = this->GetComponent<Transform>();

					Vector2 cupPos = cupTr->GetPos();
					Vector2 grPos = grTr->GetPos();

					cupPos.y -= (fSize - fLen) - 1.0f;
					cupTr->SetPos(cupPos);
				}
			}

		}
	}

	void UnderGround::OnCollisionStay(Collider* other)
	{
		if (dynamic_cast<Character01*>(other->GetOwner()))
		{
			Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
			if (cuphead->mState == eChar01State::BigRun)// 커질 때 콜라이더가 언더그라운드와 충돌하기에 예외처리 1
			{

			}
			else if (cuphead->mBig == true)// 커질 때 콜라이더가 언더그라운드와 충돌하기에 예외처리 2
			{

			}
			else
			{
				cuphead->mCurHp = 0.0f;

				Collider* cupheadCol = cuphead->GetComponent<Collider>();
				Vector2 cupheadPos = cupheadCol->GetPos();

				Collider* groundCol = this->GetComponent<Collider>();
				Vector2 groundPos = groundCol->GetPos();

				float fLen = fabs(cupheadPos.y - groundPos.y);
				float fSize = cupheadCol->GetSize().y;

				if (fLen < fSize)
				{
					Transform* cupTr = cuphead->GetComponent<Transform>();
					Transform* grTr = this->GetComponent<Transform>();

					Vector2 cupPos = cupTr->GetPos();
					Vector2 grPos = grTr->GetPos();

					cupPos.y -= fSize - fLen - 1.0f;
					cupTr->SetPos(cupPos);
				}
			}
		}
	}

	void UnderGround::OnCollisionExit(Collider* other)
	{

	}

}