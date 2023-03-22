#include "yaBlackOutM.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaAnimator.h"
#include "yaScene.h"

namespace ya
{
	BlackOutM::BlackOutM()
	{

	}

	BlackOutM::~BlackOutM()
	{

	}

	void BlackOutM::Initialize()
	{
		mImage01 = Resources::Load<Image>(L"BlackOutM", L"..\\Resources\\Item\\Effect\\BlackOutM.bmp");
		//mImage02 = Resources::Load<Image>(L"BlackOutM", L"..\\Resources\\Item\\Effect\\BlackOutM.bmp");
		//mImage03 = Resources::Load<Image>(L"BlackOutM", L"..\\Resources\\Item\\Effect\\BlackOutM.bmp");

		GameObject::Initialize();
	}

	void BlackOutM::Update()
	{
		GameObject::Update();
	}

	void BlackOutM::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		TransparentBlt(hdc, 750, 200, mImage01->GetWidth() * 1.2, mImage01->GetHeight() * 1.2
			, mImage01->GetHdc(), 0, 0, mImage01->GetWidth(), mImage01->GetHeight(), RGB(170, 0, 0));
		
		//TransparentBlt(hdc, 750, 200, mImage01->GetWidth() * 0.7, mImage01->GetHeight() * 0.7
		//	, mImage01->GetHdc(), 0, 0, mImage01->GetWidth(), mImage01->GetHeight(), RGB(170, 0, 0));
		//TransparentBlt(hdc, 900, 450, mImage02->GetWidth() * 0.7, mImage02->GetHeight() * 0.7
		//	, mImage02->GetHdc(), 0, 0, mImage02->GetWidth(), mImage02->GetHeight(), RGB(170, 0, 0));
		//TransparentBlt(hdc, 1050, 320, mImage03->GetWidth() * 0.7, mImage03->GetHeight() * 0.7
		//	, mImage03->GetHdc(), 0, 0, mImage03->GetWidth(), mImage03->GetHeight(), RGB(170, 0, 0));
	}

	void BlackOutM::Release()
	{
		GameObject::Release();
	}
}