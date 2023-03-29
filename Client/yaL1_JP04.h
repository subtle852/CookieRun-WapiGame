#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class L1_JP04 : public GameObject
	{
	public:
		L1_JP04();
		~L1_JP04();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		Animator* mAnimator;
	};
}