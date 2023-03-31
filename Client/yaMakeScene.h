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
	class EatEffect;
	class CloudEffect;

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
		std::unordered_map<UINT64, GameObject*> mObs;// 게임오브젝트를 멤버 배열로 받아 destroy하려고 만든 것

		std::unordered_map<UINT64, GameObject*> mBasicJelly;
		std::unordered_map<UINT64, GameObject*> mBearJelly;

		std::unordered_map<UINT64, GameObject*> mObstacle;
		std::unordered_map<UINT64, GameObject*> mCoin;

		TilePos id;
		TileInd id2;

		float DownPosX;
		float DownPosY;
		float UpPosX;
		float UpPosY;

	public:
		static Vector2 mChPos;

		float mMagnetTime = 0.0f;

		float mBtoBTime = 0.0f;
		bool mBtoBend = false;
		bool mBtoBend2 = false;

		float mOtoCTime = 0.0f;
		bool mOtoCend = false;
		bool mOtoCend2 = false;

		EatEffect* mEatEffect = nullptr;
		static bool mEatEffectOn;
		float mEatEffectTime = 0.0f;

		CloudEffect* mCloudEffect = nullptr;
		static bool mCloudEffectOn;
		float mCloudEffectTime = 0.0f;
	};
}