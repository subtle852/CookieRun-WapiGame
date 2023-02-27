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
		mImage = Resources::Load<Image>(L"PlayBG", L"..\\Resources\\stage00.bmp");

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
		//BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
		TransparentBlt(hdc, pos.x, pos.y, 1600, 900
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}
	void PlayBackGround::Release()
	{
		GameObject::Release();
	}
}