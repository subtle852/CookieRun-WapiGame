#pragma once
#include "yaScene.h"

namespace ya
{
	class StoreScene : public Scene
	{
	public:
		StoreScene();
		~StoreScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	public:
		GameObject* mOb = nullptr;
		GameObject* mObs[6] = { nullptr, };
		GameObject* mObs2[6] = { nullptr, };
	};
}