#pragma once
#include "MusicManager.h"
#include "EffectManager.h"
#include "Define.h"


class CPlayer
{
private:

	//���[�V�����N���X
	CSpriteMotionController	m_Motion;

	//SE�EBGM�}�l�[�W���[
	CMusicMgmt* m_MusicMgmt;

	//�G�t�F�N�g�}�l�[�W���[
	CEffectMgmt* m_pEffectMgmt;

	//�`���`
	CRectangle				m_SrcRect;

	//�L�����N�^�[�e�N�X�`��
	CTexture				m_Texture;

	//HP�\���e�N�X�`��
	CTexture				m_HPTexture;
	CTexture				m_HPFrame;

	//�v���C���[���W
	float					m_PosX;
	float					m_PosY;

	//�X�s�[�h�ϐ�
	float					m_MoveY;

	//�����蔻��(��)
	float m_legsboxY;

	//HP
	int				m_HP;

	//���G����
	int					m_DamageWait;

	//���S�t���O
	bool				m_deathflg;

	//�W�����v�t���O     ��ɉ��Z����Ă���Ԃ̃t���O
	bool					m_Jumpflg;

	//�召�W�����v�t���O ��W�����v:true
	bool					m_BSflg;
	//�召�W�����v�J�E���g
	float					m_JumpCount;

	//�f�o�b�O�p
	//���G�t���O
	bool _unrivaled;
	int _chare_A;

	//���[�V������ޒ�`
	enum tag_MOTION {
		MOTION_MOVE,		//�ړ�
		MOTION_JUMPSTART,	//�W�����v�J�n
		MOTION_COUNT,		//����
	};

public:
	CPlayer();
	~CPlayer();

	//�f�ރ��[�h
	bool Load(void);

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�N���A���̍X�V
	void UpdateClear(void);

	//�`��
	void Render(void);

	//���
	void Release(void);

	//�f�o�b�O�\��
	void RenderDebugging(void);

	//���镨(�㏸�����蔲��)�Ɠ��������ꍇ
	void UPdateCollisionBra(float y);

	//�n�ʂƓ��������ꍇ
	void UPdateCollisionGround(float y);

	//��Q���E�G�Ɠ��������ꍇ
	void UPdateCollisionOB(void);

	//SE�EBGM�}�l�[�W���[�Z�b�g
	void SetMusicManager(CMusicMgmt* mgmt) { m_MusicMgmt = mgmt; }

	//�G�t�F�N�g�}�l�[�W���[�Z�b�g
	void SetEffectManager(CEffectMgmt* mgmt) { m_pEffectMgmt = mgmt; }


	//�v���C���[��`�擾
	CRectangle GetRect(void) {
		return CRectangle(m_PosX + PLAYER_ADMENT_SPACE, m_PosY,
			m_PosX + PLAYER_ADMENT_SPACE+ PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//�v���C���[����������
	CRectangle GetLegsRect() {
		return CRectangle(m_PosX+ PLAYER_ADMENT_SPACE,m_PosY + m_legsboxY,
			m_PosX+ PLAYER_ADMENT_SPACE + PLAYER_HIT_X, m_PosY + PLAYER_HIT_Y);
	}

	//���W�擾
	float CircleX() { return m_PosX; }
	float CircleY() { return m_PosY; }

	//�Q�[���I�[�o�[�����n��
	//true: �Q�[���I�[�o�[
	bool	GetOver(void) { return m_deathflg; }

};
