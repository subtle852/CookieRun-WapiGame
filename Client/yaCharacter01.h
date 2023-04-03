#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Animator;
	class Rigidbody;

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
		BigRun,
	};

	class Character01 : public GameObject
	{
	public:
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
		static void IncreaseHP(float hp) { mCurHp += hp; }
		static void DecreaseHP(float hp) { mCurHp -= hp; }

	private:
		void run();
		void beforerun();
		void jump();
		void djump();
		void slide();
		void death();
		void idle();
		void transparent();
		void bigrun();

		void JumpCompleteEvent();
		void DJumpCompleteEvent();
		void SlideStarteEvent();
		void Transp1CompleteEvent();
		void DamagedCompleteEvent();
		void Transp2CompleteEvent();


	private:
		//eChar01State mState;
		Animator* mAnimator;
		Rigidbody* mRigidbody;

		int mJmpcnt = 0;
		int mDJmpcnt = 0;
		int mBJmpcnt = 0;

		//static float mCurHp;
		static float mMaxHp;
		static float mHpPercent;

	public:
		eChar01State mState;
		static float mCurHp;

		bool mFast = false; float mFastT = 0.0f; bool mFastFirst = false;
		bool mSlow = false; float mSlowT = 0.0f;
		bool mInv = false; float mInvT = 0.0f;
		static bool mBig; float mBigT = 0.0f; int mBcnt = 0;// mBig는 펫이 알아야해서 static으로 선언 
		static bool mSml; int mSmlcnt = 0;  float mSmlT = 0.0f;

		bool mGround = false; int mScnt = 0; bool mG = false;

		bool mKeyError = false; float mKeyErrorT = 0.0f;

		bool mMagnetState = false;

		bool mBtoB = false;
		bool mOtoC = false;

		bool mZom = true;
		float mZomWait = 0.0f;

		bool mPlayInit = false;
		bool mMakeInit = false;

		bool mStopbyFlag = false;
	};
}