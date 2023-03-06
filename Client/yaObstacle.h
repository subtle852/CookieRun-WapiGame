#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Obstacle : public GameObject
	{
	public:
		Obstacle();
		~Obstacle();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}