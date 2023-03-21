#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaImage.h"
#include "yaSceneManager.h"
#include "yaCharacter01.h"

extern ya::Application application;
namespace ya
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	Camera::eCameraEffectType Camera::mType = Camera::eCameraEffectType::None;
	class Image* Camera::mCutton = nullptr;
	float Camera::mCuttonAlpha = 1.0f;
	float Camera::mAlphaTime = 0.0f;
	float Camera::mEndTime = 3.0f;

	float Camera::mSwingATime = 0.0f;
	float Camera::mSwingBTime = 0.0f;
	float Camera::mSwingFTime = 0.0f;
	float Camera::mSwingETime = 0.1f;

	void Camera::Initiailize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);

		mType = eCameraEffectType::FadeIn;// 설정
		mCutton = Image::Create(L"Cutton", mResolution.x, mResolution.y, RGB(0, 0, 0)/*원하는 색*/);
	}

	void Camera::Update()
	{

		if (Input::GetKey(eKeyCode::LEFT))
			mLookPosition.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::RIGHT))
			mLookPosition.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::UP))
			mLookPosition.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::DOWN))
			mLookPosition.y += 100.0f * Time::DeltaTime();

		if (mTarget != nullptr)
		{
			Scene* scn = SceneManager::GetActiveScene();
			if (scn->GetName() == L"Play")
			{
				mLookPosition.x = mTarget->GetComponent<Transform>()->GetPos().x + 500.0f;
				mLookPosition.y = 450.0f;
			}
		}
		else
		{
			//Camera::Clear();
		}

		if (mAlphaTime < mEndTime)
		{
			//255 - > 1
			mAlphaTime += Time::DeltaTime();
			float ratio = (mAlphaTime / mEndTime);

			if (mType == eCameraEffectType::FadeIn)
			{
				mCuttonAlpha = 1.0f - ratio;
			}
			else if (mType == eCameraEffectType::FadeOut)
			{
				mCuttonAlpha = ratio;
			}
		}

		if ((mType == eCameraEffectType::None))
		{
			mSwingFTime = 0.0f;
		}

		if ((mType == eCameraEffectType::ShakeH))
		{
			mSwingFTime += Time::DeltaTime();

			if (mSwingFTime < 1.0f)
			{
				mSwingATime += Time::DeltaTime();
				mSwingBTime += Time::DeltaTime();

				if (mSwingATime > mSwingETime)
				{
					mLookPosition.y += 50.0f;
				}

				if (mSwingBTime > mSwingETime * 2)
				{
					mLookPosition.y -= 50.0f;
					mSwingATime = 0.0f;
					mSwingBTime = 0.0f;
				}
			}
			if (mSwingFTime > 1.0f)
			{
				mType = eCameraEffectType::None;
			}
		}

		if ((mType == eCameraEffectType::ShakeW))
		{
			mSwingFTime += Time::DeltaTime();

			if (mSwingFTime < 1.0f)
			{
				mSwingATime += Time::DeltaTime();
				mSwingBTime += Time::DeltaTime();

				if (mSwingATime > mSwingETime)
				{
					mLookPosition.x += 50.0f;
				}

				if (mSwingBTime > mSwingETime * 2)
				{
					mLookPosition.x -= 50.0f;
					mSwingATime = 0.0f;
					mSwingBTime = 0.0f;
				}
			}
			if (mSwingFTime > 1.0f)
			{
				mType = eCameraEffectType::None;
			}
		}


		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::Render(HDC hdc)
	{
		if (mAlphaTime < mEndTime
			&& mType == eCameraEffectType::FadeIn)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = 0;
			func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

			AlphaBlend(hdc
				, 0, 0
				, mResolution.x, mResolution.y
				, mCutton->GetHdc()
				, 0, 0
				, mCutton->GetHeight(), mCutton->GetWidth()
				, func);
		}
	}

	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mDistance = Vector2::Zero;
	}
}