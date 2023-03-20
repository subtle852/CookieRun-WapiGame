#include "yaObstacle.h"
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
	Obstacle::Obstacle()
	{

	}

	Obstacle::~Obstacle()
	{

	}

	void Obstacle::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\land1\\jump", Vector2::Zero, 0.1f);

		mAnimator->Play(L"land1jump", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 200.0f));
		collider->SetCenter(Vector2(-60.0f, -200.0f));

		GameObject::Initialize();
	}

	void Obstacle::Update()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//pos.x -= 700.0f * Time::DeltaTime();
		
		//tr->SetPos(pos);

		GameObject::Update();
	}

	void Obstacle::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Obstacle::Release()
	{
		GameObject::Release();
	}
	void Obstacle::OnCollisionEnter(Collider* other)
	{
	}
	void Obstacle::OnCollisionStay(Collider* other)
	{
	}
	void Obstacle::OnCollisionExit(Collider* other)
	{
	}
}