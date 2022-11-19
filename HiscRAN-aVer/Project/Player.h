#pragma once
#include	"Mof.h"
#include "MusicManager.h"
#include "Define.h"


class CPlayer
{
private:

	//���[�V�����N���X
	CSpriteMotionController	m_Motion;

	CMusicManager* m_MusicManager;

	//�`���`
	CRectangle				m_SrcRect;

	//�L�����N�^�[�e�N�X�`��
	CTexture				m_Texture;

	//�v���C���[���W
	float					m_PosX;
	float					m_PosY;

	//�X�s�[�h�ϐ�
	float					m_MoveY;


	//�����蔻��(��)
	float m_legsboxY;

	//�����蔻��(�X�L��)
	float m_SkillA;
	float m_SkillB;

	//HP
	int				m_HP;

	//���G����
	int					m_DamageWait;

	//�Ռ��g����
	int m_CircleWait;

	//���S�t���O
	bool				m_deathflg;

	//�W�����v�t���O     ��ɉ��Z����Ă���Ԃ̃t���O
	bool					m_Jumpflg;

	//�召�W�����v�t���O ��W�����v:true
	bool					m_BSflg;
	//�召�W�����v�J�E���g
	float					m_JumpCount;

	//�X���C�f�B���O�t���O
	float					m_Slidingflg;


	//���[�V������ޒ�`
	enum tag_MOTION {
		MOTION_WAIT,
		MOTION_MOVE,
		MOTION_JUMPSTART,
		MOTION_SLIDING,
		MOTION_JUMPEND,
		MOTION_DAMAGE,

		MOTION_COUNT,
	};

public:
	CPlayer();
	~CPlayer();

	bool Load(void);
	void Initialize(void);

	void Update(void);
	void Render(void);
	void Release(void);

	//�킩��Ȃ����ꉽ?
	void UpdateSkillShock(void);

	//�f�o�b�O�\��
	void RenderDebugging(void);

	//���ꓖ���蔻��
	bool CollosopnBar(CRectangle r);
	void UPdateCollisionBra(float y);

	//�n�ʂ̓����蔻��
	bool CollosopnGround(CRectangle r);
	void UPdateCollisionGround(float y);

	//��Q�������蔻��
	bool CollosopnOB(CRectangle r);
	//��Q���E�G�Ɠ��������ꍇ
	void UPdateCollisionOB(void);

	//�X���C�f�B���O����
	void UPdateSliding(void);

	//�G�����蔻��:���g�p
	bool CollosopnEnemy(CRectangle r);
	
	//HP��������
	void UpdateHP(void);

	void SetMusicManager(CMusicManager* pmng) { m_MusicManager = pmng; }

	//�v���C���[��`�擾
	CRectangle GetRect(void) {
		return CRectangle(m_PosX + PLAYER_ADMENT_SPACE, m_PosY,
			m_PosX + PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//�v���C���[����������
	CRectangle legsGetRect() {
		return CRectangle(m_PosX+ PLAYER_ADMENT_SPACE,m_PosY + m_legsboxY,
			m_PosX + PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//�v���C���[�z���񂹔͈�
	CRectangle SuckingRect() {
		return CRectangle(m_PosX + PLAYER_ADMENT_SPACE, m_PosY - 200,
			m_PosX + PLAYER_HIT_X + 100, m_PosY + PLAYER_HIT_Y + 600);
	}
	//�Ռ��g�����蔻��
	CRectangle m_CircleRect() {
		return CRectangle(m_PosX - m_SkillA + PLAYER_ADMENT_SPACE, m_PosY - m_SkillA,
			m_PosX + m_SkillB, m_PosY + m_SkillA);
	}

	//���W�擾
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }


};
