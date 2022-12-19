#pragma once
#include "Define.h"


class CMusicMgmt
{
private:

	//SE�p�N���X
	CSoundBuffer m_Music_SE[SE_TYPE_COUNT];

	//BGM�p�N���X
	CSoundBuffer m_Music_BGM[BGM_TYPE_COUNT];

public:
	CMusicMgmt();
	~CMusicMgmt();

	//�f�ރ��[�h
	tag_LoadSituation Load(void);

	//������
	void Initialize(float bgmv, float sev);

	//��ʐ��ڎ��̏���������
	void InitializeIn_middle(float bgmv, float sev);


	//SE�Đ�
	CSoundBuffer* SEStart(tag_SE_TYPE type);
	//SE��~
	void SEStop(tag_SE_TYPE type);
	//SE�{�����[���Z�b�g
	void SESetVolume(float sev);
	//SE���Đ�����Ă��邩�擾
	//true :�Đ���
	bool SEisPlay(tag_SE_TYPE type);

	//BGM�Đ�
	CSoundBuffer* BGMStart(tag_BGM_TYPE type);
	//BGM��~
	void BGMStop(tag_BGM_TYPE type);
	//BGM�{�����[���Z�b�g
	void BGMSetVolume(float bgmv);

	//SE�����ׂĒ�~
	void SEALLStop(void);

	//���[�v�ݒ�
	void BGMLoop(tag_BGM_TYPE type,bool b);

	//SE�{�����[���Q�b�g
	float GetSEVolume();

	//BGM�{�����[���Q�b�g
	float GetBGMVolume();

	//���
	void Release(void);

};

