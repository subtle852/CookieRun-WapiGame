#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Bear_SmallPink : public GameObject
	{
	public:
		Bear_SmallPink();
		~Bear_SmallPink();

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