#include "yaTitleScene.h"
#include "yaTitleBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"


namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{

		TitleBackGround* title_bg = new TitleBackGround();
		AddGameObject(title_bg, eLayerType::BG);

		Scene::Initialize();

	}
	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Main);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleScene::Release()
	{
		Scene::Release();
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}