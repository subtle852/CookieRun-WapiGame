#include "yaSelectStageScene.h"
#include "yaSelectStageBackGround.h"
#include "yaPortal.h"
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
		Scene::Initialize();

		object::Instantiate<SelectStageBackGround>(eLayerType::BG);
		object::Instantiate<Portal>(Vector2(170.0f, 400.0f), eLayerType::Obstacle);
		object::Instantiate<Portal>(Vector2(670.0f, 400.0f), eLayerType::Obstacle);
		object::Instantiate<Portal>(Vector2(1170.0f, 400.0f), eLayerType::Obstacle);
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