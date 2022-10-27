#pragma once
#include "Mof.h"
#define OB_VOLUME 5


class CObstacle
{

private:

	float ob_PosX;
	float ob_PosY;

	//�\���t���O:true�F�\��
	bool ob_Show;

	//�����蔻��
	float ob_hitboxX;
	float ob_hitboxY;

	//todo:��Q����ށi���j
	//1:�֎q
	//2:������
	//3:�{�[��
	int ob_Type;

public:

	CObstacle();
	~CObstacle();

	void Initialize(void);
	void Update(float over);
	void Start(float posy,int type);

	void Render(void);
	void DebuggingRender(void);



	CRectangle GetRect(int type);

	bool Getshow(void) { return ob_Show; }

	bool GetType(void) { return ob_Type; }

	void Setshow(bool b) { ob_Show = b; }

};

