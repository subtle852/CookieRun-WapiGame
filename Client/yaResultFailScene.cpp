#include "yaResultFailScene.h"
#include "yaResultFailBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"

namespace ya
{
	ResultFailScene::ResultFailScene()
	{
	}

	ResultFailScene::~ResultFailScene()
	{
	}

	void ResultFailScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<ResultFailBackGround>(eLayerType::BG);
	}

	void ResultFailScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}
	}

	void ResultFailScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void ResultFailScene::Release()
	{
		Scene::Release();
	}

	void ResultFailScene::OnEnter()
	{
		
	}

	void ResultFailScene::OnExit()
	{

	}
}