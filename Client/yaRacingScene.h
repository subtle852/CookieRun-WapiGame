#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya
{
	class Character01;
	class F_1;
	class F_2;
	class F_3;
	class F_4;
	class F_5;
	class RacingB01;

	class RacingScene : public Scene
	{
	public:
		RacingScene();
		~RacingScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Character01* mCh01;
		Character01* mCh02;
		Character01* mCh03;
		Character01* mCh04;
		Character01* mCh05;

		F_1* mCh01F;
		F_2* mCh02F;
		F_3* mCh03F;
		F_4* mCh04F;
		F_5* mCh05F;
			
		RacingB01* mB01 = nullptr;

		float mTime = 0.0f;

		int mNumber = -1;
		GameObject* mNumOb = nullptr;
		int mWinner = -1;
		GameObject* mWinOb = nullptr;

		float mBenefit1 = 0.f;
		float mBenefit2 = 0.f;
		float mBenefit3 = 0.f;
		float mBenefit4 = 0.f;
		float mBenefit5 = 0.f;

		GameObject* mOb = nullptr;
		GameObject* mObs[6] = { nullptr, };
		GameObject* mObs2[6] = { nullptr, };
	};
}