#include "yaCard01_11.h"
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
	Card01_11::Card01_11()
	{

	}

	Card01_11::~Card01_11()
	{

	}

	void Card01_11::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\11", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0111", true);

		GameObject::Initialize();
	}

	void Card01_11::Update()
	{
		GameObject::Update();
	}

	void Card01_11::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_11::Release()
	{
		GameObject::Release();
	}
}