#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Animator;
	class Character00 : public GameObject
	{
	public:
		enum class eChar00State
		{
			Run,
			Jump,
			Slide,
			Death,
			Idle,
		};


		Character00();
		~Character00();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		void run();
		void jump();
		void slide();
		void death();
		void idle();

		void idleCompleteEvent();

	private:
		eChar00State mState;
		Animator* mAnimator;
	};
}