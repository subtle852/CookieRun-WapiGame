#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Select_Player : public GameObject
	{
	public:
		Select_Player();
		~Select_Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}