#include "yaSceneManager.h"
#include "yaCollisionManager.h"
#include "yaCamera.h"

#include "yaTitleScene.h"
#include "yaMainScene.h"

#include "yaLotteryScene.h"
#include "yaStoreScene.h"
#include "yaSlotScene.h"
#include "yaRacingScene.h"
#include "yaBaccaratScene.h"

#include "yaSelectCharScene.h"
#include "yaSelectPetScene.h"
#include "yaSelectStageScene.h"
#include "yaPlayScene.h"
#include "yaResultSucScene.h"
#include "yaResultFailScene.h"
#include "yaToolScene.h"
#include "yaMakeScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static 변수 초기화
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Main] = new MainScene();

		mScenes[(UINT)eSceneType::Lottery] = new LotteryScene();
		mScenes[(UINT)eSceneType::Store] = new StoreScene();
		mScenes[(UINT)eSceneType::Slot] = new SlotScene();
		mScenes[(UINT)eSceneType::Racing] = new RacingScene();
		mScenes[(UINT)eSceneType::Baccarat] = new BaccaratScene();

		mScenes[(UINT)eSceneType::SelectChar] = new SelectCharScene();
		mScenes[(UINT)eSceneType::SelectPet] = new SelectPetScene();
		mScenes[(UINT)eSceneType::SelectStage] = new SelectStageScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::ResultS] = new ResultSucScene();
		mScenes[(UINT)eSceneType::ResultF] = new ResultFailScene();
		mScenes[(UINT)eSceneType::Tool] = new ToolScene();
		mScenes[(UINT)eSceneType::Make] = new MakeScene();


		//mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER"); //Entity 활용법

		mScenes[(UINT)eSceneType::Title]->SetName(L"Title");
		mScenes[(UINT)eSceneType::Main]->SetName(L"Main");

		mScenes[(UINT)eSceneType::Lottery]->SetName(L"Lottery");
		mScenes[(UINT)eSceneType::Store]->SetName(L"Store");
		mScenes[(UINT)eSceneType::Slot]->SetName(L"Slot");
		mScenes[(UINT)eSceneType::Racing]->SetName(L"Racing");
		mScenes[(UINT)eSceneType::Baccarat]->SetName(L"Baccarat");

		mScenes[(UINT)eSceneType::SelectChar]->SetName(L"SelectChar");
		mScenes[(UINT)eSceneType::SelectPet]->SetName(L"SelectPet");
		mScenes[(UINT)eSceneType::SelectStage]->SetName(L"SelectStage");
		mScenes[(UINT)eSceneType::Play]->SetName(L"Play");
		mScenes[(UINT)eSceneType::ResultS]->SetName(L"ResultS");
		mScenes[(UINT)eSceneType::ResultF]->SetName(L"ResultF");
		mScenes[(UINT)eSceneType::Make]->SetName(L"Make");

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Initialize();
		}

		mActiveScene = mScenes[(UINT)eSceneType::Title];
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;// nullptr인 경우도 있으니 예외처리

			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::LoadScene(eSceneType type)
	{
		Camera::Clear();

		// 현재 씬 나가면서
		mActiveScene->OnExit();

		CollisionManager::Clear();

		// 새로운 씬 들어오면서
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}