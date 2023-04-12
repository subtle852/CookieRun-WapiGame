#include "yaSlot01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaCamera.h"

namespace ya
{
	Slot01::Slot01()
	{

	}
	Slot01::~Slot01()
	{

	}
	void Slot01::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector2(1.45f, 1.45f));

		Image* mImage = Resources::Load<Image>(L"sssss", L"..\\Resources\\Slot\\Lane\\sssss.bmp"); 
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"L1", mImage, Vector2((1311.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.01, 0);

		Image* mImage1 = Resources::Load<Image>(L"r1", L"..\\Resources\\Slot\\Lane\\r1.bmp");
		mAnimator->CreateAnimation(L"R1", mImage1, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);

		Image* mImage2 = Resources::Load<Image>(L"r2", L"..\\Resources\\Slot\\Lane\\r2.bmp");
		mAnimator->CreateAnimation(L"R2", mImage2, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);

		Image* mImage3 = Resources::Load<Image>(L"r3", L"..\\Resources\\Slot\\Lane\\r3.bmp");
		mAnimator->CreateAnimation(L"R3", mImage3, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);

		Image* mImage4 = Resources::Load<Image>(L"r4", L"..\\Resources\\Slot\\Lane\\r4.bmp");
		mAnimator->CreateAnimation(L"R4", mImage4, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);

		Image* mImage5 = Resources::Load<Image>(L"r5", L"..\\Resources\\Slot\\Lane\\r5.bmp");
		mAnimator->CreateAnimation(L"R5", mImage5, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);

		Image* mImage6 = Resources::Load<Image>(L"r6", L"..\\Resources\\Slot\\Lane\\r6.bmp");
		mAnimator->CreateAnimation(L"R6", mImage6, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);

		Image* mImage7 = Resources::Load<Image>(L"r7", L"..\\Resources\\Slot\\Lane\\r7.bmp");
		mAnimator->CreateAnimation(L"R7", mImage7, Vector2((1314.0f * 0), (67.0f * 0)), 32, 1, 32, Vector2::Zero, 0.03, 0);
		//mAnimator->CreateAnimations(L"..\\Resorces\\Chalise\\Idle", Vector2::Zero, 0.1f); 


		//mAnimator->GetCompleteEvent(L"Jump") = std::bind(&Character01::JumpCompleteEvent, this);
		mState = eSlot01State::L1;

		GameObject::Initialize();
	}
	void Slot01::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case ya::eSlot01State::L1:

			mAnimator->Play(L"L1", true);
			break;
		case ya::eSlot01State::R1:
			mAnimator->Play(L"R1", false);
			break;
		case ya::eSlot01State::R2:
			mAnimator->Play(L"R2", false);
			break;
		case ya::eSlot01State::R3:
			mAnimator->Play(L"R3", false);
			break;
		case ya::eSlot01State::R4:
			mAnimator->Play(L"R4", false);
			break;
		case ya::eSlot01State::R5:
			mAnimator->Play(L"R5", false);
			break;
		case ya::eSlot01State::R6:
			mAnimator->Play(L"R6", false);
			break;
		case ya::eSlot01State::R7:
			mAnimator->Play(L"R7", false);
			break;
		}

	}

	void Slot01::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Slot01::Release()
	{
		GameObject::Release();
	}

	//void Slot::JumpCompleteEvent(/*const Cuphead* this*/)
	//{
	//	mState = eChar01State::BeforeRun;
	//}

}