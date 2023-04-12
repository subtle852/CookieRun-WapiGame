#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Card01_11 : public GameObject
	{
	public:
		Card01_11();
		~Card01_11();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}