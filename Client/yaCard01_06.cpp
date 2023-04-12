#include "yaCard01_06.h"
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
	Card01_06::Card01_06()
	{

	}

	Card01_06::~Card01_06()
	{

	}

	void Card01_06::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\06", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0106", true);

		GameObject::Initialize();
	}

	void Card01_06::Update()
	{
		GameObject::Update();
	}

	void Card01_06::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_06::Release()
	{
		GameObject::Release();
	}
}