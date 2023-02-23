#pragma once
#include "yaScene.h"

namespace ya
{
	class Character00;
	class PlayBackGround;
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
		Character00* mCharacter00;
		PlayBackGround* mPlayBackGround;
	};
}

