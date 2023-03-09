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

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		void run();
		void jump();
		void slide();
		void death();
		void idle();

		void JumpCompleteEvent();
		void SlideCompleteEvent();

	private:
		eChar00State mState;
		Animator* mAnimator;
	};
}