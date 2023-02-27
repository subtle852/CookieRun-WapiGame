#include "yaTitleBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    TitleBackGround::TitleBackGround()
    {
    }

    TitleBackGround::~TitleBackGround()
    {
    }

    void TitleBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"TitleBG", L"..\\Resources\\title.bmp");

        GameObject::Initialize();
    }

    void TitleBackGround::Update()
    {
        GameObject::Update();
    }

    void TitleBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void TitleBackGround::Release()
    {
        GameObject::Release();
    }
}

// 아니 이게 Load함수에서 걸려지는걸까?
//namespace ya 
//{
//    TitleBackGround::TitleBackGround()
//    {
//
//    }
//    TitleBackGround::~TitleBackGround()
//    {
//    }
//    void TitleBackGround::Initialize()
//    {
//        mImage = Resources::Load<Image>(L"BG", L"..\\Resources\\Title\\TitleBG.bmp"); 
//
//        GameObject::Initialize();
//    }
//    void TitleBackGround::Update()
//    {
//        GameObject::Update();
//    }
//    void TitleBackGround::Render(HDC hdc)
//    {
//        Transform* tr = GetComponent<Transform>();
//        Vector2 pos = tr->GetPos();
//        BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
//
//        GameObject::Render(hdc);
//    }
//    void TitleBackGround::Release()
//    {
//        GameObject::Release();
//    }
//}