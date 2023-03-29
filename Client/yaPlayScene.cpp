#include "yaPlayScene.h"
#include "yaCharacter01.h"
#include "yaPet01.h"
#include "yaPlayBackGround.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaObstacle.h"
#include "yaObstacle01.h"
#include "yaCollisionManager.h"
#include "yaTransform.h"
#include "yaCamera.h"
#include "yaObject.h"
#include "yaTime.h"

#include "yaCoin_Silver.h"
#include "yaBlackOutMItem.h"
#include "yaShakeItem.h"
#include "yaSmItem.h"
#include "yaBigItem.h"
#include "yaFastItem.h"
#include "yaSlowItem.h"
#include "yaHpItemI.h"
#include "yaHpItemD.h"
#include "yaObstacleToCoin.h"
#include "yaBasicToBear.h"
#include "yaMagnetItem.h"
#include "yaInputEItem.h"
#include "yaInvincibleItem.h"

#include "yaJumpButton.h"
#include "yaSlideButton.h"
#include "yaPauseButton.h"
#include "yaGaugeCircle.h"
#include "yaGaugeBar.h"
#include "yaGround.h"
#include "yaUnderGround.h"
#include "yaOverGround.h"

#include "yaSelectCharScene.h"
#include "yaMakeScene.h"

namespace ya
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		//mCh00 =
		//object::Instantiate<Character01>(eLayerType::Player);
		//Camera::SetTarget(mCh01);

		Scene::Initialize();

		// 여기다
		//object::Instantiate<PlayBackGround>(eLayerType::BG);

		object::Instantiate<OverGround>(Vector2(-100.0f, 400.0f), eLayerType::Ground);
		//object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground);
		object::Instantiate<Ground>(Vector2(-100.0f, 700.0f), eLayerType::Ground, Vector2(10000.0f, 50.0f));
		object::Instantiate<UnderGround>(Vector2(-100.0f, 890.0f), eLayerType::Ground);

		int temp = SelectCharScene::GetCharNumber();
		if (int temp = SelectCharScene::GetCharNumber() == 1)
		{
			mCh01 = object::Instantiate<Character01>(Vector2(300.0f, 650.0f), eLayerType::Player);
		}

		mPet01 = object::Instantiate<Pet01>(eLayerType::Pet);

		object::Instantiate<Obstacle>(Vector2(700.0f, 700.0f), eLayerType::Obstacle);

		mOtC01 = object::Instantiate<ObstacleToCoin>(Vector2(1800.0f, 700.0f), eLayerType::Item);
		mOb01 = object::Instantiate<Obstacle01>(Vector2(2000.0f, 650.0f), eLayerType::Obstacle);

		object::Instantiate<Obstacle>(Vector2(2700.0f, 700.0f), eLayerType::Obstacle);
		object::Instantiate<Obstacle01>(Vector2(3300.0f, 650.0f), eLayerType::Obstacle);
		object::Instantiate<Obstacle>(Vector2(5600.0f, 700.0f), eLayerType::Obstacle);
		object::Instantiate<Coin_Silver>(Vector2(2100.0f, 700.0f), eLayerType::Item);

		object::Instantiate<BigItem>(Vector2(2800.0f, 700.0f), eLayerType::Item);
		object::Instantiate<ShakeItem>(Vector2(5000.0f, 700.0f), eLayerType::Item);
		object::Instantiate<FastItem>(Vector2(5400.0f, 700.0f), eLayerType::Item);//
		//object::Instantiate<BasicToBear>(Vector2(5900.0f, 700.0f), eLayerType::Item);
		object::Instantiate<BlackOutMItem>(Vector2(6000.0f, 700.0f), eLayerType::Item);//
		object::Instantiate<SlowItem>(Vector2(9300.0f, 700.0f), eLayerType::Item);//
		object::Instantiate<InputEItem>(Vector2(9500.0f, 700.0f), eLayerType::Item);
		object::Instantiate<InvincibleItem>(Vector2(10100.0f, 700.0f), eLayerType::Item);//
		object::Instantiate<HpItemI>(Vector2(11600.0f, 700.0f), eLayerType::Item);//
		object::Instantiate<HpItemD>(Vector2(13000.0f, 700.0f), eLayerType::Item);//
		object::Instantiate<SmItem>(Vector2(13200.0f, 700.0f), eLayerType::Item);//

		object::Instantiate<GaugeCircle>(Vector2(-10.0f, 20.0f), eLayerType::UIAbove);
		object::Instantiate<GaugeBar>(Vector2(59.0f, 32.0f), eLayerType::UI);

		object::Instantiate<JumpButton>(Vector2(100.0f, 650.0f), eLayerType::UI);
		object::Instantiate<SlideButton>(Vector2(1200.0f, 650.0f), eLayerType::UI);
		object::Instantiate<PauseButton>(Vector2(1480.0f, 40.0f), eLayerType::UI);

		/*{
			wchar_t temp[256] = L"..\\Resources\\asdd";
			FILE* file = nullptr;
			_wfopen_s(&file, temp, L"rb");

			if (file == nullptr)
				return;

			while (true)
			{
				int index = -1;
				TilePos id;

				if (fread(&index, sizeof(int), 1, file) == NULL)
					break;

				if (fread(&id.id, sizeof(TilePos), 1, file) == NULL)
					break;


				if (index == 0)
				{
					object::Instantiate<Obstacle>(Vector2(id.x, id.y), eLayerType::Obstacle);
				}
				if (index == 1)
				{
					object::Instantiate<Obstacle01>(Vector2(id.x, id.y), eLayerType::Obstacle);
				}
	
		}*/

		//CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		//CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
	}

	void PlayScene::Update()
	{
		Transform* tr = mCh01->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		Transform* trr = mPet01->GetComponent<Transform>();
		trr->SetPos(Vector2(pos.x - 120.0f, pos.y - 0.0f));

		if (mOtC01->mOn == true)// mOtC01 충돌
		{
			Transform* tr = mOb01->GetComponent<Transform>();// mOb01 위치 저장
			Vector2 pos = tr->GetPos();
			//object::Instantiate<JellyCoin>(Vector2(pos.x, 700.0f), eLayerType::Item);// mOb01위치에 JellyCoin 생성// 오류발생
			
			ya::object::Destory(mOb01);

			mOtC01->mOn = false;

			ya::object::Destory(mOtC01);
		}

		//Camera::mType = Camera::eCameraEffectType::ShakeH;// 설정
		//Camera::mCutton = Image::Create(L"Cutton00", Camera::mResolution.x, Camera::mResolution.y, RGB(0, 0, 0)/*원하는 색*/);

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			//SceneManager::LoadScene(eSceneType::ResultS);
			SceneManager::LoadScene(eSceneType::Make);
		}

		Scene::Update();

	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		Scene::SceneText(hdc);

		Scene::PosText(hdc);
	}

	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
		Camera::SetTarget(mCh01);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Obstacle, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
	}

	void PlayScene::OnExit()
	{
		Camera::Clear();
		//ya::object::Destory(mBG);
		//ya::object::Destory(mCh01);
		//ya::object::Destory(mPet01);
		//ya::object::Destory(mOb01);
		//ya::object::Destory(mOb02);
		//ya::object::Destory(mOb03);
		//ya::object::Destory(mOb04);
		//ya::object::Destory(mJcoin01);
		//ya::object::Destory(mJcoin02);
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f }); 씬넘길때 원상복귀 시키는것
	}
}