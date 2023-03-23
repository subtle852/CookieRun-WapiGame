#pragma once

enum class eSceneType
{
	Title,
	Main,
	SelectChar,
	//PetSelect,
	SelectStage,
	Play, //Stage00,
	ResultS,
	ResultF,
	Tool,
	Make,
	Max,
};

enum class eLayerType // layer �׸��� ����
{
	BG,
	Tile,
	Obstacle,
	Item,
	Player,
	Pet,
	Ground,
	Effect,
	UI,
	UIAbove,
	End = 16,
};

enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Rigidbody,
	Audio,
	End,
};