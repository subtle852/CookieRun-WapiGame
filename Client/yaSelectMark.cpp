#include "yaSelectMark.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    SelectMark::SelectMark()
    {

    }

    SelectMark::~SelectMark()
    {

    }

    void SelectMark::Initialize()
    {
        //mImage = Resources::Load<Image>(L"SelectMark", L"..\\Resources\\Play\\gaugebg_heart01.bmp");

        GameObject::Initialize();
    }

    void SelectMark::Update()
    {
        GameObject::Update();
    }

    void SelectMark::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 1.0, mImage->GetHeight() * 1.0
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void SelectMark::Release()
    {
        GameObject::Release();
    }
}