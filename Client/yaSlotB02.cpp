#include "yaSlotB02.h"
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
	SlotB02::SlotB02()
	{

	}

	SlotB02::~SlotB02()
	{

	}

	void SlotB02::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Slot\\Button2", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"SlotButton2", true);

		GameObject::Initialize();
	}

	void SlotB02::Update()
	{
		GameObject::Update();
	}

	void SlotB02::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void SlotB02::Release()
	{
		GameObject::Release();
	}
}