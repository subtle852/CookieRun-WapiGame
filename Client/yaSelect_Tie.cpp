#include "yaSelect_Tie.h"
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
	Select_Tie::Select_Tie()
	{

	}

	Select_Tie::~Select_Tie()
	{

	}

	void Select_Tie::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\result\\tie", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"resulttie", true);

		GameObject::Initialize();
	}

	void Select_Tie::Update()
	{
		GameObject::Update();
	}

	void Select_Tie::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Select_Tie::Release()
	{
		GameObject::Release();
	}
}