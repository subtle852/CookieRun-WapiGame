#pragma once
#include "yaGameObject.h"
#include "yaImage.h"

namespace ya
{
	class Animator;

	enum class eSlot01State
	{
		L1,
		R1,
		R2,
		R3,
		R4,
		R5,
		R6,
		R7,
		R8,
	};

	class Slot01 : public GameObject
	{
	public:
		Slot01();
		~Slot01();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();
	
	private:
		Animator* mAnimator;

	public:
		eSlot01State mState;
	};
}