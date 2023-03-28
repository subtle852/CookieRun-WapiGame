#include "yaGround.h"
#include "yaCollider.h"
#include "yaCharacter01.h"
#include "yaRigidbody.h"
#include "yaTransform.h"

namespace ya
{
	Ground::Ground()
	{
	}

	Ground::~Ground()
	{
	}

	void Ground::Initialize()
	{
		//mCollider = AddComponent<Collider>();
		//mCollider->SetSize(Vector2(1000.0f, 50.0f));
		GameObject::Initialize();
	}

	void Ground::Update()
	{
		GameObject::Update();
	}

	void Ground::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Ground::Release()
	{
	}

	void Ground::OnCollisionEnter(Collider* other)
	{
		Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
		if (cuphead == nullptr)
			return;

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

	void Ground::OnCollisionStay(Collider* other)
	{
		Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
		if (cuphead == nullptr)
			return;

		//Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
		//rb->SetGround(true);

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

	void Ground::OnCollisionExit(Collider* other)
	{
		Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
		if (cuphead == nullptr)
			return;

		//Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
		//rb->SetGround(false);
	}

}