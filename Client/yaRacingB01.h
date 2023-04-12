#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class RacingB01 : public GameObject
	{
	public:
		RacingB01();
		~RacingB01();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}