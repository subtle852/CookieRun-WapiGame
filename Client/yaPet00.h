#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Animator;
	class Pet00 : public GameObject
	{
	public:
		enum class ePet00State
		{
			Run,
			Jump,
			Slide,
			Idle,
		};


		Pet00();
		~Pet00();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		void run();
		void jump();
		void slide();
		void idle();

		//void idleCompleteEvent();

	private:
		ePet00State mState;
		Animator* mAnimator;
	};
}