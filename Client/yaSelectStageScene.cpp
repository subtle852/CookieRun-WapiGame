#include "yaSelectStageScene.h"
#include "yaSelectStageBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaObject.h"

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
		object::Instantiate<SelectStageBackGround>(eLayerType::BG);
	}
	void SelectStageScene::OnExit()
	{
	}
}