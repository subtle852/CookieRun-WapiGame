#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class SlotB03 : public GameObject
	{
	public:
		SlotB03();
		~SlotB03();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}