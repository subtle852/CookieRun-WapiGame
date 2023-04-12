#include "yaSelect_BankerPair.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaScene.h"
#include "yaCamera.h"

namespace ya
{
	Select_BankerPair::Select_BankerPair()
	{

	}

	Select_BankerPair::~Select_BankerPair()
	{

	}

	void Select_BankerPair::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\result\\banker_p", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"resultbanker_p", true);

		GameObject::Initialize();
	}

	void Select_BankerPair::Update()
	{
		GameObject::Update();
	}

	void Select_BankerPair::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Select_BankerPair::Release()
	{
		GameObject::Release();
	}
}