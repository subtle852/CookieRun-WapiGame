#include "yaCard01_02.h"
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
	Card01_02::Card01_02()
	{

	}

	Card01_02::~Card01_02()
	{

	}

	void Card01_02::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\02", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0102", true);

		GameObject::Initialize();
	}

	void Card01_02::Update()
	{
		GameObject::Update();
	}

	void Card01_02::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_02::Release()
	{
		GameObject::Release();
	}
}