#pragma once
#include "yaScene.h"

namespace ya
{
	class Slot01;
	class SlotB01; class SlotB02; class SlotB03; class SlotBs;

	class SlotScene : public Scene
	{
	public:
		SlotScene();
		~SlotScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Slot01* mSlot01;
		Slot01* mSlot02;
		Slot01* mSlot03;
		float mTime;

		int tempValueF;
		int tempValueS;

		SlotB01* mSlotB01 = nullptr;
		SlotB02* mSlotB02 = nullptr;
		SlotB03* mSlotB03 = nullptr;
		SlotBs* mSlotBs = nullptr;
	};
}