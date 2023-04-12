#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Card01_10 : public GameObject
	{
	public:
		Card01_10();
		~Card01_10();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}