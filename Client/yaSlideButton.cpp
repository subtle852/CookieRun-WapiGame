#include "yaSlideButton.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    SlideButton::SlideButton()
    {

    }

    SlideButton::~SlideButton()
    {

    }

    void SlideButton::Initialize()
    {
        mImage = Resources::Load<Image>(L"SlideNoUI", L"..\\Resources\\Play\\btn_slide_no.bmp");

        GameObject::Initialize();
    }

    void SlideButton::Update()
    {
        if (Input::GetKeyDown(eKeyCode::S))
        {
            mImage = Resources::Load<Image>(L"SlideYesUI", L"..\\Resources\\Play\\btn_slide_dim.bmp");
        }
        if (Input::GetKeyUp(eKeyCode::S))
        {
            mImage = Resources::Load<Image>(L"SlideNoUI", L"..\\Resources\\Play\\btn_slide_no.bmp");
        }

        GameObject::Update();
    }

    void SlideButton::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void SlideButton::Release()
    {
        GameObject::Release();
    }
}