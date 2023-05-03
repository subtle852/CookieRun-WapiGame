#include "yaPlay_Silver.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    Play_Silver::Play_Silver()
    {

    }

    Play_Silver::~Play_Silver()
    {

    }

    void Play_Silver::Initialize()
    {
        mImage = Resources::Load<Image>(L"PlaySilver", L"..\\Resources\\Play\\play_silver.bmp");

        GameObject::Initialize();
    }

    void Play_Silver::Update()
    {
        GameObject::Update();
    }

    void Play_Silver::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 0.7, mImage->GetHeight() * 0.7
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void Play_Silver::Release()
    {
        GameObject::Release();
    }
}