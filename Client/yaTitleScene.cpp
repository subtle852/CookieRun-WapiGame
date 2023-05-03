#include "yaTitleScene.h"
#include "yaTitleBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaObject.h"

#include "yaCamera.h"

#include "yaSound.h"
#include "yaResources.h"

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
		Scene::Initialize();

		anima = object::Instantiate<TitleBackGround>(eLayerType::BG);
		mBGM = Resources::Load<Sound>(L"TitleTheme", L"..\\Resources\\Sound\\Title\\title_dj_version.wav");
		mBGM->Play(false);
	}

	void TitleScene::Update()
	{
		if (GetFocus())
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				mBGM->Stop(true);
				SceneManager::LoadScene(eSceneType::Main);
			}
		}
		Scene::Update();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
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