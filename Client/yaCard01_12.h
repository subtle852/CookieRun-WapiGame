#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Card01_12 : public GameObject
	{
	public:
		Card01_12();
		~Card01_12();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}