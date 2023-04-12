#include "yaSelect_Player.h"
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
	Select_Player::Select_Player()
	{

	}

	Select_Player::~Select_Player()
	{

	}

	void Select_Player::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\result\\player", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"resultplayer", true);

		GameObject::Initialize();
	}

	void Select_Player::Update()
	{
		GameObject::Update();
	}

	void Select_Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Select_Player::Release()
	{
		GameObject::Release();
	}
}