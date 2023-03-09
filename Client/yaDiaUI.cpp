#include "yaDiaUI.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    DiaUI::DiaUI()
    {

    }

    DiaUI::~DiaUI()
    {

    }

    void DiaUI::Initialize()
    {
        mImage = Resources::Load<Image>(L"DiaUI", L"..\\Resources\\Main\\main_ui_dia.bmp");

        GameObject::Initialize();
    }

    void DiaUI::Update()
    {
        GameObject::Update();
    }

    void DiaUI::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.2, mImage->GetHeight() * 1.2
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void DiaUI::Release()
    {
        GameObject::Release();
    }
}