#pragma once
#include "yaGameObject.h"
#include "yaCharacter01.h"
#include "yaImage.h"

namespace ya
{
	class Animator;
	class Rigidbody;

	enum class eChar02State
	{
		Run,
		BeforeRun,
		Jump,
		DoubleJump,
		Slide,
		Death,
		Idle,
		Transp1,// 이거 필요없음
		Transp2,// 이거 필요없음
		Damaged,
		BigRun,
		Up,
		Down,
	};

	class Character02 : public Character01
	{
	public:
		Character02();
		~Character02();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		static float GetHpPercent() { return (Character02::mCurHp / Character02::mMaxHp) * 100; }
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
		void transparent();// 이거 필요없음
		void bigrun();
		void up();
		void down();

		void JumpCompleteEvent();
		void DJumpCompleteEvent();
		void SlideStarteEvent();
		void Transp1CompleteEvent();// 이거 필요없음
		void DamagedCompleteEvent();// 이거 필요없음
		void Transp2CompleteEvent();// 이거 필요없음


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
		eChar02State mState;
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
		bool mBonusInit = false;

		bool mStopbyFlag = false;

		float mWaitTime = 0.0f;
	};
}