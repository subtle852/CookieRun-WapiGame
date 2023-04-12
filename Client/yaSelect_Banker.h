#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class Select_Banker : public GameObject
	{
	public:
		Select_Banker();
		~Select_Banker();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}