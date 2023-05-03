#include "yaF_8.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"
#include "yaCharacter01.h"

namespace ya
{
	F_8::F_8()
	{

	}

	F_8::~F_8()
	{

	}

	void F_8::Initialize()
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
		mAnimator->CreateAnimations(L"..\\Resources\\Font\\8", Vector2::Zero, 0.1f, 0);

		mAnimator->Play(L"Font8", true);

		GameObject::Initialize();
	}

	void F_8::Update()
	{
		GameObject::Update();
	}

	void F_8::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void F_8::Release()
	{
		GameObject::Release();
	}
	void F_8::OnCollisionEnter(Collider* other)
	{
	}
	void F_8::OnCollisionStay(Collider* other)
	{
	}
	void F_8::OnCollisionExit(Collider* other)
	{
	}
}