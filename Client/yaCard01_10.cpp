#include "yaCard01_10.h"
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
	Card01_10::Card01_10()
	{

	}

	Card01_10::~Card01_10()
	{

	}

	void Card01_10::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\10", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0110", true);

		GameObject::Initialize();
	}

	void Card01_10::Update()
	{
		GameObject::Update();
	}

	void Card01_10::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_10::Release()
	{
		GameObject::Release();
	}
}