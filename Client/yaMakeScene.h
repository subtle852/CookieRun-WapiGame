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

	union TileInd
	{
		struct
		{
			UINT32 ind;
			UINT32 width;
		};
		UINT64 id2;
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
		std::unordered_map<UINT64, UINT64> mTiles;

		Character01* mCh;

		GameObject* mOb;
		std::unordered_map<UINT64, GameObject*> mVectorOb;

		std::unordered_map<UINT64, GameObject*> mBasicJelly;

		TilePos id;
		TileInd id2;

		float DownPosX;
		float DownPosY;
		float UpPosX;
		float UpPosY;

	public:
		static Vector2 mChPos;

		float mMagnetTime = 0.0f;
	};
}