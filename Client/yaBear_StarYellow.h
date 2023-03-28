#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Bear_StarYellow : public GameObject
	{
	public:
		Bear_StarYellow();
		~Bear_StarYellow();

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