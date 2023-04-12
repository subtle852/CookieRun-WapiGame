#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Select_PlayerPair : public GameObject
	{
	public:
		Select_PlayerPair();
		~Select_PlayerPair();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}