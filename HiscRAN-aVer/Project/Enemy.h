#pragma once
#include	"Define.h"

class CEnemy
{
	//���[�V�����N���X
	CSpriteMotionController* m_Motion;

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

	void Initialize();
	void Start(float posy, int type);
	void Update(float over);
	void Render();
	void RenderDebug();
	void Release();

	//�G�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* enetex);

	//�G�A�j���[�V�������Z�b�g
	void SetAnime(CSpriteMotionController* eneanim);

	//�G�̔���
	CRectangle GetRect(void);
	//�X�e�[�W�̕\�����ł̖₢�Ŏg�p
	bool Getshow(void) { return ene_Show; }

	//Y���W����
	//y:���킹���������W
	void SetPosY(float y);

	int GetType(void) { return ene_Type; }
};

