#include "yaCollider.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaCamera.h"

namespace ya
{
	UINT Collider::ColliderNumber = 0;
	Collider::Collider()
		: Component(eComponentType::Collider)
		, mCenter(Vector2::Zero)
		, mPos(Vector2::Zero)
		, mSize(100.0f, 100.0f)
		, mID(ColliderNumber++)
		, practice(0)
	{

	}

	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		mPos = tr->GetPos() + mCenter;
	}

	void Collider::Render(HDC hdc)
	{
		HPEN pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));

		if(practice)
			pen = CreatePen(BS_SOLID, 2, RGB(255, 0, 0));

		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Vector2 pos = Camera::CaluatePos(mPos);
		Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y);

		(HPEN)SelectObject(hdc, oldPen);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(pen);
	}
	void Collider::Release()
	{
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		++practice;
		GetOwner()->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}
	void Collider::OnCollisionExit(Collider* other)
	{
		--practice;
		GetOwner()->OnCollisionExit(other);
	}
}