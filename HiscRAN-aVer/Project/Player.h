#pragma once
#include	"Mof.h"

//�d��
#define  GRAVITY	0.3f

//��W�����v�l
#define  BIGJUMP	-13.0f
//���W�����v�l
#define  SMALLJUMP	-6.0f

class CPlayer
{
private:

	//���[�V�����N���X
	CSpriteMotionController	m_Motion;

	//�`���`
	CRectangle				m_SrcRect;

	//�L�����N�^�[�e�N�X�`��
	CTexture				m_Texture;

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

	//����I�[�o�[�l
	float	m_OverX;
	float	m_OverY;

	//X�Œ�ʒu
	float m_StopX;

	//HP
	int				m_HP;
	//���G����
	int					m_DamageWait;

	//�Q�[���J�n�t���O
	bool					m_Startflg;
	//���S�t���O
	bool				m_deathflg;
	//�W�����v�p���[
	float				m_JumpPower;
	//�W�����v�t���O
	bool				m_Jumpflg;
	//�召�W�����v�J�E���g
	float				m_JumpCount;


	//���[�V������ޒ�`
	enum tag_MOTION {
		MOTION_WAIT,
		MOTION_MOVE,
		MOTION_JUMPSTART,
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
	void DebuggingRender(void);

	//���ꓖ���蔻��
	bool CollosopnBar(CRectangle r);
	void UPdateCollisionBra(float y);

	//�n�ʂ̓����蔻��
	bool CollosopnGround(float y);
	void UPdateCollisionGround(float y);

	//��Q�������蔻��
	bool CollosopnOB(CRectangle r);
	//��Q���E�G�Ɠ��������ꍇ
	void UPdateCollisionOB(void);


	//�G�����蔻��:���g�p
	bool CollosopnEnemy(CRectangle r);

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

	//�Q�[����~�F�Đ��؂�ւ�
	void GameStopPlayChange();

	//�L�����������Ă��邩�擾
	bool GetGameStopPlay();

	//���W�擾
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }


};
