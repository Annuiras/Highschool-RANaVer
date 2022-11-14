#pragma once
#include "Mof.h"
#include "Define.h"

class CObstacle
{

private:

	//���e�N�X�`��
	CTexture*	ob_Textuer;

	//���W
	float ob_PosX;
	float ob_PosY;

	//�\���t���O:true�F�\��
	bool ob_Show;

	//��Q���^�C�v�ʉ���
	float ob_HitWidth;

	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);


	void Update(float over);
	void Start(float posy,int type);

	//OB�e�N�X�`�����Z�b�g
	void SetTexture(CTexture* obtex);

	void Render(void);
	void RenderDebugging(void);


	//�_���[�W��`�擾
	CRectangle GetRect(int type);

	//��Q����ɏ��铖���蔻��擾
	CRectangle GetTopBarRect(int type);


	//�\�����t���O�擾
	bool Getshow(void) { return ob_Show; }

	//��Q���^�C�v�擾
	bool GetType(void) { return ob_Type; }

	//Y���W�擾
	float GetY(int type) { return GetTopBarRect(type).Top; }

	//�\���t���O�Z�b�g
	void Setshow(bool b) { ob_Show = b; }

};

