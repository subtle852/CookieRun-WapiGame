#include "yaPlay_Score.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaTransform.h"

namespace ya
{
    Play_Score::Play_Score()
    {

    }

    Play_Score::~Play_Score()
    {

    }

    void Play_Score::Initialize()
    {
        mImage = Resources::Load<Image>(L"PlayScore", L"..\\Resources\\Play\\play_score.bmp");

        GameObject::Initialize();
    }

    void Play_Score::Update()
    {
        GameObject::Update();
    }

    void Play_Score::Render(HDC hdc)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = tr->GetPos();
        //BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
        TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * 0.7, mImage->GetHeight() * 0.7
            , mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(170, 0, 0));

        GameObject::Render(hdc);
    }

    void Play_Score::Release()
    {
        GameObject::Release();
    }
}