#include "yaPet01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	Pet01::Pet01()
	{

	}

	Pet01::~Pet01()
	{

	}

	void Pet01::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(300.0f, 400.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		Image* mImage = Resources::Load<Image>(L"Pet01", L"..\\Resources\\pet_idle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"idle", mImage, Vector2::Zero, 8, 5, 1, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Run", mImage, Vector2::Zero, 8, 5, 4, Vector2::Zero, 0.15);

		mAnimator->Play(L"Run", true);

		GameObject::Initialize();
	}

	void Pet01::Update()
	{
		GameObject::Update();
	}

	void Pet01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Pet01::Release()
	{
		GameObject::Release();
	}

}