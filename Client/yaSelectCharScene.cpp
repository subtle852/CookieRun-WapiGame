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
		object::Instantiate<SelectCharBackGround>(eLayerType::BG);
	}
	void SelectCharScene::OnExit()
	{
	}
}