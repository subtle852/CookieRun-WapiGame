#include "yaF_9.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_9::F_9()
	{

	}

	F_9::~F_9()
	{

	}

	void F_9::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(1200.0f, 500.0f));
		tr->SetScale(Vector2(0.6f, 0.6f));

		Scene* scn = SceneManager::GetActiveScene();
		if (scn->GetName() == L"ResultF" || scn->GetName() == L"ResultS")
		{
			tr->SetScale(Vector2(1.5f, 1.5f));
		}

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\9", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font9", true);

		GameObject::Initialize();
	}

	void F_9::Update()
	{
		GameObject::Update();
	}

	void F_9::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_9::Release()
	{
		GameObject::Release();
	}
	void F_9::OnCollisionEnter(Collider* other)
	{
	}
	void F_9::OnCollisionStay(Collider* other)
	{
	}
	void F_9::OnCollisionExit(Collider* other)
	{
	}
}