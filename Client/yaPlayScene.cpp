#include "yaPlayScene.h"
#include "yaCharacter00.h"
#include "yaInput.h"
#include "yaSceneManager.h"

ya::PlayScene::PlayScene()
{
}

ya::PlayScene::~PlayScene()
{
}

void ya::PlayScene::Initialize()
{
	mCharacter00 = new Character00();
	mCharacter00->SetName(L"Player");
	AddGameObject(mCharacter00, eLayerType::Player);

	Scene::Initialize();
}

void ya::PlayScene::Update()
{
	if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
	{
		SceneManager::LoadScene(eSceneType::Title);
	}

	Scene::Update();
}

void ya::PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}

void ya::PlayScene::Release()
{
	Scene::Release();
}

void ya::PlayScene::OnEnter()
{
}

void ya::PlayScene::OnExit()
{
	// OnExit�� �� �̵��̶���� �������� ��ҵ��� �ʱ�ȭ ��Ű���� ���⼭ �̷��� ����� �ϰ� 
	// �׷��� �ʴٸ� Initialize�� �� ��ü���� ����� �����
	// mCuphead->SetPos(Vector2{ 0.0f, 0.0f });
}