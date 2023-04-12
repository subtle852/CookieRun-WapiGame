#include "yaSlotB03.h"
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
	SlotB03::SlotB03()
	{

	}

	SlotB03::~SlotB03()
	{

	}

	void SlotB03::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Slot\\Button3", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"SlotButton3", true);

		GameObject::Initialize();
	}

	void SlotB03::Update()
	{
		GameObject::Update();
	}

	void SlotB03::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void SlotB03::Release()
	{
		GameObject::Release();
	}
}