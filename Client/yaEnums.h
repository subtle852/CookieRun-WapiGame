#pragma once

enum class eSceneType
{
	Title,
	Main,
	SelectChar,
	//PetSelect,
	SelectStage,
	Play, //Stage00,
	Result,
	Max,
};

enum class eLayerType // layer �׸��� ����
{
	BG,
	Opponent,
	Player,
	Effect,
	UI,
	End,
};

enum class eComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animator,
	Audio,
	End,
};