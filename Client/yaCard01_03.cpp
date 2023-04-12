#include "yaCard01_03.h"
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
	Card01_03::Card01_03()
	{

	}

	Card01_03::~Card01_03()
	{

	}

	void Card01_03::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\03", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0103", true);

		GameObject::Initialize();
	}

	void Card01_03::Update()
	{
		GameObject::Update();
	}

	void Card01_03::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_03::Release()
	{
		GameObject::Release();
	}
}