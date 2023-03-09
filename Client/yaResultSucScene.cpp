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

	}
	void ResultSucScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::ResultF);
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
		object::Instantiate<ResultSucBackGround>(eLayerType::BG);
	}
	void ResultSucScene::OnExit()
	{
	}
}