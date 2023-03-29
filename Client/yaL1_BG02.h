#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Animator;

	class L1_BG02 : public GameObject
	{
	public:
		L1_BG02();
		~L1_BG02();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		Animator* mAnimator;
	};
}