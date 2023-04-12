#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;
	class SlotB02 : public GameObject
	{
	public:
		SlotB02();
		~SlotB02();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
	};
}