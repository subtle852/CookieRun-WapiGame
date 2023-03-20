#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class JellyCoin : public GameObject
	{
	public:
		JellyCoin();
		~JellyCoin();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		Animator* mAnimator;

	public:
		bool ok;
	};
}