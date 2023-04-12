#pragma once

enum class eSceneType
{
	Title,
	Main,
	Lottery,
	Store,
	Slot,
	Racing,
	Baccarat,
	SelectChar,
	SelectPet,
	SelectStage,
	Play, //Stage00,
	ResultS,
	ResultF,
	Tool,
	Make,
	Max,
};

enum class eLayerType // layer 그리는 순서
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

union TilePos
{
	struct
	{
		UINT32 x;
		UINT32 y;
	};
	UINT64 id;
};

union TileInd
{
	struct
	{
		UINT32 ind;
		UINT32 width;
	};
	UINT64 id2;
};