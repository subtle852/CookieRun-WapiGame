#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class L1_DP03 : public GameObject
	{
	public:
		L1_DP03();
		~L1_DP03();

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