#include "yaF_0.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_0::F_0()
	{

	}

	F_0::~F_0()
	{

	}

	void F_0::Initialize()
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
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\0", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font0", true);

		GameObject::Initialize();
	}

	void F_0::Update()
	{
		GameObject::Update();
	}

	void F_0::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_0::Release()
	{
		GameObject::Release();
	}
	void F_0::OnCollisionEnter(Collider* other)
	{
	}
	void F_0::OnCollisionStay(Collider* other)
	{
	}
	void F_0::OnCollisionExit(Collider* other)
	{
	}
}