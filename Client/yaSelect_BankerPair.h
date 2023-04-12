#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Select_BankerPair : public GameObject
	{
	public:
		Select_BankerPair();
		~Select_BankerPair();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}