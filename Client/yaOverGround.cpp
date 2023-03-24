#include "yaOverGround.h"
#include "yaCollider.h"
#include "yaCharacter01.h"
#include "yaRigidbody.h"
#include "yaTransform.h"

namespace ya
{
	OverGround::OverGround()
	{
	}

	OverGround::~OverGround()
	{
	}

	void OverGround::Initialize()
	{
		//mCollider = AddComponent<Collider>();
		//mCollider->SetSize(Vector2(80000.0f, 50.0f));
		GameObject::Initialize();
	}

	void OverGround::Update()
	{
		GameObject::Update();
	}

	void OverGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void OverGround::Release()
	{
	}

	void OverGround::OnCollisionEnter(Collider* other)
	{
		Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
		if (cuphead == nullptr)
			return;

		Collider* cupheadCol = cuphead->GetComponent<Collider>();
		Vector2 cupheadPos = cupheadCol->GetPos();

		Collider* groundCol = this->GetComponent<Collider>();
		Vector2 groundPos = groundCol->GetPos();
		
		if((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
		//if (cuphead->mOver == true)
		{
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

				cupPos -= (fSize - fLen) - 1.0f;
				cupTr->SetPos(cupPos);
			}
		}
	}

	void OverGround::OnCollisionStay(Collider* other)
	{
		Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
		if (cuphead == nullptr)
			return;

		Collider* cupheadCol = cuphead->GetComponent<Collider>();
		Vector2 cupheadPos = cupheadCol->GetPos();

		Collider* groundCol = this->GetComponent<Collider>();
		Vector2 groundPos = groundCol->GetPos();

		if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
		//if (cuphead->mOver == true)
		{
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

	void OverGround::OnCollisionExit(Collider* other)
	{
		Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
		if (cuphead == nullptr)
			return;

		cuphead->mOver = true;

		Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
		rb->SetGround(false);
	}

}