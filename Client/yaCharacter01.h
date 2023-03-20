#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Animator;
	class Rigidbody;

	class Character01 : public GameObject
	{
	public:
		enum class eChar01State
		{
			Run,
			BeforeRun,
			Jump,
			DoubleJump,
			Slide,
			Death,
			Idle,
			Transp1,
			Transp2,
			Damaged,
		};


		Character01();
		~Character01();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		static float GetHpPercent() { return mHpPercent; }
		static void SetHp(float hp) { mCurHp = hp; }

	private:
		void run();
		void beforerun();
		void jump();
		void djump();
		void slide();
		void death();
		void idle();
		void transparent();

		void JumpCompleteEvent();
		void DJumpCompleteEvent();
		void SlideStarteEvent();
		void Transp1CompleteEvent();
		void DamagedCompleteEvent();
		void Transp2CompleteEvent();


	private:
		eChar01State mState;
		Animator* mAnimator;
		Rigidbody* mRigidbody;

		int mJmpcnt = 0;
		int mDJmpcnt = 0;

		static float mCurHp;
		static float mMaxHp;
		static float mHpPercent;
	};
}