#include "yaSelectStageBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    SelectStageBackGround::SelectStageBackGround()
    {
    }

    SelectStageBackGround::~SelectStageBackGround()
    {
    }

    void SelectStageBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"SelectStageBG", L"..\\Resources\\selectstage.bmp");

        GameObject::Initialize();
    }

    void SelectStageBackGround::Update()
    {
        GameObject::Update();
    }

    void SelectStageBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void SelectStageBackGround::Release()
    {
        GameObject::Release();
    }
}