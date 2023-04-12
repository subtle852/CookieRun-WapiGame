#include "yaRacingB01.h"
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
	RacingB01::RacingB01()
	{

	}

	RacingB01::~RacingB01()
	{

	}

	void RacingB01::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Racing\\Button", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"RacingButton", true);

		GameObject::Initialize();
	}

	void RacingB01::Update()
	{
		GameObject::Update();
	}

	void RacingB01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void RacingB01::Release()
	{
		GameObject::Release();
	}
}