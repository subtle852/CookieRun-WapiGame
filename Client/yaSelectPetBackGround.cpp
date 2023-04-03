#include "yaSelectPetBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    SelectPetBackGround::SelectPetBackGround()
    {

    }

    SelectPetBackGround::~SelectPetBackGround()
    {

    }

    void SelectPetBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"SelectPetBG", L"..\\Resources\\SelectP\\selectpet_bg.bmp");

        GameObject::Initialize();
    }

    void SelectPetBackGround::Update()
    {
        GameObject::Update();
    }

    void SelectPetBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void SelectPetBackGround::Release()
    {
        GameObject::Release();
    }
}