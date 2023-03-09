#include "yaMainBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
	MainBackGround::MainBackGround()
	{

	}
	MainBackGround::~MainBackGround()
	{

	}

	void MainBackGround::Initialize()
	{
		mImage = Resources::Load<Image>(L"MainBG", L"..\\Resources\\main.bmp");

		GameObject::Initialize();
	}

	void MainBackGround::Update()
	{
		GameObject::Update();
	}

	void MainBackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		//BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
		TransparentBlt(hdc, pos.x, pos.y, 1600, 900
			, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));
	}

	void MainBackGround::Release()
	{
		GameObject::Release();
	}
}