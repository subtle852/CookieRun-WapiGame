#include "yaSlotB01.h"
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
	SlotB01::SlotB01()
	{

	}

	SlotB01::~SlotB01()
	{

	}

	void SlotB01::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Slot\\Button1", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"SlotButton1", true);

		GameObject::Initialize();
	}

	void SlotB01::Update()
	{
		GameObject::Update();
	}

	void SlotB01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void SlotB01::Release()
	{
		GameObject::Release();
	}
}