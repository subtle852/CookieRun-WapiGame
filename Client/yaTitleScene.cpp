#include "yaTitleScene.h"

#include "yaInput.h"
#include "yaSceneManager.h"

#include "yaTitleBackGround.h"

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
		mTitleBackGround = new TitleBackGround();
		// cuphead->SetPos(Vector2{0.0f, 0.0f + i});
		mTitleBackGround->SetName(L"Player");
		AddGameObject(mTitleBackGround, eLayerType::BG);

		//Scene::Initialize();
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
	}

	void TitleScene::Render(HDC hdc)
	{
	}

	void TitleScene::Release()
	{
	}

	void TitleScene::OnEnter()
	{
	}

	void TitleScene::OnExit()
	{
	}
}