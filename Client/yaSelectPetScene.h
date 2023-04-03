#pragma once
#include "yaScene.h"

namespace ya
{
	class SelectPetScene : public Scene
	{
	public:
		SelectPetScene();
		~SelectPetScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		static int GetPetNumber() { return mPetNumber; }

	private:
		static int mPetNumber;
	};
}