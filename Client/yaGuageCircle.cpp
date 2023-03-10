#include "yaGuageCircle.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    GuageCircle::GuageCircle()
    {

    }

    GuageCircle::~GuageCircle()
    {

    }

    void GuageCircle::Initialize()
    {
        mImage = Resources::Load<Image>(L"GuageCircle", L"..\\Resources\\Play\\gaugebg_heart01.bmp");

        GameObject::Initialize();
    }

    void GuageCircle::Update()
    {
        GameObject::Update();
    }

    void GuageCircle::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.3, mImage->GetHeight() * 1.3
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void GuageCircle::Release()
    {
        GameObject::Release();
    }
}