#include "yaCard01_05.h"
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
	Card01_05::Card01_05()
	{

	}

	Card01_05::~Card01_05()
	{

	}

	void Card01_05::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\05", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0105", true);

		GameObject::Initialize();
	}

	void Card01_05::Update()
	{
		GameObject::Update();
	}

	void Card01_05::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_05::Release()
	{
		GameObject::Release();
	}
}