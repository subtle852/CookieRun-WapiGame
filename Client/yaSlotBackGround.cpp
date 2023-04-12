#include "yaSlotBackGround.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    SlotBackGround::SlotBackGround()
    {

    }

    SlotBackGround::~SlotBackGround()
    {

    }

    void SlotBackGround::Initialize()
    {
        mImage = Resources::Load<Image>(L"SlotBG", L"..\\Resources\\Slot\\slot_bg.bmp");

        GameObject::Initialize();
    }

    void SlotBackGround::Update()
    {
        GameObject::Update();
    }

    void SlotBackGround::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();

        TransparentBlt(hdc, pos.x, pos.y, 1600, 900
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void SlotBackGround::Release()
    {
        GameObject::Release();
    }
}