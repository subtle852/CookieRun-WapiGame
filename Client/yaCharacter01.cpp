#include "yaCharacter01.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaCollider.h"
#include "yaRigidbody.h"

namespace ya
{
	Character01::Character01()
	{

	}
	Character01::~Character01()
	{

	}
	void Character01::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(200.0f, 600.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		Image* mImage = Resources::Load<Image>(L"Char01", L"..\\Resources\\idle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"idle", mImage, Vector2((290.0f * 1), (290.0f * 2)), 11, 6, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Roll", mImage, Vector2::Zero, 11, 6, 6, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Run", mImage, Vector2(0.0f, (290.0f * 1)), 11, 6, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"Jump", mImage, Vector2((290.0f * 1), (290.0f * 0)), 11, 6, 7, Vector2::Zero, 0.1);// 0에 가까울수록 애니메이션 빨리 동작
		mAnimator->CreateAnimation(L"DJump", mImage, Vector2((290.0f * 1), (290.0f * 0)), 11, 6, 7, Vector2::Zero, 0.08);
		mAnimator->CreateAnimation(L"Slide", mImage, Vector2((290.0f * 9), (290.0f * 0)), 11, 6, 2, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"Death", mImage, Vector2((290.0f * 0), (290.0f * 4)), 11, 6, 4, Vector2::Zero, 0.15);
		//mAnimator->CreateAnimations(L"..\\Resorces\\Chalise\\Idle", Vector2::Zero, 0.1f);


		mAnimator->GetCompleteEvent(L"Jump") = std::bind(&Character01::JumpCompleteEvent, this);
		//mAnimator->GetCompleteEvent(L"Slide") = std::bind(&Character01::SlideCompleteEvent, this);
		mAnimator->GetCompleteEvent(L"DJump") = std::bind(&Character01::DJumpCompleteEvent, this);

		Scene* scn = SceneManager::GetActiveScene();

		if (scn->GetName() == L"Main")
		{
			mAnimator->Play(L"idle", true);
		}
		
		if (scn->GetName() == L"Play")
		{
			Collider* collider = AddComponent<Collider>();
			collider->SetSize(Vector2(100.0f, 100.0f));
			collider->SetCenter(Vector2(-50.0f, -100.0f));

			mRigidbody = AddComponent<Rigidbody>();
			mRigidbody->SetMass(1.0f);

			mState = eChar00State::Run;
		}

		GameObject::Initialize();
	}
	void Character01::Update()
	{
		GameObject::Update();

		Scene* scn = SceneManager::GetActiveScene();
		if (scn->GetName() == L"Play")
		{
			switch (mState)
			{
			case ya::Character01::eChar00State::Run:
				run();
				break;
			case ya::Character01::eChar00State::Jump:
				jump();
				break;
			case ya::Character01::eChar00State::DoubleJump:
				djump();
				break;
			case ya::Character01::eChar00State::Slide:
				slide();
				break;
			case ya::Character01::eChar00State::Death:
				death();
				break;
			case ya::Character01::eChar00State::Idle:
				idle();
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

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Down)
		//{
		//	pos.x += 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
		//{
		//	pos.y -= 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::S) == eKeyState::Down)
		//{
		//	pos.y += 100.0f * Time::DeltaTime();
		//}

		//if (Input::GetKeyState(eKeyCode::D) == eKeyState::Up)
		//{
		//	mPos.x = 0.0f;
		//	mPos.y = 0.0f;
		//}
		// tr->SetPos(pos);
		// 이렇게 여러 상황들을 제어할 수 있음
		// ex. 아이템 클릭 후, 이동시 특정 위치가 아닐때는 다시 그 위치로 이동시키는 경우를 만들 수 있음


		//mTime 멤버 변수 만들어주고 생성자에서 : mTime(0.0f) 해줬다는 가정하에
		//mTime += Time::DeltaTime();

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
		// 충돌한 other의 체력이라던가 애니메이션이라던가 실행 가능
		//mAnimator->Play(L"Death", false);
	}

	void Character01::OnCollisionStay(Collider* other)
	{

	}

	void Character01::OnCollisionExit(Collider* other)
	{

	}

	void Character01::run()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(200.0f, 600.0f));

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(100.0f, 100.0f));
		collider->SetCenter(Vector2(-50.0f, -100.0f));
		mAnimator->Play(L"Run", true);

		if (Input::GetKeyDown(eKeyCode::W))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			pos.y -= 150.0f;
			tr->SetPos(pos);
			//mRigidbody->AddForce(Vector2(0.0f, -150.0f));
			mState = eChar00State::Jump;	
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar00State::Slide;
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
	void Character01::jump()
	{
		//Collider* collider = GetComponent<Collider>();
		//collider->SetSize(Vector2(100.0f, 100.0f));
		//collider->SetCenter(Vector2(-50.0f, -100.0f));

		mAnimator->Play(L"Jump", true);

		if (!mAnimator->IsComplte())
		{
			if (Input::GetKeyDown(eKeyCode::W))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				pos.y -= 150.0f;
				tr->SetPos(pos);
				mState = eChar00State::DoubleJump;
			}
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar00State::Slide;
		}
		
	}

	void Character01::djump()
	{
		mAnimator->Play(L"DJump", true);

		if (Input::GetKey(eKeyCode::S))
		{
			mState = eChar00State::Slide;
		}
	}

	void Character01::slide()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(200.0f, 600.0f));

		Collider* collider = GetComponent<Collider>();
		collider->SetSize(Vector2(100.0f, 50.0f));
		collider->SetCenter(Vector2(-50.0f, -30.0f));
		
		mAnimator->Play(L"Slide", true);

		if (Input::GetKeyUp(eKeyCode::S))
		{
			mState = eChar00State::Run;
		}

	}

	void Character01::death()
	{

	}

	void Character01::idle()
	{
		
	}

	void Character01::JumpCompleteEvent(/*const Cuphead* this*/)
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();

		//pos.y += 300.0f; //* Time::DeltaTime();
		mState = eChar00State::Run;
		//mAnimator->Play(L"Run", true);

		//tr->SetPos(pos);
	}

	void Character01::DJumpCompleteEvent()
	{
		mState = eChar00State::Run;
	}

	//void Character01::SlideCompleteEvent()
	//{

	//}
}