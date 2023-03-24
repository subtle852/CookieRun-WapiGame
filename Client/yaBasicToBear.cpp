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
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mImage = Resources::Load<Image>(L"pt", L"..\\Resources\\item03_fast.bmp");

		GameObject::Initialize();
	}

	void BasicToBear::Update()
	{
		GameObject::Update();
	}

	void BasicToBear::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();

		Vector2 renderPos = Camera::CaluatePos(tr->GetPos());

		TransparentBlt(hdc, renderPos.x, renderPos.y, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
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
			object::Destory(this);
		}
	}

	void BasicToBear::OnCollisionExit(Collider* other)
	{

	}
}