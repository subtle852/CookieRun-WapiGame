#include "yaPlayButton.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    PlayButton::PlayButton()
    {

    }

    PlayButton::~PlayButton()
    {

    }

    void PlayButton::Initialize()
    {
        mImage = Resources::Load<Image>(L"PlayUI", L"..\\Resources\\Main\\main_ui_play.bmp");

        GameObject::Initialize();
    }

    void PlayButton::Update()
    {
        GameObject::Update();
    }

    void PlayButton::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight()
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void PlayButton::Release()
    {
        GameObject::Release();
    }
}