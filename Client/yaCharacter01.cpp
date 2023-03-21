#include "yaCharacter01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaRigidbody.h"
#include "yaCamera.h"

#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaGround.h"
#include "yaUnderGround.h"

namespace ya
{
	float Character01::mCurHp = 100;
	float Character01::mMaxHp = 100;
	float Character01::mHpPercent = (Character01::mCurHp / Character01::mMaxHp) * 100;

	Character01::Character01()
	{

	}
	Character01::~Character01()
	{

	}
	void Character01::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector2(1.2f, 1.2f));

		Image* mImage = Resources::Load<Image>(L"Char01", L"..\\Resources\\Char\\idle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"idle", mImage, Vector2((290.0f * 1), (290.0f * 2)), 11, 6, 4, Vector2::Zero, 0.13, 0);
		mAnimator->CreateAnimation(L"Roll", mImage, Vector2::Zero, 11, 6, 6, Vector2::Zero, 0.15, 0);
		mAnimator->CreateAnimation(L"BeforeRun", mImage, Vector2((290.0f * 6), (290.0f * 0)), 11, 6, 1, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Run", mImage, Vector2(0.0f, (290.0f * 1)), 11, 6, 4, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"FastRun", mImage, Vector2((290.0f * 4), (290.0f * 1)), 11, 6, 4, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"SlowRun", mImage, Vector2(0.0f, (290.0f * 1)), 11, 6, 4, Vector2::Zero, 0.5, 0);
		mAnimator->CreateAnimation(L"Jump", mImage, Vector2((290.0f * 0), (290.0f * 0)), 11, 6, 1, Vector2::Zero, 0.1, 0);// 0에 가까울수록 애니메이션 빨리 동작
		mAnimator->CreateAnimation(L"DJump", mImage, Vector2((290.0f * 1), (290.0f * 0)), 11, 6, 6, Vector2::Zero, 0.08, 0);
		mAnimator->CreateAnimation(L"Slide", mImage, Vector2((290.0f * 9), (290.0f * 0)), 11, 6, 2, Vector2::Zero, 0.08, 0);
		mAnimator->CreateAnimation(L"Death", mImage, Vector2((290.0f * 0), (290.0f * 4)), 11, 6, 4, Vector2::Zero, 0.15, 0);
		mAnimator->CreateAnimation(L"Transp1", mImage, Vector2((290.0f * 9), (290.0f * 1)), 11, 6, 2, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Transp2", mImage, Vector2((290.0f * 9), (290.0f * 1)), 11, 6, 2, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Damaged", mImage, Vector2(0.0f, (290.0f * 4)), 11, 6, 1, Vector2::Zero, 0.2, 0);
		//mAnimator->CreateAnimations(L"..\\Resorces\\Chalise\\Idle", Vector2::Zero, 0.1f);


		mAnimator->GetCompleteEvent(L"Jump") = std::bind(&Character01::JumpCompleteEvent, this);
		mAnimator->GetCompleteEvent(L"DJump") = std::bind(&Character01::DJumpCompleteEvent, this);
		mAnimator->GetStartEvent(L"Slide") = std::bind(&Character01::SlideStarteEvent, this);
		mAnimator->GetCompleteEvent(L"Transp1") = std::bind(&Character01::Transp1CompleteEvent, this);
		mAnimator->GetCompleteEvent(L"Transp2") = std::bind(&Character01::Transp2CompleteEvent, this);
		mAnimator->GetCompleteEvent(L"Damaged") = std::bind(&Character01::DamagedCompleteEvent, this);

		Scene* scn = SceneManager::GetActiveScene();

		if (scn->GetName() == L"Main")
		{
			mAnimator->Play(L"idle", true);
		}
		
		if (scn->GetName() == L"Play")
		{
			Transform* tr = GetComponent<Transform>();
			tr->SetScale(Vector2(1.2f, 1.2f));

			Collider* collider = AddComponent<Collider>();
			collider->SetSize(Vector2(100.0f, 100.0f));
			collider->SetCenter(Vector2(-10.0f, -50.0f));

			mRigidbody = AddComponent<Rigidbody>();
			mRigidbody->SetMass(1.0f);

			mState = eChar01State::Run;
		}

		GameObject::Initialize();
	}
	void Character01::Update()
	{
		GameObject::Update();

		Scene* scn = SceneManager::GetActiveScene();
		if (scn->GetName() == L"Play")
		{
			if (mState != eChar01State::Death)
			{
				if (mFast == false && mSlow == false)// 속도 아이템 먹지 않는 경우의 속도
				{
					Transform* tr = GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += 550.0f * Time::DeltaTime();
					tr->SetPos(pos);
				}

				else if (mFast == true)// Fast 아이템 먹었을 때
				{
					mFastT += Time::DeltaTime();

					//mAnimator->Play(L"FastRun", true);
					Transform* tr = GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += 1000.0f * Time::DeltaTime();
					tr->SetPos(pos);

					if (mFastT > 2.0f)
					{
						mFastT = 0.0f;
						mFast = false;
					}
				}

				else if (mSlow == true)// slow 아이템 먹었을 때
				{
					mSlowT += Time::DeltaTime();

					//mAnimator->Play(L"FastRun", true);
					Transform* tr = GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += 100.0f * Time::DeltaTime();
					tr->SetPos(pos);

					if (mSlowT > 2.0f)
					{
						mSlowT = 0.0f;
						mSlow = false;
					}
				}
			}

			{
				if (mInv == false)
				{
					Character01::mCurHp -= 1.0f * Time::DeltaTime();
				}
				else// 무적 아이템 먹었을 때
				{
					mInvT += Time::DeltaTime();

					if (mInvT > 2.0f)
					{
						mInvT = 0.0f;
						mInv = false;
					}
				}
			}

			{
				if (mState == eChar01State::BigRun || mState == eChar01State::BigJump || mState == eChar01State::BigSlide)// 커졌을 때
				{
					mBig = true;
					mBigT += Time::DeltaTime();

					if (mBigT > 5.0f)
					{
						mBigT = 0.0f;
						mBig = false;

						Transform* tr = GetComponent<Transform>();
						tr->SetScale(Vector2(1.2f, 1.2f));
						mState = eChar01State::Run;
					}
				}
			}

			// 현재 체력 예외 처리
			if (Character01::mCurHp <= 0.0f)
			{
				mCurHp = 0.0f;
				mState = eChar01State::Death;
			}
			if (Character01::mCurHp > 100.0f)
			{
				mCurHp = 100.0f;
			}

			// 현재 체력 퍼센트 계산
			Character01::mHpPercent = (Character01::mCurHp / Character01::mMaxHp) * 100;

			// 상태에 따른 상태 함수 실행하는 스위치문
			switch (mState)
			{
			case ya::eChar01State::Run:
				run();
				break;
			case ya::eChar01State::BeforeRun:
				beforerun();
				break;
			case ya::eChar01State::Jump:
				jump();
				break;
			case ya::eChar01State::DoubleJump:
				djump();
				break;
			case ya::eChar01State::Slide:
				slide();
				break;
			case ya::eChar01State::Death:
				death();
				break;
			case ya::eChar01State::Idle:
				idle();
				break;
			case ya::eChar01State::Transp1:
				transparent();
				break;
			case ya::eChar01State::Transp2:
				mAnimator->Play(L"Transp2", true);
				break;
			case ya::eChar01State::Damaged:
				mAnimator->Play(L"Damaged", true);
				break;
			case ya::eChar01State::BigRun:
				bigrun();
				break;
			case ya::eChar01State::BigJump:
				bigjump();
				break;
			case ya::eChar01State::BigSlide:
				bigslide();
				break;
			}
		}

		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();

		//Animator* animator = GetComponent<Animator>();

		//if (Input::GetKeyState(eKeyCode::A) == eKeyState::Down)
		//{
		//	pos.x -= 100.0f * Time::DeltaTime();
		//}

		//if (mTime > 2.0f)
		//{
		//	object::Destory(this);
		//} 
		// 이렇게 길이 조정 가능 2초뒤면 사라지도록(이 부분은 3월 8일 01:25 영상 참고 or Delete Object 깃 참조)
	}

	void Character01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Character01::Release()
	{
		GameObject::Release();
	}

	void Character01::OnCollisionEnter(Collider* other)
	{
		//if (dynamic_cast<Obstacle*>(other->GetOwner()))
		//{
		//	mState = eChar01State::Transp1;
		//}

		{
			if (mFast == true) {}
			else if (mInv == true) {}
			else if (mBig == true) {}
			else// 위는 빠르게, 무적, 커지게 상태에서 Obstacle과 부딪히면 피가 줄어들지 않는 경우로 제외시킨 것
			{

				if (dynamic_cast<Obstacle*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<Obstacle01*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
			}
		}

		if (dynamic_cast<UnderGround*>(other->GetOwner()))
		{
			if (mState == eChar01State::BigRun || mState == eChar01State::BigJump)// 커질 때 콜라이더가 언더그라운드와 충돌하기에 예외처리 1
			{

			}
			else if(mBig == false)// 커질 때 콜라이더가 언더그라운드와 충돌하기에 예외처리 2
			{

			}
			else// 지하바닥과 충돌할때 Hp 0으로
			{
				mCurHp = 0;
			}
		}
	
	}

	void Character01::OnCollisionStay(Collider* other)
	{
		if (mBig == true && dynamic_cast<Ground*>(other->GetOwner()))// 커졌을 때 바로 카메라 흔들리고, 커진 상태에서 점프하고 땅에 닿으면 카메라 흔들리게 
		{
			Camera::mType = Camera::eCameraEffectType::ShakeH;
		}
	}

	void Character01::OnCollisionExit(Collider* other)
	{
	}

	void Character01::run()
	{
		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(100.0f, 100.0f));
		collider->SetCenter(Vector2(-10.0f, -50.0f));

		mDJmpcnt = 0;

		{
			if (mFast == false && mSlow == false)
			{
				mAnimator->Play(L"Run", true);
			}
			else if (mFast == true)
			{
				mAnimator->Play(L"FastRun", true);
			}
			else if (mSlow == true)
			{
				mAnimator->Play(L"SlowRun", true);
			}
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			mState = eChar01State::Slide;
		}

		if (Input::GetKeyDown(eKeyCode::W))
		{
			mJmpcnt++;

			if (mJmpcnt == 1)
			{
				Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -2200.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);
				mState = eChar01State::Jump;
			}
		}

		//if (Input::GetKey(eKeyCode::A))
		//{
		//	pos.x -= 100.0f * Time::DeltaTime();
		//}
		//
		//if (Input::GetKey(eKeyCode::D))
		//{
		//	pos.x += 100.0f * Time::DeltaTime();

		//	//// 회전
		//	//Transform* tr = GetComponent<Transform>();
		//	//float x = cosf(-PI / 4.0f);
		//	//float y = sinf(-PI / 4.0f);
		//	//
		//	//pos.x += 100.0f * x * Time::DeltaTime();
		//	//pos.y += 100.0f * y * Time::DeltaTime();
		//	//tr->SetPos(pos);
		//	//
		//	//// 벡터 회전
		//	//Transform* tr = GetComponent<Transform>();
		//	//Vector2 dir(1.0f, 1.0f);
		//	//
		//	//float x = dir.x * cosf(PI / 4.0f) - dir.y * sinf(PI / 4.0f);
		//	//float y = dir.x * sinf(PI / 4.0f) + dir.y * cosf(PI / 4.0f);
		//	//
		//	//Vector2 pos = tr->GetPos();
		//	//pos.x += 100.0f * x * Time::DeltaTime();
		//	//pos.y += 100.0f * y * Time::DeltaTime();
		//	//
		//	//tr->SetPos(pos);
		//	//
		//	//// 벡터 회전이 필요없는 경우, 그 위치에 그냥 몬스터가 있으면
		//	//Transform* tr = GetComponent<Transform>();
		//	//Vector2 dir = Vector2(500.0f, 500.0f) - tr->GetPos();
		//	//dir.Normalize();
		//	//
		//	//Vector2 pos = tr->GetPos();
		//	//pos.x += 100.0f * dir.x * Time::DeltaTime();
		//	//pos.y += 100.0f * dir.y * Time::DeltaTime();
		//	//tr->SetPos(pos);
		//}
	}

	void Character01::beforerun()
	{

		mAnimator->Play(L"BeforeRun", false);

		if (!mRigidbody->GetGround() && Input::GetKeyDown(eKeyCode::W))
		{
			mDJmpcnt++;

			if (mDJmpcnt == 1)
			{
				Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -2200.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);
				mState = eChar01State::DoubleJump;
			}
		}

		if (mRigidbody->GetGround())
		{
			mRigidbody->mVelocity = Vector2(0.0f, 0.0f);

			mState = eChar01State::Run;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar01State::Slide;
		}
	}

	void Character01::jump()
	{
		mJmpcnt = 0;

		mAnimator->Play(L"Jump", true);

		if (!mRigidbody->GetGround() && Input::GetKeyDown(eKeyCode::W))
		{
			mDJmpcnt++;

			if (mDJmpcnt == 1)
			{
				Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -2200.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);
				mState = eChar01State::DoubleJump;
			}
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar01State::Slide;
		}
		
	}

	void Character01::djump()
	{

		if (mDJmpcnt == 1)
		{
			mAnimator->Play(L"DJump", true);
		}

		if (Input::GetKeyDown(eKeyCode::W))
		{
			mDJmpcnt++;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar01State::Slide;
		}
	}

	void Character01::slide()
	{

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(150.0f, 75.0f));
		collider->SetCenter(Vector2(-50.0f, -25.0f));
		
		mAnimator->Play(L"Slide", true);

		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = eChar01State::Run;
		}
		//if (Input::GetKey(eKeyCode::W))
		//{
		//	mState = eChar01State::Run;
		//}

	}

	void Character01::death()
	{
		mAnimator->Play(L"Death", false);
	}

	void Character01::idle()
	{

	}

	void Character01::transparent()
	{
		mAnimator->Play(L"Transp1", true);
	}

	void Character01::bigrun()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(tr->GetPos().x, 130.0f));
		tr->SetScale(Vector2(3.0f, 3.0f));

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(50.0f, 150.0f));
		collider->SetCenter(Vector2(230.0f, 410.0f));

		mAnimator->Play(L"Run", true);

		if (Input::GetKeyDown(eKeyCode::W))
		{
			Vector2 velocity = mRigidbody->GetVelocity();
			velocity.y = -2000.0f;

			mRigidbody->SetVelocity(velocity);
			mRigidbody->SetGround(false);
			mState = eChar01State::BigJump;

		}

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar01State::BigSlide;
		}
	}

	void Character01::bigjump()
	{
		mAnimator->Play(L"BeforeRun", false);

		if (mRigidbody->GetGround())
		{
			mRigidbody->mVelocity = Vector2(0.0f, 0.0f);

			mState = eChar01State::BigRun;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar01State::BigSlide;
		}
	}
	void Character01::bigslide()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(tr->GetPos().x, 130.0f));

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(50.0f, 150.0f));
		collider->SetCenter(Vector2(230.0f, 410.0f));

		mAnimator->Play(L"Slide", true);

		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = eChar01State::BigRun;
		}
	}

	void Character01::JumpCompleteEvent(/*const Cuphead* this*/)
	{
		mState = eChar01State::BeforeRun;
	}

	void Character01::DJumpCompleteEvent()
	{
		mState = eChar01State::BeforeRun;
	}

	void Character01::SlideStarteEvent()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(tr->GetPos().x, 650.0f));
	}

	void Character01::Transp1CompleteEvent()
	{
		mState = eChar01State::Damaged;
	}

	void Character01::DamagedCompleteEvent()
	{
		mState = eChar01State::Transp2;
	}

	void Character01::Transp2CompleteEvent()
	{
		mState = eChar01State::Run;
	}
}