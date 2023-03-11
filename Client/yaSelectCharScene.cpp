#include "yaSelectCharScene.h"
#include "yaSelectCharBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"

namespace ya
{
	SelectCharScene::SelectCharScene()
	{

	}
	SelectCharScene::~SelectCharScene()
	{

	}

	void SelectCharScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<SelectCharBackGround>(eLayerType::BG);
	}

	void SelectCharScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::SelectStage);
		}
	}

	void SelectCharScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);
	}

	void SelectCharScene::Release()
	{
		Scene::Release();
	}

	void SelectCharScene::OnEnter()
	{

	}

	void SelectCharScene::OnExit()
	{
	}
}