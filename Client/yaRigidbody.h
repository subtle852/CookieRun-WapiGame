#pragma once
#include "yaComponent.h"

namespace ya
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force);
		void SetGround(bool ground) { mbGround = ground; }

	private:
		float mMass;// 질량
		Vector2 mForce;// 힘, 밀어주는 것
		Vector2 mAccelation;// 가속도
		Vector2 mVelocity;// 속도(방향 + 크기)

		Vector2 mLimitedVelocity;

		Vector2 mGravity;
		float mFriction;
		bool mbGround;

		/*float mStaticFriction;
		float mKineticFriction;*/
		//float mCoefficientFriction;
		//float mNormalForce;
	};
}