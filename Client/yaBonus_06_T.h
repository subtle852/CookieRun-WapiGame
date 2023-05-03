#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Bonus_06_T : public GameObject
	{
	public:
		Bonus_06_T();
		~Bonus_06_T();

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