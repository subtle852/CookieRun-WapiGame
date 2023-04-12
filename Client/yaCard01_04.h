#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Card01_04 : public GameObject
	{
	public:
		Card01_04();
		~Card01_04();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}