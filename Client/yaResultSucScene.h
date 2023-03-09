#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya
{
	class ResultSucScene : public Scene
	{
	public:
		ResultSucScene();
		~ResultSucScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;


	private:
		Image* mScenImage;
	};
}