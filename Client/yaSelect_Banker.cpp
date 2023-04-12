#include "yaSelect_Banker.h"
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
	Select_Banker::Select_Banker()
	{

	}

	Select_Banker::~Select_Banker()
	{

	}

	void Select_Banker::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\result\\banker", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"resultbanker", true);

		GameObject::Initialize();
	}

	void Select_Banker::Update()
	{
		GameObject::Update();
	}

	void Select_Banker::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Select_Banker::Release()
	{
		GameObject::Release();
	}
}