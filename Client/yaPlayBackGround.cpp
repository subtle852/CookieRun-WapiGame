#include "yaPlayBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"

namespace ya
{
	PlayBackGround::PlayBackGround()
	{

	}

	PlayBackGround::~PlayBackGround()
	{

	}

	void PlayBackGround::Initialize()
	{
		mAnimator = AddComponent<Animator>();

		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(600.0f, 700.0f));
		tr->SetScale(Vector2(2.4f, 2.4f));

		mAnimator->CreateAnimations(L"..\\Resources\\Map\\Land1", Vector2::Zero, 0.1f, 0);
		mAnimator->Play(L"MapLand1", false);

		GameObject::Initialize();
	}

	void PlayBackGround::Update()
	{
		GameObject::Update();
	}

	void PlayBackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void PlayBackGround::Release()
	{
		GameObject::Release();
	}
}