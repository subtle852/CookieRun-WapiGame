#pragma once
#include "yaScene.h"

namespace ya
{
	class Card01_00;

	class BaccaratScene : public Scene
	{
	public:
		BaccaratScene();
		~BaccaratScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		int mBetMoney = 0;
		GameObject* mBetMoneyOb[6] = { nullptr, };

		int mSelect = -1;
		GameObject* mSelectOb = nullptr;

		float mTime = 0.0f;

		Card01_00* mC00_01 = nullptr;
		Card01_00* mC00_02 = nullptr;
		Card01_00* mC00_03 = nullptr;
		Card01_00* mC00_04 = nullptr;

		Card01_00* mC00_05 = nullptr;
		Card01_00* mC00_06 = nullptr;

		GameObject* mCards[6] = { nullptr, };

		int mPlayerSum = 0;
		GameObject* mPlayerSumOb = nullptr;
		int mBankerSum = 0;
		GameObject* mBankerSumOb = nullptr;

		int mPlayerArray[2] = { -1,-1 };
		int mBankerArray[2] = { -1,-1 };

		int mResult = -1;
		GameObject* mResultOb = nullptr;
	};
}