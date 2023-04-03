#pragma once
#include "yaScene.h"
#include "yaImage.h"
#include "yaEnums.h"

namespace ya
{
	class PlayBackGround;

	class Character01;
	class Pet01;

	class CloudEffect;

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

	private:
		std::unordered_map<UINT64, UINT64> mTiles;

		//Character01* mCh;

		GameObject* mOb;
		std::unordered_map<UINT64, GameObject*> mObs;// 게임오브젝트를 멤버 배열로 받아 destroy하려고 만든 것

		std::unordered_map<UINT64, GameObject*> mBasicJelly;
		std::unordered_map<UINT64, GameObject*> mBearJelly;

		std::unordered_map<UINT64, GameObject*> mObstacle;
		std::unordered_map<UINT64, GameObject*> mCoin;

		TilePos id;
		TileInd id2;

	public:
		static Vector2 mChPos;

		float mMagnetTime = 0.0f;

		float mBtoBTime = 0.0f;
		bool mBtoBend = false;
		bool mBtoBend2 = false;

		float mOtoCTime = 0.0f;
		bool mOtoCend = false;
		bool mOtoCend2 = false;

		CloudEffect* mCloudEffect = nullptr;
		static bool mCloudEffectOnatPlay;
		float mCloudEffectTime = 0.0f;
	};
}