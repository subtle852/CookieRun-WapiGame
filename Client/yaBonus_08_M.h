#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Bonus_08_M : public GameObject
	{
	public:
		Bonus_08_M();
		~Bonus_08_M();

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