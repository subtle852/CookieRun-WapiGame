#include "yaCard01_00.h"
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
	Card01_00::Card01_00()
	{

	}

	Card01_00::~Card01_00()
	{

	}

	void Card01_00::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\00", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0100", true);

		GameObject::Initialize();
	}

	void Card01_00::Update()
	{
		GameObject::Update();
	}

	void Card01_00::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_00::Release()
	{
		GameObject::Release();
	}
}