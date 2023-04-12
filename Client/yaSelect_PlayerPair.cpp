#include "yaSelect_PlayerPair.h"
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
	Select_PlayerPair::Select_PlayerPair()
	{

	}

	Select_PlayerPair::~Select_PlayerPair()
	{

	}

	void Select_PlayerPair::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\result\\player_p", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"resultplayer_p", true);

		GameObject::Initialize();
	}

	void Select_PlayerPair::Update()
	{
		GameObject::Update();
	}

	void Select_PlayerPair::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Select_PlayerPair::Release()
	{
		GameObject::Release();
	}
}