#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Obstacle01 : public GameObject
	{
	public:
		Obstacle01();
		~Obstacle01();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		Animator* mAnimator;
		
		float mTime = 0.0f;
	};
}