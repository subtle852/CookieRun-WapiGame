#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya
{
	class Character00;
	class Pet00;

	class MainScene : public Scene
	{
	public:
		MainScene();
		~MainScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Character00* mCh00;
		Pet00* mPet00;
	};
}