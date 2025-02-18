#include "yaCard01_07.h"
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
	Card01_07::Card01_07()
	{

	}

	Card01_07::~Card01_07()
	{

	}

	void Card01_07::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Baccarat\\cards\\C_01\\07", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"C_0107", true);

		GameObject::Initialize();
	}

	void Card01_07::Update()
	{
		GameObject::Update();
	}

	void Card01_07::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Card01_07::Release()
	{
		GameObject::Release();
	}
}