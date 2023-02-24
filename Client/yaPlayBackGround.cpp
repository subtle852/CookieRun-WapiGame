#include "yaPlayBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	PlayBackGround::PlayBackGround()
	{

	}
	PlayBackGround::~PlayBackGround()
	{
	}
	void PlayBackGround::Initialize()
	{
		mImage = Resources::Load<Image>(L"BG", L"..\\Resources\\Play\\PlayBG.bmp");

		GameObject::Initialize();
	}
	void PlayBackGround::Update()
	{
		GameObject::Update();
	}
	void PlayBackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
	void PlayBackGround::Release()
	{
		GameObject::Release();
	}
}