#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Card01_05 : public GameObject
	{
	public:
		Card01_05();
		~Card01_05();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}