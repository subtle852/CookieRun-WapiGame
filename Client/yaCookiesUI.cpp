#include "yaCookiesUI.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    CookiesUI::CookiesUI()
    {

    }

    CookiesUI::~CookiesUI()
    {

    }

    void CookiesUI::Initialize()
    {
        mImage = Resources::Load<Image>(L"CookiesUI", L"..\\Resources\\Main\\main_ui_cookies.bmp");

        GameObject::Initialize();
    }

    void CookiesUI::Update()
    {
        GameObject::Update();
    }

    void CookiesUI::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void CookiesUI::Release()
    {
        GameObject::Release();
    }
}