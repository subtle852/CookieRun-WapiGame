#include "yaSelectStageScene.h"
#include "yaSelectStageBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"


namespace ya
{
	SelectStageScene::SelectStageScene()
	{
	}
	SelectStageScene::~SelectStageScene()
	{
	}
	void SelectStageScene::Initialize()
	{

		SelectStageBackGround* title_bg = new SelectStageBackGround();
		AddGameObject(title_bg, eLayerType::BG);

		Scene::Initialize();

	}
	void SelectStageScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
	}
	void SelectStageScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void SelectStageScene::Release()
	{
		Scene::Release();
	}
	void SelectStageScene::OnEnter()
	{
	}
	void SelectStageScene::OnExit()
	{
	}
}