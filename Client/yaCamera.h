#pragma once
#include "YamYamEngine.h"

namespace ya
{
	class GameObject;
	class Camera
	{
	public:
		enum class eCameraEffectType
		{
			None,
			FadeIn,
			FadeOut,
			ShakeH,
			ShakeW,
			Rotate,
			End,
		};

		static void Initiailize();
		static void Update();
		static void Render(HDC hdc);
		static void Clear();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

	public:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;

		static eCameraEffectType mType;
		static class Image* mCutton;
		static float mCuttonAlpha;
		static float mAlphaTime;
		static float mEndTime;

		static float mSwingFTime;
		static float mSwingATime; static float mSwingBTime;
		static float mSwingETime;
	};
}
