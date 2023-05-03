#include "yaOverGround.h"
#include "yaCollider.h"
#include "yaCharacter01.h"
#include "yaCharacter02.h"
#include "yaCharacter03.h"
#include "yaCharacter04.h"
#include "yaCharacter05.h"
#include "yaCharacter06.h"
#include "yaCharacter07.h"
#include "yaCharacter08.h"
#include "yaRigidbody.h"
#include "yaTransform.h"
#include "yaSelectCharScene.h"

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
		if (SelectCharScene::GetCharNumber() == 1)
		{
			Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
			{
				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				cuphead->mG = true;

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
		if (SelectCharScene::GetCharNumber() == 2)
		{
			Character02* cuphead = dynamic_cast<Character02*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
			{
				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				cuphead->mG = true;

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
		if (SelectCharScene::GetCharNumber() == 3)
		{
			Character03* cuphead = dynamic_cast<Character03*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
			{
				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				cuphead->mG = true;

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
		if (SelectCharScene::GetCharNumber() == 4)
		{
			Character04* cuphead = dynamic_cast<Character04*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
			{
				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				cuphead->mG = true;

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
		if (SelectCharScene::GetCharNumber() == 5)
		{
			Character05* cuphead = dynamic_cast<Character05*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
			{
				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				cuphead->mG = true;

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
		if (SelectCharScene::GetCharNumber() == 6)
		{
			Character06* cuphead = dynamic_cast<Character06*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
			{
				Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
				rb->SetGround(true);

				cuphead->mG = true;

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
		if (SelectCharScene::GetCharNumber() == 7)
		{
			Character07* cuphead = dynamic_cast<Character07*>(other->GetOwner());
		
			if (cuphead->mTransfState != true)
			{

				Collider* cupheadCol = cuphead->GetComponent<Collider>();
				Vector2 cupheadPos = cupheadCol->GetPos();

				Collider* groundCol = this->GetComponent<Collider>();
				Vector2 groundPos = groundCol->GetPos();

				if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
				{
					Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
					rb->SetGround(true);

					cuphead->mG = true;

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
		}
		if (SelectCharScene::GetCharNumber() == 8)
		{
			Character08* cuphead = dynamic_cast<Character08*>(other->GetOwner());
			
			if (cuphead->mTransfState != true)
			{
				Collider* cupheadCol = cuphead->GetComponent<Collider>();
				Vector2 cupheadPos = cupheadCol->GetPos();

				Collider* groundCol = this->GetComponent<Collider>();
				Vector2 groundPos = groundCol->GetPos();

				if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
				{
					Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
					rb->SetGround(true);

					cuphead->mG = true;

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
		}
	}

	void OverGround::OnCollisionStay(Collider* other)
	{
		if (SelectCharScene::GetCharNumber() == 1)
		{
			Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		if (SelectCharScene::GetCharNumber() == 2)
		{
			Character02* cuphead = dynamic_cast<Character02*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		if (SelectCharScene::GetCharNumber() == 3)
		{
			Character03* cuphead = dynamic_cast<Character03*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		if (SelectCharScene::GetCharNumber() == 4)
		{
			Character04* cuphead = dynamic_cast<Character04*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		if (SelectCharScene::GetCharNumber() == 5)
		{
			Character05* cuphead = dynamic_cast<Character05*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		if (SelectCharScene::GetCharNumber() == 6)
		{
			Character06* cuphead = dynamic_cast<Character06*>(other->GetOwner());
			Collider* cupheadCol = cuphead->GetComponent<Collider>();
			Vector2 cupheadPos = cupheadCol->GetPos();

			Collider* groundCol = this->GetComponent<Collider>();
			Vector2 groundPos = groundCol->GetPos();

			if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		if (SelectCharScene::GetCharNumber() == 7)
		{
			Character07* cuphead = dynamic_cast<Character07*>(other->GetOwner());
			
			if (cuphead->mTransfState != true)
			{
				Collider* cupheadCol = cuphead->GetComponent<Collider>();
				Vector2 cupheadPos = cupheadCol->GetPos();

				Collider* groundCol = this->GetComponent<Collider>();
				Vector2 groundPos = groundCol->GetPos();

				if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		}
		if (SelectCharScene::GetCharNumber() == 8)
		{
			Character08* cuphead = dynamic_cast<Character08*>(other->GetOwner());
			
			if (cuphead->mTransfState != true)
			{
				Collider* cupheadCol = cuphead->GetComponent<Collider>();
				Vector2 cupheadPos = cupheadCol->GetPos();

				Collider* groundCol = this->GetComponent<Collider>();
				Vector2 groundPos = groundCol->GetPos();

				if ((50.0f < groundPos.y - cupheadPos.y) && (groundPos.y - cupheadPos.y < 100.0f))
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
		}

	}

	void OverGround::OnCollisionExit(Collider* other)
	{
		if (SelectCharScene::GetCharNumber() == 1)
		{
			Character01* cuphead = dynamic_cast<Character01*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 2)
		{
			Character02* cuphead = dynamic_cast<Character02*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 3)
		{
			Character03* cuphead = dynamic_cast<Character03*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 4)
		{
			Character04* cuphead = dynamic_cast<Character04*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 5)
		{
			Character05* cuphead = dynamic_cast<Character05*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 6)
		{
			Character06* cuphead = dynamic_cast<Character06*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 7)
		{
			Character07* cuphead = dynamic_cast<Character07*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
		if (SelectCharScene::GetCharNumber() == 8)
		{
			Character08* cuphead = dynamic_cast<Character08*>(other->GetOwner());
			Rigidbody* rb = cuphead->GetComponent<Rigidbody>();
			rb->SetGround(false);
		}
	}

}