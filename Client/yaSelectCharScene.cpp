#include "yaSelectCharScene.h"
#include "yaSelectCharBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaCamera.h"
namespace ya
{
	int SelectCharScene::mCharNumber = 1;

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
		//if (1�� ��Ű UI ��ư ������)
		//{
		//	mCharNumber = 1;
		//}

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::SelectStage);
			//SelectCharBackGround::flag = true;
		}

		Scene::Update();
	}

	void SelectCharScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
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