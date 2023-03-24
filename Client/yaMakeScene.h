#pragma once
#include "yaScene.h"

namespace ya
{
	union TilePos
	{
		struct
		{
			UINT32 x;
			UINT32 y;
		};
		UINT64 id;
	};

	class Character01;
	class GameObject;

	class MakeScene : public Scene
	{
	public:
		MakeScene();
		~MakeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void Create();

	private:
		std::unordered_map<UINT64, int> mTiles;

		Character01* mCh;

		GameObject* mOb;

		TilePos id;

		float DownPosX;
		float DownPosY;
		float UpPosX;
		float UpPosY;
	};
}