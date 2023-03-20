#include "yaResultSucScene.h"
#include "yaResultSucBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"

namespace ya
{
	ResultSucScene::ResultSucScene()
	{
	}

	ResultSucScene::~ResultSucScene()
	{
	}

	void ResultSucScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<ResultSucBackGround>(eLayerType::BG);
	}

	void ResultSucScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
	}

	void ResultSucScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void ResultSucScene::Release()
	{
		Scene::Release();
	}

	void ResultSucScene::OnEnter()
	{

	}

	void ResultSucScene::OnExit()
	{

	}
}