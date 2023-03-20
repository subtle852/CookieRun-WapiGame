#include "yaTitleScene.h"
#include "yaTitleBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaObject.h"

#include "yaCamera.h"

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

	}

	void TitleScene::Update()
	{
		//Camera::mType = Camera::eCameraEffectType::FadeIn;// 설정
		//Camera::mCutton = Image::Create(L"Cutton00", Camera::mResolution.x, Camera::mResolution.y, RGB(0, 0, 0)/*원하는 색*/);

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Main);
		}
		Scene::Update();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);
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