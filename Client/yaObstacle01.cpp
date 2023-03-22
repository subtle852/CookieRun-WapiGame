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
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\land1\\slide", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"land1slide", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetSize(Vector2(120.0f, 520.0f));
		collider->SetCenter(Vector2(-60.0f, -550.0f));

		GameObject::Initialize();
	}

	void Obstacle01::Update()
	{
		GameObject::Update();
	}

	void Obstacle01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
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