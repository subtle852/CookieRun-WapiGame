#include "yaSelectCharBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    SelectCharBackGround::SelectCharBackGround()
    {

    }

    SelectCharBackGround::~SelectCharBackGround()
    {

    }

    void SelectCharBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"SelectCharBG", L"..\\Resources\\selectchar.bmp");

        GameObject::Initialize();
    }

    void SelectCharBackGround::Update()
    {
        GameObject::Update();
    }

    void SelectCharBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void SelectCharBackGround::Release()
    {
        GameObject::Release();
    }
}