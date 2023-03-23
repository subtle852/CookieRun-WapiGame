#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya
{
	class PlayBackGround;

	class Character01;
	class Pet01;

	class Obstacle;
	class Obstacle01;

	class BlackOutMItem; class BlackOutM;

	class ObstacleToCoin;

	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		PlayBackGround* mBG;

		Character01* mCh01;
		Pet01* mPet01;

		//Obstacle* mOb01;
		Obstacle01* mOb01;
		ObstacleToCoin* mOtC01;
	};
}