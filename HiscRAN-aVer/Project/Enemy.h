#pragma once
#include	"Mof.h"
#include	"Define.h"

#define		ENEMY_VOLUME	10

#define		ENEMY_SIZE_WIDTH	60
#define		ENEMY_SIZE_HEIGHT	60

//todo �G

class CEnemy
{
	//���[�V�����N���X
	CSpriteMotionController	m_Motion;

	//�`���`
	CRectangle				m_SrcRect;

	//�G���W
	float	ene_PosX;
	float	ene_PosY;

	bool	ene_Show;

	//�G�e�N�X�`��
	CTexture* ene_Texture;

	int		ene_Type;

	//�X�s�[�h
	float	ene_SpeedX;
	float	ene_SpeedY;

	//���[�V������ޒ�`
	enum tag_MOTION {
		MOTION_MOVE,

		MOTION_COUNT,
	};

public:
	CEnemy();
	~CEnemy();

	bool Load();
	void Initialize();
	void Start(float posy, int type);
	void Update(float over);
	void Render();
	void RenderDebug();
	void Release();

	//�G�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* enetex);

	//�G�̔���
	CRectangle GetRect(int type);
	//�X�e�[�W�̕\�����ł̖₢�Ŏg�p
	bool Getshow(void) { return ene_Show; }

	int GetType(void) { return ene_Type; }
};

