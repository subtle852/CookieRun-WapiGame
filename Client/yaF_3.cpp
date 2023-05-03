#include "yaF_3.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_3::F_3()
	{

	}

	F_3::~F_3()
	{

	}

	void F_3::Initialize()
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
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\3", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font3", true);

		GameObject::Initialize();
	}

	void F_3::Update()
	{
		GameObject::Update();
	}

	void F_3::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_3::Release()
	{
		GameObject::Release();
	}
	void F_3::OnCollisionEnter(Collider* other)
	{
	}
	void F_3::OnCollisionStay(Collider* other)
	{
	}
	void F_3::OnCollisionExit(Collider* other)
	{
	}
}