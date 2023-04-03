#pragma once
#include "yaScene.h"

namespace ya
{
	class LotteryScene : public Scene
	{
	public:
		LotteryScene();
		~LotteryScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	};
}