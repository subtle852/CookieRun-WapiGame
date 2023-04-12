#include "yaSlotBs.h"
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
	SlotBs::SlotBs()
	{

	}

	SlotBs::~SlotBs()
	{

	}

	void SlotBs::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Slot\\ButtonS", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"SlotButtonS", true);

		GameObject::Initialize();
	}

	void SlotBs::Update()
	{
		GameObject::Update();
	}

	void SlotBs::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void SlotBs::Release()
	{
		GameObject::Release();
	}
}