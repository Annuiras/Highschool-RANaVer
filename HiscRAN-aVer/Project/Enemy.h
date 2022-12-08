#pragma once
#include	"Define.h"

//�G�N���X
class CEnemy
{
	//���[�V�����N���X
	CSpriteMotionController* m_Motion;

	//�`���`
	CRectangle				m_SrcRect;

	//�G���W
	float	m_PosX;
	float	m_PosY;

	//�\���t���O
	//ture:�\����
	bool	m_Show;

	//�G�e�N�X�`��
	CTexture* m_Texture;

	//�X�s�[�h
	float	m_MoveY;

	//���[�V������ޒ�`
	enum tag_MOTION {
		MOTION_MOVE,

		MOTION_COUNT,
	};

public:
	CEnemy();
	~CEnemy();

	//������
	void Initialize();

	//����
	void Start(float posy, int type);

	//�X�V
	void Update(float scroll);

	//�`��
	void Render();
	void RenderDebug();

	//���
	void Release();

	//�G�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* enetex);

	//�G�A�j���[�V�������Z�b�g
	void SetAnime(CSpriteMotionController* eneanim);

	//�G�̔���
	CRectangle GetRect(void);

	//�\�����t���O��n��
	bool Getshow(void) { return m_Show; }

	//Y���W����
	//y:���킹���������W
	void SetPosY(float y);
};

