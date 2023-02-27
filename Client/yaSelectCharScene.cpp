#include "yaSelectCharScene.h"
#include "yaSelectCharBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"


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

		SelectCharBackGround* title_bg = new SelectCharBackGround();
		AddGameObject(title_bg, eLayerType::BG);

		Scene::Initialize();

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