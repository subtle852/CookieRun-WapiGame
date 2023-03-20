#include "yaGaugeCircle.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    GaugeCircle::GaugeCircle()
    {

    }

    GaugeCircle::~GaugeCircle()
    {

    }

    void GaugeCircle::Initialize()
    {
        mImage = Resources::Load<Image>(L"GaugeCircle", L"..\\Resources\\Play\\gaugebg_heart01.bmp");

        GameObject::Initialize();
    }

    void GaugeCircle::Update()
    {
        GameObject::Update();
    }

    void GaugeCircle::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.3, mImage->GetHeight() * 1.3
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void GaugeCircle::Release()
    {
        GameObject::Release();
    }
}