#include "yaCharacter08.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaRigidbody.h"
#include "yaCamera.h"
#include "yaObject.h"

#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaGround.h"
#include "yaUnderGround.h"
#include "yaOverGround.h"

#include "yaFlag.h"

#include "yaL1_JP01.h"
#include "yaL1_JP02.h"
#include "yaL1_JP03.h"
#include "yaL1_JP04.h"
#include "yaL1_JP05.h"
#include "yaL1_JP06.h"

#include "yaL1_DP01.h"
#include "yaL1_DP02.h"
#include "yaL1_DP03.h"
#include "yaL1_DP04.h"
#include "yaL1_DP05.h"
#include "yaL1_DP06.h"

#include "yaL1_SL01.h"
#include "yaL1_SL02.h"
#include "yaL1_SL03.h"
#include "yaL1_SL04.h"
#include "yaL1_SL05.h"
#include "yaL1_SL06.h"

// BonusTime
#include "yaBonus_01_B.h"
#include "yaBonus_02_O.h"
#include "yaBonus_03_N.h"
#include "yaBonus_04_U.h"
#include "yaBonus_05_S.h"
#include "yaBonus_06_T.h"
#include "yaBonus_07_I.h"
#include "yaBonus_08_M.h"
#include "yaBonus_09_E.h"

#include "yaPlayScene.h"

namespace ya
{
	float Character08::mCurHp = 100;
	float Character08::mMaxHp = 100;
	float Character08::mHpPercent = (Character08::mCurHp / Character08::mMaxHp) * 100;

	bool Character08::mBig = false;
	bool Character08::mSml = false;

	Character08::Character08()
	{

	}
	Character08::~Character08()
	{

	}
	void Character08::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector2(1.2f, 1.2f));

		Image* mImage = Resources::Load<Image>(L"Char08", L"..\\Resources\\Char\\S\\hero.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"idle", mImage, Vector2((366.13f * 2), (366.13f * 2)), 15, 8, 4, Vector2::Zero, 0.13, 0);
		mAnimator->CreateAnimation(L"Roll", mImage, Vector2::Zero, 15, 8, 6, Vector2::Zero, 0.15, 0);
		mAnimator->CreateAnimation(L"BeforeRun", mImage, Vector2((366.13f * 6), (366.13f * 0)), 15, 8, 1, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Run", mImage, Vector2(0.0f, (366.13f * 1)), 15, 8, 4, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"FastRun", mImage, Vector2((366.13f * 4), (366.13f * 1)), 15, 8, 4, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"SlowRun", mImage, Vector2(0.0f, (366.13f * 1)), 15, 8, 4, Vector2::Zero, 0.5, 0);
		mAnimator->CreateAnimation(L"Jump", mImage, Vector2((366.13f * 0), (366.13f * 0)), 15, 8, 1, Vector2::Zero, 0.1, 0);// 0�� �������� �ִϸ��̼� ���� ����
		mAnimator->CreateAnimation(L"DJump", mImage, Vector2((366.13f * 1), (366.13f * 0)), 15, 8, 6, Vector2::Zero, 0.08, 0);
		mAnimator->CreateAnimation(L"Slide", mImage, Vector2((366.13f * 9), (366.13f * 0)), 15, 8, 2, Vector2::Zero, 0.08, 0);
		mAnimator->CreateAnimation(L"Death", mImage, Vector2((366.13f * 0), (366.13f * 4)), 15, 8, 5, Vector2::Zero, 0.15, 0);
		mAnimator->CreateAnimation(L"Transp1", mImage, Vector2((366.13f * 9), (366.13f * 1)), 15, 8, 2, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Transp2", mImage, Vector2((366.13f * 9), (366.13f * 1)), 15, 8, 2, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Damaged", mImage, Vector2(0.0f, (366.13f * 4)), 15, 8, 1, Vector2::Zero, 0.2, 0);
		mAnimator->CreateAnimation(L"BeforeTransf", mImage, Vector2((366.13f * 0), (366.13f * 5)), 15, 8, 10, Vector2::Zero, 0.05, 0);
		mAnimator->CreateAnimation(L"Transf", mImage, Vector2((366.13f * 10), (366.13f * 5)), 15, 8, 4, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"AfterTransf", mImage, Vector2((366.13f * 0), (366.13f * 6)), 15, 8, 4, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Up", mImage, Vector2((366.13f * 0), (366.13f * 3)), 15, 8, 1, Vector2::Zero, 0.1, 0);
		mAnimator->CreateAnimation(L"Down", mImage, Vector2((366.13f * 11), (366.13f * 3)), 15, 8, 1, Vector2::Zero, 0.1, 0);


		mAnimator->GetCompleteEvent(L"Jump") = std::bind(&Character08::JumpCompleteEvent, this);
		mAnimator->GetCompleteEvent(L"DJump") = std::bind(&Character08::DJumpCompleteEvent, this);
		mAnimator->GetStartEvent(L"Slide") = std::bind(&Character08::SlideStarteEvent, this);
		mAnimator->GetCompleteEvent(L"Transp1") = std::bind(&Character08::Transp1CompleteEvent, this);
		mAnimator->GetCompleteEvent(L"Transp2") = std::bind(&Character08::Transp2CompleteEvent, this);
		mAnimator->GetCompleteEvent(L"Damaged") = std::bind(&Character08::DamagedCompleteEvent, this);
		mAnimator->GetCompleteEvent(L"BeforeTransf") = std::bind(&Character08::BeforeTransfCompleteEvent, this);
		mAnimator->GetCompleteEvent(L"AfterTransf") = std::bind(&Character08::AfterTransfCompleteEvent, this);

		Scene* scn = SceneManager::GetActiveScene();

		if (scn->GetName() == L"Main")
		{
			mAnimator->Play(L"idle", true);
		}

		//if (scn->GetName() == L"Play")
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	tr->SetScale(Vector2(1.2f, 1.2f));

		//	Collider* collider = AddComponent<Collider>();
		//	collider->SetSize(Vector2(100.0f, 100.0f));
		//	collider->SetCenter(Vector2(-10.0f, -50.0f));

		//	mRigidbody = AddComponent<Rigidbody>();
		//	mRigidbody->SetMass(1.0f);

		//	mState = eChar01State::Run;
		//}

		//if (scn->GetName() == L"Make")
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	tr->SetScale(Vector2(1.2f, 1.2f));

		//	Collider* collider = AddComponent<Collider>();
		//	collider->SetSize(Vector2(100.0f, 100.0f));
		//	collider->SetCenter(Vector2(-10.0f, -50.0f));

		//	mRigidbody = AddComponent<Rigidbody>();
		//	mRigidbody->SetMass(1.0f);

		//	mState = eChar01State::Run;
		//}

		GameObject::Initialize();
	}
	void Character08::Update()
	{
		GameObject::Update();

		Scene* scn = SceneManager::GetActiveScene();

		if (scn->GetName() == L"Main")
		{
			mAnimator->Play(L"idle", true);
		}

		if (scn->GetName() == L"Racing")
		{
			mAnimator->Play(L"Run", true);
		}

		if (scn->GetName() == L"Bonus")
		{
			if (mBonusInit == false)
			{	
				Transform* tr = GetComponent<Transform>();
				tr->SetScale(Vector2(1.2f, 1.2f));

				Collider* collider = AddComponent<Collider>();
				collider->SetSize(Vector2(100.0f, 100.0f));
				collider->SetCenter(Vector2(-10.0f, -50.0f));

				mRigidbody = AddComponent<Rigidbody>();
				mRigidbody->SetMass(1.0f);

				mState = eChar08State::Down;
				
				mBonusInit = true;
			}

			switch (mState)
			{
			case ya::eChar08State::Up:
				up();
				break;
			case ya::eChar08State::Down:
				down();
				break;
			}
		}

		if (scn->GetName() == L"Play" || scn->GetName() == L"Make")
		{
			if (mState != eChar08State::BeforeTransf && mState != eChar08State::Transf && mState != eChar08State::AfterTransf)
			{
				mWaitTime += Time::DeltaTime();
			}

			if (mWaitTime > 10.0f)
			{
				mTransfState = true;
				mState = eChar08State::BeforeTransf;
			}

			if (mPlayInit == false)
			{
				if (scn->GetName() == L"Play")
				{
					Transform* tr = GetComponent<Transform>();
					tr->SetScale(Vector2(1.2f, 1.2f));

					Collider* collider = AddComponent<Collider>();
					collider->SetSize(Vector2(100.0f, 100.0f));
					collider->SetCenter(Vector2(-10.0f, -50.0f));

					mRigidbody = AddComponent<Rigidbody>();
					mRigidbody->SetMass(1.0f);

					mState = eChar08State::Run;
				}
				mPlayInit = true;
			}
			if (mMakeInit == false)
			{
				if (scn->GetName() == L"Make")
				{
					Transform* tr = GetComponent<Transform>();
					tr->SetScale(Vector2(1.2f, 1.2f));

					Collider* collider = AddComponent<Collider>();
					collider->SetSize(Vector2(100.0f, 100.0f));
					collider->SetCenter(Vector2(-10.0f, -50.0f));

					mRigidbody = AddComponent<Rigidbody>();
					mRigidbody->SetMass(1.0f);

					mState = eChar08State::Run;
				}
				mMakeInit = true;
			}

			if (mG == false)
			{
				mRigidbody->SetGround(false);
			}

			if (mState != eChar08State::Death)
			{
				if (scn->GetName() == L"Make")
				{
					if (Input::GetKey(eKeyCode::D))
					{
						Transform* tr = GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						pos.x += 600.0f * Time::DeltaTime();
						tr->SetPos(pos);
					}
					if (Input::GetKey(eKeyCode::A))
					{
						Transform* tr = GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						pos.x -= 600.0f * Time::DeltaTime();
						tr->SetPos(pos);
					}
				}

				if (scn->GetName() == L"Play")
				{
					if (mStopbyFlag == false)
					{
						if (mFast == false && mSlow == false)// �ӵ� ������ ���� �ʴ� ����� �ӵ�
						{
							Transform* tr = GetComponent<Transform>();
							Vector2 pos = tr->GetPos();
							pos.x += 600.0f * Time::DeltaTime();
							tr->SetPos(pos);
						}
					}

					if (mStopbyFlag == true)
					{
						mState = eChar08State::Idle;
					}
				}

				if (mFast == true && mStopbyFlag == false)// Fast ������ �Ծ��� ��
				{
					if (mFastFirst == false)
					{
						Transform* tr = GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						pos.y -= 80.0f;
						tr->SetPos(pos);
						mFastFirst = true;
					}
					mFastT += Time::DeltaTime();

					//mAnimator->Play(L"FastRun", true);
					Transform* tr = GetComponent<Transform>();
					Vector2 pos = tr->GetPos();
					pos.x += 800.0f * Time::DeltaTime();
					tr->SetPos(pos);

					if (mFastT > 2.0f)
					{
						mFastT = 0.0f;
						mFast = false;
						mFastFirst = false;
					}
				}

				if (mSlow == true && mStopbyFlag == false)// slow ������ �Ծ��� ��
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
				if (mInv == false)// ü�� �ð� ��� ����
				{
					Character08::mCurHp -= 3.0f * Time::DeltaTime();
				}
				else// ���� ������ �Ծ��� ��
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
				if (mBig == true)// Ŀ���� ��
				{
					mBcnt++;
					if (mBcnt == 1)
					{
						mRigidbody->SetGround(false);
					}
					mState = eChar08State::BigRun;
					mBigT += Time::DeltaTime();

					if (mBigT > 3.0f)
					{
						Transform* tr = GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						pos.y = 600.0f;
						tr->SetPos(pos);
						mRigidbody->SetGround(false);

						mState = eChar08State::Run;

						mBcnt = 0;
						mBigT = 0.0f;
						mBig = false;
					}
				}

				if (mSml == true)// �۾����� ��
				{
					mSmlT += Time::DeltaTime();
					mSmlcnt++;

					if (mSmlcnt == 1)
					{
						Transform* tr = GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						pos.y = 400.0f;
						tr->SetPos(pos);
						tr->SetScale(Vector2(0.7f, 0.7f));

						Collider* collider = GetComponent<Collider>();
						collider->SetSize(Vector2(50.0f, 50.0f));
						collider->SetCenter(Vector2(-20.0f, -140.0f));
					}

					if (mSmlT > 3.0f)
					{
						Transform* tr = GetComponent<Transform>();
						Vector2 pos = tr->GetPos();
						pos.y = 600.0f;
						tr->SetPos(pos);
						tr->SetScale(Vector2(1.2f, 1.2f));

						Collider* collider = GetComponent<Collider>();
						collider->SetSize(Vector2(30.0f, 30.0f));
						collider->SetCenter(Vector2(-10.0f, -50.0f));
						//mState = eChar01State::Run;

						mSmlcnt = 0;
						mSmlT = 0.0f;
						mSml = false;
					}
				}
			}

			{
				if (mKeyError == true)// Ű ���� 
				{
					mKeyErrorT += Time::DeltaTime();

					if (mKeyErrorT > 4.0f)
					{
						Camera::mType = Camera::eCameraEffectType::None;
						mKeyError = false;
					}
				}
				if (mKeyError == false)
				{
					mKeyErrorT = 0.0f;
				}
			}

			if (mTransfState == true)
			{
				mTransFTime += Time::DeltaTime();
				if (mTransFTime > 3.0f)
				{
					mState = eChar08State::AfterTransf;
				}
			}

			// ���� ü�� ���� ó��
			if (Character08::mCurHp <= 0.0f)
			{
				if (mZom == true)
				{
					mCurHp = 0.0f;
					mState = eChar08State::Death;
					mZomWait += Time::DeltaTime();

					if (mZomWait > 2.0f)
					{
						//Transform* tr = GetComponent<Transform>();
						//Vector2 pos = tr->GetPos();
						//pos.y = 600.0f;
						//tr->SetPos(pos);

						mCurHp += 30.f;
						mState = eChar08State::Run;
						mZom = false;
					}
				}
				else
				{
					mCurHp = 0.0f;
					mState = eChar08State::Death;
				}
			}
			if (Character08::mCurHp > 100.0f)
			{
				mCurHp = 100.0f;
			}

			// ���� ü�� �ۼ�Ʈ ���
			Character08::mHpPercent = (Character08::mCurHp / Character08::mMaxHp) * 100;

			// ���¿� ���� ���� �Լ� �����ϴ� ����ġ��
			switch (mState)
			{
			case ya::eChar08State::Run:
				run();
				break;
			case ya::eChar08State::BeforeRun:
				beforerun();
				break;
			case ya::eChar08State::Jump:
				jump();
				break;
			case ya::eChar08State::DoubleJump:
				djump();
				break;
			case ya::eChar08State::Slide:
				slide();
				break;
			case ya::eChar08State::Death:
				death();
				break;
			case ya::eChar08State::Idle:
				idle();
				break;
			case ya::eChar08State::Transp1:
				transparent();
				break;
			case ya::eChar08State::Transp2:
				mAnimator->Play(L"Transp2", true);
				break;
			case ya::eChar08State::Damaged:
				mAnimator->Play(L"Damaged", true);
				break;
			case ya::eChar08State::BigRun:
				bigrun();
				break;
			case ya::eChar08State::BeforeTransf:
				beforeTransf();
				break;
			case ya::eChar08State::Transf:
				transf();
				break;
			case ya::eChar08State::AfterTransf:
				afterTransf();
				break;
			case ya::eChar08State::Up:
				up();
				break;
			case ya::eChar08State::Down:
				down();
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
		// �̷��� ���� ���� ���� 2�ʵڸ� ���������(�� �κ��� 3�� 8�� 01:25 ���� ���� or Delete Object �� ����)
	}

	void Character08::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Character08::Release()
	{
		GameObject::Release();
	}

	void Character08::OnCollisionEnter(Collider* other)
	{
		//if (dynamic_cast<Obstacle*>(other->GetOwner()))
		//{
		//	mState = eChar01State::Transp1;
		//}

		{
			if (mFast == true) {}
			else if (mInv == true) {}
			else if (mBig == true) {}
			else// ���� ������, ����, Ŀ���� ���¿��� Obstacle�� �ε����� �ǰ� �پ���� �ʴ� ���� ���ܽ�Ų ��
			{
#pragma region 장애물 충돌 시 체력 마이너스
				if (dynamic_cast<L1_JP01*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_JP02*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_JP03*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_JP04*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_JP05*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_JP06*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_DP01*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_DP02*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_DP03*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_DP04*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_DP05*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_DP06*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_SL01*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_SL02*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_SL03*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_SL04*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_SL05*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
				if (dynamic_cast<L1_SL06*>(other->GetOwner()))
				{
					mCurHp -= 10;
				}
#pragma endregion
			}
		}

		if (dynamic_cast<Bonus_01_B*>(other->GetOwner()))
		{
			PlayScene::mBonusState[0] = 1;
		}
		if (dynamic_cast<Bonus_02_O*>(other->GetOwner()))
		{
			PlayScene::mBonusState[1] = 1;
		}
		if (dynamic_cast<Bonus_03_N*>(other->GetOwner()))
		{
			PlayScene::mBonusState[2] = 1;
		}
		if (dynamic_cast<Bonus_04_U*>(other->GetOwner()))
		{
			PlayScene::mBonusState[3] = 1;
		}
		if (dynamic_cast<Bonus_05_S*>(other->GetOwner()))
		{
			PlayScene::mBonusState[4] = 1;
		}
		if (dynamic_cast<Bonus_06_T*>(other->GetOwner()))
		{
			PlayScene::mBonusState[5] = 1;
		}
		if (dynamic_cast<Bonus_07_I*>(other->GetOwner()))
		{
			PlayScene::mBonusState[6] = 1;
		}
		if (dynamic_cast<Bonus_08_M*>(other->GetOwner()))
		{
			PlayScene::mBonusState[7] = 1;
		}
		if (dynamic_cast<Bonus_09_E*>(other->GetOwner()))
		{
			PlayScene::mBonusState[8] = 1;
		}

		if (dynamic_cast<Ground*>(other->GetOwner()))
		{
			mG = true;
			mRigidbody->SetGround(true);
		}
		if (dynamic_cast<UnderGround*>(other->GetOwner()))
		{
			mG = true;
			mRigidbody->SetGround(true);
		}

		if (dynamic_cast<Flag*>(other->GetOwner()))
		{
			mStopbyFlag = true;
		}
	}

	void Character08::OnCollisionStay(Collider* other)
	{
		if (mBig == true && dynamic_cast<Ground*>(other->GetOwner()))// Ŀ���� �� �ٷ� ī�޶� ��鸮��, Ŀ�� ���¿��� �����ϰ� ���� ������ ī�޶� ��鸮�� 
		{
			Camera::mType = Camera::eCameraEffectType::ShakeH;
		}

		if (dynamic_cast<Ground*>(other->GetOwner()))
		{
			mG = true;
		}
		if (dynamic_cast<UnderGround*>(other->GetOwner()))
		{
			mG = true;
		}
	}

	void Character08::OnCollisionExit(Collider* other)
	{

		if (dynamic_cast<Ground*>(other->GetOwner()))
		{
			mG = false;
		}
		if (dynamic_cast<UnderGround*>(other->GetOwner()))
		{
			mG = false;
		}
		if (dynamic_cast<OverGround*>(other->GetOwner()))
		{
			mG = false;
		}
	}

	void Character08::run()
	{
		if (mSml != true)
		{
			Transform* tr = GetComponent<Transform>();
			//tr->SetPos(Vector2(tr->GetPos().x, 130.0f));
			tr->SetScale(Vector2(1.2f, 1.2f));

			Collider* collider = GetComponent<Collider>();
			collider->SetSize(Vector2(100.0f, 100.0f));
			collider->SetCenter(Vector2(-10.0f, -50.0f));
		}

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

		if (mKeyError == false)
		{
			if (Input::GetKeyDown(eKeyCode::S))
			{
				mState = eChar08State::Slide;
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
					mState = eChar08State::Jump;
				}
			}
		}

		if (mKeyError == true)
		{
			if (Input::GetKeyDown(eKeyCode::W))
			{
				mState = eChar08State::Slide;
			}

			if (Input::GetKeyDown(eKeyCode::S))
			{
				mJmpcnt++;

				if (mJmpcnt == 1)
				{
					Vector2 velocity = mRigidbody->GetVelocity();
					velocity.y = -2200.0f;

					mRigidbody->SetVelocity(velocity);
					mRigidbody->SetGround(false);
					mState = eChar08State::Jump;
				}
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

		//	//// ȸ��
		//	//Transform* tr = GetComponent<Transform>();
		//	//float x = cosf(-PI / 4.0f);
		//	//float y = sinf(-PI / 4.0f);
		//	//
		//	//pos.x += 100.0f * x * Time::DeltaTime();
		//	//pos.y += 100.0f * y * Time::DeltaTime();
		//	//tr->SetPos(pos);
		//	//
		//	//// ���� ȸ��
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
		//	//// ���� ȸ���� �ʿ���� ���, �� ��ġ�� �׳� ���Ͱ� ������
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

	void Character08::beforerun()
	{
		mAnimator->Play(L"BeforeRun", false);

		if (mKeyError == false)
		{
			if (!mRigidbody->GetGround() && Input::GetKeyDown(eKeyCode::W))
			{
				mDJmpcnt++;

				if (mDJmpcnt == 1)
				{
					Vector2 velocity = mRigidbody->GetVelocity();
					velocity.y = -2200.0f;

					mRigidbody->SetVelocity(velocity);
					mRigidbody->SetGround(false);
					mState = eChar08State::DoubleJump;
				}
			}
		}

		if (mKeyError == true)
		{
			if (!mRigidbody->GetGround() && Input::GetKeyDown(eKeyCode::S))
			{
				mDJmpcnt++;

				if (mDJmpcnt == 1)
				{
					Vector2 velocity = mRigidbody->GetVelocity();
					velocity.y = -2200.0f;

					mRigidbody->SetVelocity(velocity);
					mRigidbody->SetGround(false);
					mState = eChar08State::DoubleJump;
				}
			}
		}

		if (mRigidbody->GetGround())
		{
			//mRigidbody->mVelocity = Vector2(0.0f, 0.0f);

			mState = eChar08State::Run;
		}

		if (mKeyError == false)
		{
			if (Input::GetKey(eKeyCode::S))
			{
				mState = eChar08State::Slide;
			}
		}
		if (mKeyError == true)
		{
			if (Input::GetKey(eKeyCode::W))
			{
				mState = eChar08State::Slide;
			}
		}
	}

	void Character08::jump()
	{
		mJmpcnt = 0;

		mAnimator->Play(L"Jump", true);

		if (mKeyError == false)
		{
			if (!mRigidbody->GetGround() && Input::GetKeyDown(eKeyCode::W))
			{
				mDJmpcnt++;

				if (mDJmpcnt == 1)
				{
					Vector2 velocity = mRigidbody->GetVelocity();
					velocity.y = -2200.0f;

					mRigidbody->SetVelocity(velocity);
					mRigidbody->SetGround(false);
					mState = eChar08State::DoubleJump;
				}
			}

			if (Input::GetKey(eKeyCode::S))
			{
				mState = eChar08State::Slide;
			}
		}

		if (mKeyError == true)
		{
			if (!mRigidbody->GetGround() && Input::GetKeyDown(eKeyCode::S))
			{
				mDJmpcnt++;

				if (mDJmpcnt == 1)
				{
					Vector2 velocity = mRigidbody->GetVelocity();
					velocity.y = -2200.0f;

					mRigidbody->SetVelocity(velocity);
					mRigidbody->SetGround(false);
					mState = eChar08State::DoubleJump;
				}
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mState = eChar08State::Slide;
			}
		}
	}

	void Character08::djump()
	{

		if (mDJmpcnt == 1)
		{
			mAnimator->Play(L"DJump", true);
		}

		if (mKeyError == false)
		{
			if (Input::GetKeyDown(eKeyCode::W))
			{
				mDJmpcnt++;
			}

			if (Input::GetKey(eKeyCode::S))
			{
				mState = eChar08State::Slide;
			}
		}

		if (mKeyError == true)
		{
			if (Input::GetKeyDown(eKeyCode::S))
			{
				mDJmpcnt++;
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mState = eChar08State::Slide;
			}
		}
	}

	void Character08::slide()
	{
		if (mSml == true)
		{
			mState = eChar08State::Run;
		}
		else if (mSml != true)
		{
			Collider* collider = GetComponent<Collider>();
			collider->SetSize(Vector2(150.0f, 75.0f));
			collider->SetCenter(Vector2(-50.0f, -25.0f));

			mScnt++;
			if (mScnt == 1)
			{
				mRigidbody->SetGround(false);
			}

			mAnimator->Play(L"Slide", true);


			if (mKeyError == false)
			{
				if (Input::GetKeyUp(eKeyCode::S))
				{
					mRigidbody->SetGround(false);
					mScnt = 0;
					mState = eChar08State::Run;
				}
			}

			if (mKeyError == true)
			{
				if (Input::GetKeyUp(eKeyCode::W))
				{
					mRigidbody->SetGround(false);
					mScnt = 0;
					mState = eChar08State::Run;
				}
			}
		}
	}

	void Character08::death()
	{
		mAnimator->Play(L"Death", false);
	}

	void Character08::idle()
	{
		mAnimator->Play(L"idle", true);
	}

	void Character08::transparent()
	{
		mAnimator->Play(L"Transp1", true);
	}

	void Character08::bigrun()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector2(3.0f, 3.0f));

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(100.0f, 800.0f));
		collider->SetCenter(Vector2(300.0f, -250.0f));

		mAnimator->Play(L"Run", true);

		if (mKeyError == false)
		{
			if (Input::GetKeyDown(eKeyCode::W) && this->mG)
			{
				Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -2000.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);
			}
		}
		if (mKeyError == true)
		{
			if (Input::GetKeyDown(eKeyCode::S) && this->mG)
			{
				Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -2000.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);
			}
		}
	}

	void Character08::beforeTransf()
	{
		mWaitTime = 0.0f;

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(100.0f, 200.0f));
		collider->SetCenter(Vector2(-10.0f, -150.0f));

		mInv = true;
		mAnimator->Play(L"BeforeTransf", true);
	}

	void Character08::transf()
	{
		mInv = true;
		mTransfState = true;
		mAnimator->Play(L"Transf", true);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x += 800.0f * Time::DeltaTime();
		tr->SetPos(pos);

		mRigidbody = GetComponent<Rigidbody>();
		mRigidbody->mFriction = 8000.0f;
		//mGravity = Vector2(0.0f, 9000.0f); //9000
		//mFriction = 500.0f;

		if (Input::GetKey(eKeyCode::W))
		{
			//mJmpcnt++;

			//if (mJmpcnt == 1)
			{
				Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -350.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);
				//mState = eChar07State::Jump;
			}
		}
	}

	void Character08::afterTransf()
	{
		mAnimator->Play(L"AfterTransf", true);
	}

	void Character08::up()
	{
		mInv = true;
		//mTransfState = true;
		mAnimator->Play(L"Up", true);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x += 600.0f * Time::DeltaTime();
		tr->SetPos(pos);

		Vector2 velocity = mRigidbody->GetVelocity();
		velocity.y = -600.0f;

		mRigidbody->SetVelocity(velocity);
		mRigidbody->SetGround(false);

		if (Input::GetKeyUp(eKeyCode::W))
		{
			mState = eChar08State::Down;
		}
	}

	void Character08::down()
	{
		mInv = true;
		//mTransfState = true;
		mAnimator->Play(L"Down", true);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos.x += 600.0f * Time::DeltaTime();
		tr->SetPos(pos);

		mRigidbody = GetComponent<Rigidbody>();
		mRigidbody->mFriction = 6500.0f;
		//mGravity = Vector2(0.0f, 9000.0f); //9000
		//mFriction = 500.0f;

		if (Input::GetKey(eKeyCode::W))
		{
			//mJmpcnt++;

			//if (mJmpcnt == 1)
			{
				/*Vector2 velocity = mRigidbody->GetVelocity();
				velocity.y = -450.0f;

				mRigidbody->SetVelocity(velocity);
				mRigidbody->SetGround(false);*/
				
				mState = eChar08State::Up;
			}
		}
	}

	void Character08::JumpCompleteEvent(/*const Cuphead* this*/)
	{
		mState = eChar08State::BeforeRun;
	}

	void Character08::DJumpCompleteEvent()
	{
		mState = eChar08State::BeforeRun;
	}

	void Character08::SlideStarteEvent()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(tr->GetPos().x, 650.0f));
	}

	void Character08::Transp1CompleteEvent()
	{
		mState = eChar08State::Damaged;
	}

	void Character08::DamagedCompleteEvent()
	{
		//mState = eChar01State::Transp2;
		mState = eChar08State::Run;
	}

	void Character08::Transp2CompleteEvent()
	{
		mState = eChar08State::Run;
	}

	void Character08::BeforeTransfCompleteEvent()
	{
		mState = eChar08State::Transf;
	}

	void Character08::AfterTransfCompleteEvent()
	{
		mRigidbody = GetComponent<Rigidbody>();
		mRigidbody->mFriction = 500.0f;

		mTransFTime = 0.0f;
		mInv = false;
		mTransfState = false;
		mState = eChar08State::Run;
	}
}