#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class SlotB01 : public GameObject
	{
	public:
		SlotB01();
		~SlotB01();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}