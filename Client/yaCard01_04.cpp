#include "yaCard01_04.h"
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
	Card01_04::Card01_04()
	{

	}

	Card01_04::~Card01_04()
	{

	}

	void Card01_04::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\04", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0104", true);

		GameObject::Initialize();
	}

	void Card01_04::Update()
	{
		GameObject::Update();
	}

	void Card01_04::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_04::Release()
	{
		GameObject::Release();
	}
}