#include "yaGuageBar.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    GuageBar::GuageBar()
    {

    }

    GuageBar::~GuageBar()
    {

    }

    void GuageBar::Initialize()
    {
        mImage = Resources::Load<Image>(L"GuageBar", L"..\\Resources\\Play\\gauge_heart_orange.bmp");

        GameObject::Initialize();
    }

    void GuageBar::Update()
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //pos.x -= 50.0f * Time::DeltaTime();

        tr->SetPos(pos);

        GameObject::Update();
    }

    void GuageBar::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.3, mImage->GetHeight() * 1.3
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void GuageBar::Release()
    {
        GameObject::Release();
    }
}