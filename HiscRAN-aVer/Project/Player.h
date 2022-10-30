#pragma once
#include	"Mof.h"

//�d��
#define  GRAVITY	0.5f

//��W�����v�l
#define  BIGJUMP -16.0f
//���W�����v�l
#define  SMALLJUMP	-15.0f

//�ő�X���C�f�B���O�l
#define  SLIDING	100
//�X���C�f�B���O�N�[���^�C��
#define  SLIDINGCOOL 60


class CPlayer
{
private:

	//���[�V�����N���X
	CSpriteMotionController	m_Motion;

	//�`���`
	CRectangle				m_SrcRect;

	//�L�����N�^�[�e�N�X�`��
	CTexture				m_Texture;

	//���L����
	CTexture m_TEX;

	//�v���C���[���W
	float					m_PosX;
	float					m_PosY;
	//�X�s�[�h�ϐ�
	float					m_MoveX;
	float					m_MoveY;

	//�����蔻�蕝
	float m_hitboxX;
	float m_hitboxY;

	//�����蔻��(��)
	float m_legsboxY;

	//�����蔻��(�X�L��)
	float m_SkillA;
	float m_SkillB;


	//����I�[�o�[�l
	float	m_OverX;
	float	m_OverY;

	//X�Œ�ʒu
	float m_StopX;

	//HP
	int				m_HP;

	//���G����
	int					m_DamageWait;

	//�Ռ��g����
	int m_CircleWait;

	//�Q�[���J�n�t���O
	bool					m_Startflg;
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


	//�I�[�o�[�l�擾
	float GetOver(void) { return m_OverX; }

	//�v���C���[��`�擾
	CRectangle GetRect(void) {
		return CRectangle(m_PosX, m_PosY,
			m_PosX + m_hitboxX, m_PosY + m_hitboxY);
	}

	//�v���C���[����������
	CRectangle legsGetRect() {
		return CRectangle(m_PosX, m_PosY + m_legsboxY,
			m_PosX + m_hitboxX, m_PosY + m_hitboxY);
	}

	//�v���C���[�z���񂹔͈�
	CRectangle SuckingRect() {
		return CRectangle(m_PosX, m_PosY - 200,
			m_PosX + m_hitboxX + 100, m_PosY + m_hitboxY + 600);
	}
	//�Ռ��g�����蔻��
	CRectangle m_CircleRect() {
		return CRectangle(m_PosX - m_SkillA, m_PosY - m_SkillA,
			m_PosX + m_SkillB, m_PosY + m_SkillA);
	}


	//�Q�[����~�F�Đ��؂�ւ�
	void GameStopPlayChange();

	//�L�����������Ă��邩�擾
	bool GetGameStopPlay();

	//���W�擾
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }


};
