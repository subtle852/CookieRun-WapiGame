#include "yaPauseButton.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    PauseButton::PauseButton()
    {

    }

    PauseButton::~PauseButton()
    {

    }

    void PauseButton::Initialize()
    {
        mImage = Resources::Load<Image>(L"PauseButton", L"..\\Resources\\Play\\btn_puase_no.bmp");

        GameObject::Initialize();
    }

    void PauseButton::Update()
    {
        GameObject::Update();
    }

    void PauseButton::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth()* 1.2, mImage->GetHeight()*1.2
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void PauseButton::Release()
    {
        GameObject::Release();
    }
}