#include "yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"

namespace ya
{
	std::vector<Scene*> SceneManager::mScenes = {}; // static ���� �ʱ�ȭ
	Scene* SceneManager::mActiveScene = nullptr;

	void ya::SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		
		//mScenes[(UINT)eSceneType::Play]->SetName(L"PLAYER"); //Entity Ȱ���

		mActiveScene = mScenes[(UINT)eSceneType::Play];

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Initialize();
		}
	}

	void ya::SceneManager::Update()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Update();
		}
		mActiveScene->Update();
	}

	void ya::SceneManager::Render(HDC hdc)
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;
			scene->Render(hdc);
		}
		mActiveScene->Render(hdc);
	}

	void ya::SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr) continue;// nullptr�� ��쵵 ������ ����ó��

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::LoadScene(eSceneType type)
	{
		// ���� �� �����鼭
		mActiveScene->OnExit();

		// ���ο� �� �����鼭
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}
