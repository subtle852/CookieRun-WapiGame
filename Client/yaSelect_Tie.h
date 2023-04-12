#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Select_Tie : public GameObject
	{
	public:
		Select_Tie();
		~Select_Tie();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}