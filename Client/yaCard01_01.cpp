#include "yaCard01_01.h"
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
	Card01_01::Card01_01()
	{

	}

	Card01_01::~Card01_01()
	{

	}

	void Card01_01::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\01", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0101", true);

		GameObject::Initialize();
	}

	void Card01_01::Update()
	{
		GameObject::Update();
	}

	void Card01_01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_01::Release()
	{
		GameObject::Release();
	}
}