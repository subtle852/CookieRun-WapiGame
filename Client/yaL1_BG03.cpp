#include "yaL1_BG03.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	L1_BG03::L1_BG03()
	{

	}

	L1_BG03::~L1_BG03()
	{

	}

	void L1_BG03::Initialize()
	{
		mAnimator = AddComponent<Animator>();

		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(600.0f, 700.0f));
		tr->SetScale(Vector2(2.5f, 2.5f));

		mAnimator->CreateAnimations(L"..\\Resources\\Land1\\BG\\1_03", Vector2::Zero, 0.1f, 0);
		mAnimator->Play(L"BG1_03", false);

		GameObject::Initialize();
	}

	void L1_BG03::Update()
	{
		GameObject::Update();
	}

	void L1_BG03::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void L1_BG03::Release()
	{
		GameObject::Release();
	}
}