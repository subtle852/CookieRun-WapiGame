#include "yaObstacle01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
//#include "yaBaseBullet.h"
#include "yaScene.h"
#include "yaCamera.h"

namespace ya
{
	Obstacle01::Obstacle01()
	{

	}

	Obstacle01::~Obstacle01()
	{

	}

	void Obstacle01::Initialize()
	{
		mImage = Resources::Load<Image>(L"Land1Slide01", L"..\\Resources\\land1\\land1_sl_0001.bmp");

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 520.0f));
		//collider->SetCenter(Vector2(0.0f, 250.0f));
		collider->SetCenter(Vector2(25.0f, 0.0f));

		GameObject::Initialize();
	}

	void Obstacle01::Update()
	{
		GameObject::Update();
	}

	void Obstacle01::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}

	void Obstacle01::Release()
	{
		GameObject::Release();
	}
	void Obstacle01::OnCollisionEnter(Collider* other)
	{
	}
	void Obstacle01::OnCollisionStay(Collider* other)
	{
	}
	void Obstacle01::OnCollisionExit(Collider* other)
	{
	}
}